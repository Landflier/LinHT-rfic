# Integer-N Clock-Multiplier PLL

> [!NOTE]
> This proposal was drafted with AI assistance (Claude by Anthropic, used
> through Claude Code). The architecture, specifications, and final decisions
> are reviewed and owned by Vasil Yordanov.

## IP block type

General-purpose integer-N charge-pump PLL for SoC clock generation, with a ring
VCO and fully integrated loop filter — no inductors, no off-chip components.
SG13CMOS5L has no characterized integrated inductors on its reduced metal
stack, so an LC oscillator would rest on an unvalidated custom device; a
ring-based PLL is verifiable end-to-end with open tools and portable across
IHP stack variants.

## Functional description

The PLL multiplies a 5–50 MHz reference into a 7.8125 MHz – 1 GHz output clock.
Signal path: phase-frequency detector, charge pump, integrated third-order
passive loop filter, pseudo-differential ring VCO (core range 250 MHz – 1 GHz),
programmable feedback divider (N = 5–200), output post-divider
(÷1/2/4/8/16/32), and a lock detector. The VCO and charge pump run from a
local regulator off the 3.3 V analog rail, referenced to the shared bandgap,
for supply-noise rejection; dividers and logic use the 1.2 V digital rail.
Bias derives from one bandgap-referenced current source. Configuration (N,
post-divider, test modes) loads through a 3-wire shift interface. An open-loop
test mode disconnects the charge pump so the VCO control voltage can be
forced/monitored through a shared analog pin; a ÷16 VCO tap allows external
frequency counting.

## I/O

| Pin | Type | Function |
|---|---|---|
| ref_in | digital in | reference clock, 5–50 MHz |
| clk_out | digital out | synthesized clock (post-divider output) |
| en | digital in | enable / power-down |
| lock | digital out | lock-detector flag |
| cfg_clk, cfg_data, cfg_load | digital in | configuration shift register |
| test_out | digital out | VCO ÷16 tap for frequency counting |
| vctrl | analog (shared) | force/monitor VCO control voltage; low current, no special pad resistance requirement |
| ibias | analog in | bandgap-referenced bias current |
| vbg | analog in | 1.2 V bandgap reference for VCO regulator |
| VDD1V2 / VDD3V3A / VSS | supply | digital / analog / ground |

## Target specification

| Parameter | Min | Typ | Max | Absolute limit |
|---|---|---|---|---|
| Output frequency | 7.8125 MHz | — | 1 GHz | VCO covers 250 MHz–1 GHz at all corners, −40…125 °C; floor = 250 MHz ÷ 32 (best jitter: run the VCO high, divide more) |
| Multiplication factor N | 5 | — | 200 | N = 200 reaches 1 GHz from a 5 MHz reference; charge-pump current programmed ∝ N to hold loop bandwidth |
| Integrated jitter, 1 kHz–100 MHz, at 1 GHz | — | 15 ps RMS | — | 30 ps RMS |
| Reference spurs | — | −55 dBc | — | −45 dBc |
| Lock time | — | 50 µs | — | 100 µs |
| Supply sensitivity | — | 1 %/V | — | — |
| Power at 1 GHz | — | 5 mW | — | 10 mW |
| Power-down current | — | 10 µA | — | — |
| Area | — | ≤ 0.2 mm² | — | fits assigned slot |

## Test plan outline

1. **Static:** supply currents, enabled and powered down.
2. **Open-loop VCO:** force vctrl, count test_out — tuning curve, range, and
   K_VCO versus supply and temperature.
3. **Closed-loop:** sweep N and reference frequency; verify output frequency,
   lock flag, and lock time (en toggle and N step, oscilloscope capture).
4. **Jitter/noise:** phase-noise measurement on clk_out; integrate 1 kHz–100 MHz;
   reference spurs on a spectrum analyzer.
5. **Sensitivity:** ±10 % on each rail — frequency pushing and jitter change.

## Relation to the LinHT_IC fractional-N synthesizer

This block is deliberately the integer-N core of the fractional-N synthesizer
planned for the LinHT_IC transceiver (`pll_top`, SG13G2). The type-II
charge-pump loop — PFD, charge pump, integrated third-order passive loop
filter, programmable divider, lock detector — is common to both designs, and
is what this tapeout verifies in silicon: charge-pump nonidealities,
loop-filter area, lock behavior, supply sensitivity. Fractional operation is
omitted here because clock multiplication needs only the N·f_ref/P grid, and
SG13CMOS5L has no characterized inductor for an LC oscillator. The evolution
path: replace the ring VCO with a 2.08–4.16 GHz LC VCO with switched-cap band
select; replace the fixed-modulus divider with a ÷65–130 multi-modulus divider
dithered by a MASH 1-1-1 ΣΔ modulator (in the companion digital core); add
charge-pump linearization so folded quantization noise stays below the
−60 dBc fractional-spur target; retune the loop to a 75–300 kHz bandwidth
from a 32 MHz reference.
