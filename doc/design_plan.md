# LinHT_IC — Open-Source VHF/UHF IQ Transceiver: Design Plan

**Status:** v0.2 draft (2026-07-13) — for review. Open decisions are collected in [§15](#15-open-decisions-input-needed).
**Staffing model:** one graduate student, 10–15 h/week, learning the concepts while designing — see §12 for what this implies.
**Scope:** Complete plan to specify, design, verify, and tape out a simple zero-IF IQ transceiver IC with continuous 2 m ↔ 70 cm coverage in IHP SG13G2, using the OSICD open-source flow this repository is built on.

Related documents:
- Template chip docs (to be replaced as the design matures): [specifications.md](specifications.md), [pinout.md](pinout.md), [floorplan.md](floorplan.md)
- Reference literature: `literature/ebouchaud_2021_ds_sx1255_v31book/` (SX1255 datasheet), Razavi *RF Microelectronics* / *CMOS PLLs*, Kundert *Designer's Guide*, *SDR for Engineers*
- OSICD flow: FSiC2026 "From Idea to Tapeout" (Dorrer/Pretl, JKU) — this repo **is** that template

---

## 0. Plan at a glance

| Topic | Summary |
| --- | --- |
| **What** | Zero-IF "RF-to-bits" IQ transceiver for LinHT — no modem, no MCU, no LoRa, no LVDS |
| **Coverage** | 130–520 MHz continuous (2 m → 70 cm), half-duplex TDD, single antenna port pair |
| **Baseband / converters** | ±250 kHz full performance (±500 kHz reduced-ENOB); RX = 3rd-order 1-bit CT ΣΔ ADC @ 32 MHz; TX = FIR-DAC fed by on-chip digital ΣΔ |
| **Synthesizer** | Single fractional-N PLL, octave LC VCO 2.08–4.16 GHz, ÷8/÷16 + final ÷2 quadrature (25 % duty); 30.5 Hz step (F_XOSC/2^20, SX1255 semantics) |
| **Interfaces** | SPI mode 0 (~32 registers, full readback, burst) + simple I2S master, 16-bit I/Q, 125 k–1 MS/s |
| **Impairment strategy** | RF + digital loopbacks, TX DC trim DACs, digital IQ correction, RC & VCO-band calibration, digital low-IF operation against DC/1/f |
| **Technology / package** | IHP SG13G2 130 nm BiCMOS Open-PDK; 2.0 × 2.0 mm die target; QFN-32; external 1.5 V + 3.3 V rails (LDOs in rev B) |
| **Flow** | This repo's OSICD template: Xschem + ngspice/VACASK/Xyce + CACE (PVT/MC) per macro; KLayout/Magic/netgen/kpex verification; LibreLane digital-on-top assembly; analog-on-top full-chip LVS/sim, `make all` sign-off |
| **Team & pace** | 1 graduate student, 10–15 h/week, learning in the loop (≈ 500–750 h/year) |
| **Strategy** | Two staged tapeouts: **α test chip** (synthesizer + digital core) at month ~12, **β full transceiver** at month ~24 |
| **Top risks** | Octave VCO tuning range, CT ΣΔ stability vs RC spread, multi-domain padframe/PDN gap in template, fractional spurs, single-designer schedule |

---

## 1. Mission and context

Design an open-source **"RF-to-bits" IQ transceiver** for the LinHT handheld: the radio equivalent of the SX1255, but with **continuous frequency coverage from the 2 m band through the 70 cm band**, a **simple I2S digital IQ interface** to the host SoM, and an **SPI control/readback register bank**. All modulation/demodulation (M17, FM, digital voice, etc.) runs on the host — the chip contains **no modem, no MCU, no LoRa, no LVDS**.

Guiding principles (inherited from SX1255 and TinyWhisper):

1. **The chip is deliberately dumb.** Analog selectivity is coarse; channel filtering, AGC decisions, and impairment correction live in host software. This minimizes analog risk on first silicon.
2. **One clock rules everything.** A single TCXO/XTAL reference drives the PLL, the ΣΔ data converters, the digital core, and the I2S bit clock.
3. **Calibration = observability, not on-chip smarts.** Provide loopback paths and trim DACs; let the host measure and correct.
4. **Every block is a self-contained macro** in the OSICD template structure, individually simulated (PVT + MC via CACE) and DRC/LVS/PEX-clean before assembly. Digital-on-top assembly (LibreLane), analog-on-top full-chip LVS/simulation without black boxes.

---

## 2. Reference designs and what we take from each

| Source | What we adopt | What we change |
| --- | --- | --- |
| **SX1255** (Semtech, 400–510 MHz) | Zero-IF architecture; 1-bit CT ΣΔ ADCs clocked at F_XOSC; semi-digital **FIR-DAC** TX; coarse analog filtering + digital selectivity; frac-N ΣΔ PLL with F_STEP = F_XOSC/2^20 and 24-bit FRF word latched on LSB write; tiny (~20 reg) SPI control surface, mode bits instead of state machine; digital-bridge/I2S "Mode B"; RF + digital loopbacks; TCXO injection on one crystal pin; per-domain supply pins | Frequency plan (need 1.7 octaves, not 27 %); **single shared synthesizer** (half-duplex) instead of two PLLs; broadband TX mixer load instead of programmable LC tank; drop 1-bit "Mode A" pins as primary interface (keep as internal test tap); external supply rails instead of on-chip LDOs (first tapeout); add RC filter calibration and RX DC-offset handling that SX1255 lacks |
| **AD936x** (ADI) | Concept validation only: wide continuous coverage via one octave VCO + binary divider chain; digital gain/offset correction philosophy | Everything else — far too complex to clone |
| **TinyWhisper** (JKU, SG13G2, tapeout-proven) | The exact flow (this template); inverter/TG-based analog style where possible; passive voltage-mode TG mixers with 25 % duty LO; 3rd-order MFB active filters with inverter-based OTAs; XSPICE mixed-signal top-level sim; QFN packaging + KLayout bonding diagram; multi-domain caveats and SG13G2 I/O cell issues (IHP-Open-PDK #962) | We add: LC VCO + frac-N PLL (TinyWhisper had none), RX chain, ΣΔ ADCs |
| **SX1255 datasheet errata** (do **not** copy) | — | Use 2^20 (not 2^19) in F_STEP; TX filter table is SSB 209–858 kHz (spec table confuses SSB/DSB); VCO wording "2× RF" vs "1.9 GHz" is inconsistent (it is ≈4× RF); pin 12/13 I/Q labels swapped in pinout prose |

---

## 3. Target specifications

Primary use case: LinHT handheld, M17 (4FSK, 9 kHz occupied BW), analog FM 12.5/25 kHz channels, and experimental wideband modes up to ~500 kHz, half-duplex.

| Parameter | Target (typ) | Notes |
| --- | --- | --- |
| Technology | IHP SG13G2, 130 nm SiGe BiCMOS Open-PDK | LV MOS (1.5 V) core, HV MOS (3.3 V) I/O, SiGe HBTs available for LNA/VCO if beneficial |
| RF tuning range | **130 – 520 MHz continuous** | Covers 2 m (144–148), 1.25 m (219–225), 70 cm (420–450) + margin; single antenna port pair |
| Duplex | Half-duplex (TDD), TX/RX turnaround < 150 µs | Single synthesizer; separate FRF_RX/FRF_TX words latched on mode entry |
| Architecture | Zero-IF IQ, direct conversion both directions | Narrowband channels operated at **digital low-IF** (LO offset ~100–200 kHz, final mix in host) to escape DC/1/f — see §4.6 |
| Baseband bandwidth | ≥ ±250 kHz (500 kHz DSB) full performance; up to ±500 kHz reduced-ENOB mode | "≈500 kHz BW for the D/A" requirement |
| RX noise figure | ≤ 5 dB @ max gain (≤ 8 dB worst corner) | SX1255: 4.5 dB typ |
| RX gain range | ≥ 70 dB, ≤ 2 dB steps, SPI-set (host AGC) | LNA coarse (6 steps, 0/−6/−12/−24/−36/−48 dB) + PGA −24…+6 dB in 2 dB steps |
| RX IIP3 | ≥ −20 dBm @ max gain, ≥ +10 dBm @ min gain | SX1255-class |
| RX ADC | 1-bit CT ΣΔ per rail @ F_XOSC; ≥ 12 bit ENOB in ±250 kHz after decimation (≥ 9–10 bit in ±500 kHz) | 3rd-order loop (vs SX1255's 5th) at 2× the OSR; see §6.8 |
| MDS (12.5 kHz channel, 10 dB SNR) | ≈ −118 dBm | −174 + 41 dB(12.5 kHz) + NF 5 + 10 |
| TX output power | 0 dBm avg linear, +5…+8 dBm sat, 100 Ω differential | Drives external PA module; power control ≥ 30 dB range, 1–2 dB steps |
| TX DAC | FIR-DAC (32/48/64 taps), ≥ 8 bit in ±250 kHz | On-chip 3rd-order digital ΣΔ feeds it (host sends plain I2S samples) |
| TX analog filter | 3rd-order Butterworth LPF, corner ~200–900 kHz programmable, RC-calibrated | SX1255 range, plus cal (they had ±30 %) |
| Synthesizer step | F_XOSC/2^20 referred to RF (≈ 30.5 Hz @ 32 MHz) | 24-bit FRF word, SX1255-compatible semantics |
| Phase noise @ RF | ≤ −100 dBc/Hz @ 25 kHz offset; ≤ −128 dBc/Hz @ 1 MHz; integrated (500 Hz–125 kHz) ≤ 1° RMS | Sets NBFM adjacent-channel and M17 EVM floor |
| Reference | 32 MHz default (support 26–40 MHz), XTAL or clipped-sine TCXO (≤ 1.2 Vpp into XTB-style input) | Decision D1, §15 |
| Digital IF | **I2S** (Philips), chip = bus master; WS = sample rate; 16-bit I + 16-bit Q per frame; rates 125 k / 250 k / 500 k / 1 MS/s (R = MANT·3^m·2^n divider like SX1255) | One data pin per direction (SDO/SDI), shared BCLK/WS |
| Control | SPI mode 0, ≤ 10 MHz, 7-bit addr + R/W̄ bit, burst auto-increment, full readback | ~32-register map, §5.3 |
| Supplies | 1.5 V analog (3 domains) + 1.5 V digital + 3.3 V I/O, external rails (first tapeout) | On-chip LDOs deferred — Decision D4 |
| Current (typ) | RX ≤ 35 mA, TX ≤ 60 mA @ 1.5 V; Standby (XO+bias) ≤ 2 mA; Sleep ≤ 10 µA | SX1255: 18 mA RX / 60 mA TX @ 3.3 V incl. LDOs |
| Package | QFN-32, exposed ground paddle | Template padframe is 32 pads; Decision D5 |
| Die size | **2.0 × 2.0 mm** target (core ≈ 1.27 × 1.27 mm) | Template's 1.6 mm die is too small for the area budget (§8); TinyWhisper precedent is 2×2 |
| Temperature | −40…+85 °C operating (industrial) | STA/CACE corners at −40/27/125 °C junction |
| ESD | HBM 2 kV all pins (RF pins with low-C custom protection) | §9 |

---

## 4. System architecture

### 4.1 Block diagram

```
                                ┌───────────────────────────────────────────────┐
    RFI ──[LNA]──[S2D]──┬──[I mix]──[TIA+LPF3]──[PGA]──[ΣΔ ADC I]──┐            │
                        │     ▲ 0°                                 │  ┌──────┐  │
                        └──[Q mix]──[TIA+LPF3]──[PGA]──[ΣΔ ADC Q]──┼──┤ DEC  ├──┼── I2S SDO
                              ▲ 90°   (25% duty LO, 130–520 MHz)   │  │ CIC+ │  │
                                                                   │  │ HB   │  │
   XTA/XTB ──[XO/TCXO buf]──┬────────────────────────────────┐     │  └──────┘  │
                            │                                │     │            │
                            ▼                                ▼     │  ┌──────┐  │
                    ┌──[PFD/CP/LF]──[VCO 2.08–4.16G]──[÷2]──[÷1|÷2]┴─[÷2 IQ/25%]│
                    │        ▲                                      │            │
                    │   [MMD ÷N.f]◄──[MASH-3 ΣΔ 20b]◄──[FRF regs]  │  ┌──────┐  │
                    │                                               │  │ INT  │  │
   RFO_P ◄─[DRV]◄─[Σ]◄─[I mix]◄─[LPF3]◄─[FIR-DAC I]◄──[ΣΔ mod 3rd]◄┴──┤ CIC+ ├──┼── I2S SDI
   RFO_N ◄        └───[Q mix]◄─[LPF3]◄─[FIR-DAC Q]◄──[ΣΔ mod 3rd]◄────┤ HB   │  │
                                                                       └──────┘  │
   SPI (CSN/SCK/MOSI/MISO) ──► [reg bank + sequencer + cal FSMs] ◄── STAT/IRQ    │
   DIOs: IRQ, PA_EN, SW_CTRL   [RC-cal, VCO band cal, loopbacks]  BCLK/WS ◄──────┘
```

### 4.2 Operating modes

SX1255-style mode **bits**, not a state machine: `ref_enable` (bias + XO → Standby), `rx_enable`, `tx_enable`, `driver_enable` (separate, for PA ramping and external-PA sequencing). An auto-sequencer orders XO start → PLL start → converters on (the VCO band comes from the host-cached band map, §4.3), and exposes `xosc_ready`, `pll_lock`, `fcnt_done` in STAT + on IRQ/DIO pins. Sleep = everything off, register retention, < 10 µA.

### 4.3 Frequency plan (the main redesign vs SX1255)

144–450 MHz is 1.66 octaves — no single fixed-divider LO covers it. Plan:

- **LC VCO at 2.08–4.16 GHz** (one octave). Divider chain: VCO → ÷2 (CML) → optional ÷2 → final **÷2 with quadrature 25 %-duty outputs** ⇒ total ÷8 or ÷16.
  - ÷8: LO = 260–520 MHz
  - ÷16: LO = 130–260 MHz → **continuous 130–520 MHz**, quadrature always from a final ÷2 (best IQ accuracy), LO at 8–16× RF (no PA pulling, low LO leakage — same rationale SX1255 gives for its 4× VCO).
- Octave tuning needs Cmax/Cmin ≈ 4 in the tank — aggressive for one core with parasitics. **P1 decision (D8): single core with 6-bit switched-cap bank vs. two overlapping cores** (e.g. 2.0–2.95 GHz + 2.85–4.3 GHz) sharing the buffer. Dual-core is lower risk; costs one more inductor (~0.06 mm²).
- **Fractional-N ΣΔ PLL** (single, shared TX/RX): PFD/CP at F_XOSC (32 MHz), MASH 1-1-1 (20-bit fractional), multi-modulus divider ÷65…÷130 (CML ÷4/÷5 prescaler + pulse-swallow or fully programmable MMD). Loop BW programmable ≈ 75–300 kHz (SX1255 semantics). Loop filter **integrated** (3rd-order passive; ~100–300 pF MIM — area-checked in §8; capacitance-multiplier fallback if area explodes).
- **Frequency programming** (SX1255-compatible semantics): F_RF = F_XOSC · FRF(23:0) / 2^20 ⇒ 30.5 Hz step @ 32 MHz. Digital core derives divider-select (÷8/÷16) and PLL N.f from FRF automatically (manual override register for bring-up). Separate FRF_RX / FRF_TX words; the active one is loaded on mode entry and re-latched on LSB write ⇒ fast TDD turnaround without re-writing frequency.
- **VCO band calibration**: on-chip **frequency counter** (counts VCO/2^k against the reference over a programmable window) readable via SPI; the **band search runs on the host** (binary search writing the cap-bank register, reading the counter). The host caches a band map per band edge, so retunes are a single register write. No on-chip cal FSM — see §12.1 rule 2.
- Phase-noise budget: free-running VCO ≈ −110 dBc/Hz @ 1 MHz @ 3.6 GHz; ÷8 gives −18 dB ⇒ ≈ −128 dBc/Hz at RF. In-band (PLL) floor target −95…−100 dBc/Hz at RF ⇒ integrated jitter ≪ 1° RMS. Fractional spurs: MASH dithering + loop BW ≤ 300 kHz; worst-case near-integer channels analyzed in P1.

### 4.4 Receive chain

- **LNA**: single-ended input (one RF pad + dedicated ground), **inductorless** wideband topology. Candidate: common-gate/common-source **noise-cancelling balun-LNA** (Blaakmeer/Bruccoleri style) — gives single-ended-to-differential conversion for free (replaces SX1255's separate S2D buffer), NF ≈ 3 dB, S11 < −10 dB over 130–520 MHz without inductors. 6 coarse gain steps (0/−6/−12/−24/−36/−48 dB) via load/attenuator switching. Selectable 50 Ω input (drop SX1255's 200 Ω option unless LinHT front-end wants it — Decision D7). HBT option for the input device evaluated in P1 (SiGe gives NF headroom cheaply at these frequencies).
- **Mixer**: quadrature **passive current-mode mixer** (TG switches, 25 % duty LO) into **TIA** — high IIP2/IIP3, low 1/f, no bias current in the switch core. TinyWhisper proved the TG+25 % style in this PDK (TX direction).
- **Baseband filter**: TIA with RC feedback (1st-order roofing pole) followed by **3rd-order active-RC Butterworth LPF** (inverter-based OTAs, MFB — reuse/adapt TinyWhisper's 400 kHz design), corner programmable ≈ 250/375/500/750 kHz SSB, **RC-trimmed** (host-computed trim code, §4.6).
- **PGA**: −24…+6 dB, 2 dB steps (resistor-ladder around an OTA). All gain SPI-set; AGC loop closed by the host (SX1255 model).
- **ADC**: per rail, **3rd-order 1-bit CT ΣΔ** (CIFF, RC integrators, clocked at F_XOSC = 32 MHz). OSR = 64 for ±250 kHz ⇒ ~78 dB SQNR theoretical, ≥ 72 dB target post-layout ⇒ 12+ bit; ±500 kHz mode at OSR 32 ⇒ ~10 bit. `rx_adc_bw`-style loop scaling + RC trim registers. (SX1255 needed a 5th-order loop only because it ran OSR ≈ 32–36 at 500 kHz SSB; we double the OSR for the primary use case instead — much safer to stabilize.)
- **Gain/NF cascade** (max gain, to be refined in P1 Python model): LNA 18 dB/NF 3 → mixer+TIA −1 dB/NF 12 → LPF+PGA 30 dB → ADC input −3 dBFS at MDS+70 dB. Total NF ≈ 4.5–5 dB, in-channel DR ≥ 90 dB with AGC.

### 4.5 Transmit chain

- Host sends plain 16-bit I/Q over I2S → **interpolation (CIC + halfbands)** to F_XOSC → **3rd-order digital ΣΔ modulator** (feed-forward, single-bit, stable to −3 dBFS, saturating integrators — SX1255 app-note recipe, but on-chip) → **FIR-DAC** per rail: the 1-bit stream shifts through an N-tap register whose taps gate unit current cells with FIR-weighted W — reconstruction DAC and semi-digital filter in one, mostly-digital layout, ≥ 8 bit in ±250 kHz. Taps programmable 32/48/64 (BW ∝ fs/N: 32 taps @ 32 MHz ≈ 450 kHz).
- **3rd-order Butterworth active-RC LPF** (same core as RX filter, wider corner options 200–900 kHz) to strip remaining ΣΔ noise.
- **Upconversion mixer**: passive **voltage-mode TG quadrature mixer** (25 % LO) summing I and Q — TinyWhisper-style. **No LC tank load** (SX1255's programmable tank cannot span 1.7 octaves): broadband resistive/inverter load.
- **PA driver**: differential class-AB, open-drain-style outputs RFO_P/N, optimum 100 Ω differential load via external balun/choke; +5…+8 dBm sat, linear 0 dBm avg. Gain control: FIR-DAC full-scale (3 dB steps) + driver/mixer gain (2 dB steps) ⇒ ≥ 30 dB range upstream of a fixed-gain driver (SX1255 model). Separate `driver_enable` for ramping.
- **TX impairments**: LO leakage trimmed via **DC-offset trim DACs** on the TX baseband (register-set, host-calibrated through RF loopback); IQ gain/phase corrected digitally in the bridge (small multiplier) — SX1255 lacked both on chip; they're cheap and de-risk zero-IF TX.

### 4.6 Clocking, calibration, impairments

- **One reference**: XTA/XTB Pierce XO core (32 MHz default) **or** clipped-sine TCXO into XTB with XTA open (SX1255 scheme). Everything derives from it: PFD, ΣΔ converter clocks, digital core, BCLK. `CLK_OUT`-style buffered reference is merged with the I2S BCLK pin function (chip is I2S master); a gated dedicated CLK_OUT is Decision D9.
- **RC trim**: a reference RC measured by the shared on-chip frequency counter, readable over SPI; the **host** computes the 4–5-bit trim code and writes it once (broadcast to RX/TX filters and ADC integrators). Fixes the ±30 % corner accuracy SX1255 shipped with — without an on-chip cal engine (§12.1 rule 2).
- **VCO band cal**: §4.3, on retune; result in STAT.
- **Loopbacks** (CK_SEL-style register): (a) **digital loopback** — I2S TX path fed back to RX path before the converters; (b) **RF loopback** — attenuated tap of the TX driver into the RX mixer input. Host measures/corrects RX & TX IQ imbalance, TX LO leakage, and absolute gain.
- **DC offset / 1/f (the zero-IF elephant)**: a 12.5 kHz channel at true zero-IF sits inside the flicker/DC hole. Strategy (all three, belt-and-braces):
  1. **Digital low-IF operation**: host tunes LO 100–200 kHz off-channel and does the final complex mix in software — the channel lands in clean spectrum; image is adjacent spectrum suppressed by IQ balance (≥ 35 dB raw, > 50 dB after host cal). This is pure software convention — chip support is just "LO where the register says."
  2. Passive mixer + TG switches ⇒ intrinsically low 1/f corner.
  3. Programmable **digital HPF/DC servo** in the RX bridge (bypassable) + static offset trim DACs at the TIA.
- **Temperature sensor**: reuse an RX ADC in standby (SX1255 trick, ~free).

### 4.7 Power domains

Five external rails / four on-die domains (LDOs deferred to rev B — Decision D4):

| Rail | Pads | Feeds |
| --- | --- | --- |
| AVDD_RF (1.5 V) | 1 | LNA, mixers, TIA, TX driver |
| AVDD_VCO (1.5 V) | 1 | VCO, CML dividers, CP/PFD (star-routed, own AVSS_VCO) |
| AVDD_BB (1.5 V) | 1 | Filters, PGAs, ADCs, FIR-DACs, bias, XO |
| DVDD (1.5 V) | 1 | Digital core |
| IOVDD (3.3 V) | 1 | Pad ring |

**Known gap:** the template supports a single core domain today (multi-domain is on the OSICD roadmap). We will implement domains with separated power pads, pad-ring supply-cut cells, and per-domain PDN islands in `pdn_cfg.tcl` — this is real engineering work, tracked as risk R3 (§13).

---

## 5. Digital architecture

Everything runs at F_XOSC (32 MHz) in one clock domain (SPI is its own small async domain, 2-FF synchronized). Gate estimate ≈ 35–50 kGE ⇒ ~0.35 mm² hardened.

### 5.1 Blocks

| Block | Function | Est. size |
| --- | --- | --- |
| SPI slave | Mode 0, 7-bit addr + R/W̄, burst auto-increment, old-value-on-MISO during writes (SX1255 nicety) | 1 kGE |
| Register bank | ~32 bytes R/W + shadow latching (FRF on LSB write / mode entry) | 3 kGE |
| Sequencer | XO→PLL→cal→converters ordering, TDD turnaround, DIO/IRQ mapping | 2 kGE |
| RX bridge | CIC sinc⁴ decimator (÷R/4) + 2 compensated halfbands, DC servo/HPF, IQ gain/phase correction, R = MANT·3^m·2^n ∈ {32…1536} | 12 kGE |
| TX bridge | mirror interpolator + 3rd-order ΣΔ modulators (I, Q) | 10 kGE |
| I2S unit | Master-only: BCLK = F_XOSC/div, WS = fs, 16-bit×2; illegal-combo flag (SX1255 `IISM_status_flag`) | 2 kGE |
| Cal support | Frequency counter (VCO/RC, SPI readback), PLL SDM (MASH-3 20-bit) + N mapping from FRF — band/RC search algorithms run on the host (§12.1 rule 2) | 4 kGE |
| Test | raw 1-bit ΣΔ tap to DIOs (SX1255 "Mode A" as debug mode), digital loopback, scan hooks | 2 kGE |

### 5.2 Sample-rate plan (32 MHz reference)

| R (decim/interp) | fs | Use |
| --- | --- | --- |
| 32 | 1 MS/s | ±500 kHz wideband mode (reduced ENOB) |
| 64 | 500 kS/s | **default** — ±250 kHz, 16-bit, BCLK = 16 MHz (exactly 32 bit/sample) |
| 128 | 250 kS/s | narrowband, more ENOB |
| 256 | 125 kS/s | NBFM/M17 economy mode |

Keep the R = MANT·3^m·2^n scheme (MANT ∈ {8,9}) so 36/38.4 MHz references also land on useful rates.

### 5.3 Register map draft (v0.1 — SX1255-compatible where sensible)

| Addr | Name | Fields (draft) |
| --- | --- | --- |
| 0x00 | MODE | driver_en, tx_en, rx_en, ref_en |
| 0x01–0x03 | FRF_RX | 24-bit, F = F_XOSC·word/2^20, latch on LSB write / RX entry |
| 0x04–0x06 | FRF_TX | 24-bit, latch on LSB write / TX entry |
| 0x07 | VERSION (r) | mask/metal rev |
| 0x08 | TXGAIN | dac_gain[1:0] (3 dB steps), mixer_drv_gain[3:0] (2 dB steps) |
| 0x09 | TXBW | tx_filter_bw[4:0] |
| 0x0A | TXDAC | fir_taps[1:0] (32/48/64), sd_dither_en |
| 0x0B | RXFE | lna_gain[2:0], zin_sel |
| 0x0C | RXGAIN | pga_gain[3:0], pga_bw[1:0] |
| 0x0D | RXADC | adc_bw[2:0], adc_trim[2:0] |
| 0x0E | PLL | pll_bw[1:0], lo_div_ovr[1:0] (auto/÷8/÷16) |
| 0x0F | IOMAP | DIO0–3 mapping |
| 0x10 | CKSEL | dig_loopback, rf_loopback, clkout_en |
| 0x11 | STAT (r) | xosc_ready, pll_lock, fcnt_done, iism_err |
| 0x12 | IISM | mode, bclk_div[3:0], rx_dis, tx_dis |
| 0x13 | BRIDGE | mant, m, n[2:0], truncation |
| 0x14 | VCOBAND | band[5:0] — host-written from its cached band map (search runs on host) |
| 0x15 | FCNTCTL | fcnt_start, source (VCO/RC), window[2:0] — frequency-counter control |
| 0x16/0x17 | TXDCO_I/Q | TX DC-offset trim (LO leakage) |
| 0x18/0x19 | IQCORR | RX/TX gain & phase correction |
| 0x1A | RXHPF | DC-servo corner, bypass |
| 0x1B | RCTRIM | rc_trim[4:0] — host-computed, broadcast to filters/ADC |
| 0x1C | TSTMUX | atest select, raw-ΣΔ-on-DIO enable |
| 0x1D | BIAS | bandgap/bias trims |
| 0x1E | IRQMASK | per-STAT-bit IRQ enable |
| 0x1F | SCRATCH | R/W test byte |
| 0x20–0x21 | FCNT_H/L (r) | 16-bit frequency-counter readback |

---

## 6. Block plan (each = one self-contained macro)

For every macro: xschem schematic → ngspice/VACASK testbenches → CACE spec (PVT + MC) → KLayout layout → dual DRC + dual LVS + PEX → post-layout re-sim → `final/` views (GDS/LEF/LIB-stub/Verilog-stub/CDL). Effort figures = full-time person-weeks for an experienced designer (design + layout + verification) — read them as **relative sizing** between blocks; the actual calendar at 10–15 h/wk with learning-in-the-loop is §12.

| # | Macro | Contents | Key specs / risks | Effort |
| --- | --- | --- | --- | --- |
| 6.1 | `bias_top` | Bandgap, PTAT, current DACs, POR | ±5 % untrimmed, trim reg; start-up MC | 4 |
| 6.2 | `xo_top` | Pierce core + TCXO clipped-sine path, squarer, clock tree root | jitter ≤ 1 ps RMS integrated; 26–40 MHz | 4 |
| 6.3 | `vco_top` | LC VCO (1–2 cores), 6-bit cap bank, varactor, buffer | 2.08–4.16 GHz, PN −110 dBc/Hz @1 MHz; **inductor EM-verified** (openEMS/Palace + PDK model cross-check); KVCO flatness | 8 |
| 6.4 | `lodiv_top` | CML ÷2 chain, ÷8/÷16 select, 25 % quad gen, LO distribution | IQ error < 1°/0.5 dB; retiming FF at output | 5 |
| 6.5 | `pll_top` | PFD, CP, integrated 3rd-order LF, MMD ÷65–130, lock detect (SDM is in digital) | spurs < −60 dBc; CP mismatch < 2 %; LF area | 8 |
| 6.6 | `rx_fe` | Noise-cancelling balun-LNA + gain steps + passive I/Q mixer + TIA | NF ≤ 3.5 dB block-level; S11; gain-step monotonicity | 8 |
| 6.7 | `bb_filter` (×2 inst) | 3rd-order active-RC Butterworth + PGA, RC-trim bus | corner ±5 % after cal; OTA from TinyWhisper lineage | 6 |
| 6.8 | `rx_adc` (×2 inst) | 3rd-order 1-bit CT ΣΔ @ 32 MHz | stable over RC ±30 % pre-cal; VACASK trannoise + behavioral (python-deltasigma) NTF sign-off | 8 |
| 6.9 | `tx_dac` (×2 inst) | FIR-DAC 64-tap unit-current array + retiming | 8-bit/±250 kHz; element matching MC | 5 |
| 6.10 | `tx_fe` | TG voltage-mode quad upmixer + summer + class-AB driver + RF-loopback tap | +8 dBm sat @100 Ω diff; stability K-factor all corners; ESD co-design | 8 |
| 6.11 | `atest_top` | Analog test mux (2 pads), raw-node observability | leakage when off | 2 |
| 6.12 | `digital_core` | Everything in §5, hardened with LibreLane | STA at all template corners; GL cocotb | 10 |
| 6.13 | (rev B) `ldo_top` | 3.3 V→1.5 V LDO bank | deferred — D4 | — |

Shared infrastructure tasks: LO/clock distribution plan, trim/cal bus definition, ESD cells for RF pads, supply-cut pad-ring cells, chip-level decap tiles.

---

## 7. Pinout proposal (QFN-32, exposed pad = GND)

Grouped by domain around the die like SX1255 (supply-domain floorplan discipline):

| Side | Pads (in order) |
| --- | --- |
| **South (RF)** | AVSS_RF · RFI · AVSS_RF · RFO_N · RFO_P · AVDD_RF · AVDD_VCO · AVSS_VCO |
| **West (analog/ref)** | XTA · XTB · AVDD_BB · AVSS_BB · ATEST_I · ATEST_Q · RESET_N · DIO0/IRQ |
| **North (host digital)** | DVDD · DVSS · IOVDD · IOVSS · CSN · SCK · MOSI · MISO |
| **East (I2S + control)** | BCLK · WS · SDO (RX IQ) · SDI (TX IQ) · DIO1/PA_EN · DIO2/SW_CTRL · DIO3 · spare-GND |

Notes: RFI flanked by grounds; VCO supply pair adjacent and away from digital; I2S bus on the side facing the SoM; DIO1/DIO2 double as external PA-enable and antenna-switch control (register-mapped, sequencer-timed); ATEST pins use `padbare`, RF pins custom low-C ESD (§9).

---

## 8. Floorplan and area budget

Target: **die 2.0 × 2.0 mm**, padframe margin 365 µm ⇒ core ≈ 1.27 × 1.27 mm = 1.61 mm² (TinyWhisper geometry).

| Region | Blocks | Est. area |
| --- | --- | --- |
| SW quadrant (RF) | rx_fe, tx_fe (near south pads) | 0.15 mm² |
| SE quadrant (synth) | vco_top (incl. inductor(s)), pll_top + loop-filter MIM, lodiv | 0.35 mm² |
| NW quadrant (baseband) | bb_filter ×2, rx_adc ×2, tx_dac ×2, bias, xo, atest | 0.45 mm² |
| NE quadrant (digital) | digital_core | 0.35 mm² |
| Glue | routing channels, decap fill (LibreLane), guard rings | 0.30 mm² |
| **Total** | | **≈ 1.6 mm²** — fits with little slack; 2.2 mm die is the fallback |

LO runs from SE to SW (RF mixers) as differential shielded pairs on TM1; supply-domain guard rings (deep n-well / substrate contacts per SG13G2 rules) between quadrants. Update `DIE_AREA`/`CORE_AREA`/`PAD_*` in `flow/librelane/config.yaml` accordingly; per-domain PDN islands in `pdn_cfg.tcl` (cf. the SRAM-specific grid already in the template as a pattern).

---

## 9. Padframe and ESD

- Digital pads: IHP `sg13g2_io` cells (as templated). **Watch IHP-Open-PDK issue #962** (tap-cell and sim-convergence issues) — re-verify with the container release we pin.
- RF pads (RFI, RFO_P/N): analog pad cells via `padbare` + **custom ESD**: low-C dual diodes to AVDD_RF/AVSS_RF + rail clamp; C_ESD budget ≤ 300 fF per pin (at 520 MHz this is fine; it's not a GHz LNA problem). HBM 2 kV target, verified by ESD network simulation (no open-source HBM sign-off exists — design by rule + review).
- XTA/XTB: `padres` path (series R acceptable, protects the XO gate oxide).
- Supply cuts between IOVDD segments if the pad ring must separate noisy/quiet domains (evaluate — the SG13G2 IO library's filler/breaker options need a P1 check).
- Bonding diagram in KLayout per OSICD flow (QFN-32 cavity).

---

## 10. Design-flow mapping (OSICD)

Container: **IIC-OSIC-TOOLS ≥ 2026.06**, pinned per tapeout. Everything Makefile-driven from this repo; every block a recursive macro (`macros/<name>/` with its own Makefile, `schematic/`, `testbenches/`, `verification/`, `final/`).

| Activity | Tool(s) |
| --- | --- |
| System model | Python (numpy/scipy, python-deltasigma) in `scripts/system_model/`; outputs: gain/NF/IIP cascade, NTFs, filter coefficients (→ RTL params), PN budget, link budget — all regression-run |
| Behavioral chip model | SystemVerilog real-number models of analog blocks + RTL, cocotb top testbench (modem-in-the-loop with recorded M17 vectors) |
| Schematic entry | Xschem (project `xschemrc` already wraps it) |
| Analog sim | ngspice (op/ac/tran/noise), **VACASK** (HB, transient-noise, acstb for filter/OTA stability, ADC trannoise), Xyce (big parallel transients, full-chain TX sim) |
| Characterization | **CACE** spec per macro: PVT (MOS tt/ss/ff × temp −40/27/125 × VDD ±5 %) + Monte-Carlo mismatch (≥ 200 runs on matching-critical: ADC, FIR-DAC, CP, bandgap, IQ paths) |
| EM | openEMS / Palace for VCO inductor(s), LO routing, RF pad + bondwire; cross-check against IHP PDK inductor models; SG13G2_SPARX repo as RF-flow reference |
| Digital | Verilator lint → cocotb + Icarus (RTL & GL) → LibreLane hardening of `digital_core` (STA all corners) |
| Layout | KLayout (analog), LibreLane/OpenROAD (digital + top assembly, NDR rules for LO/RF/supply nets, decap insertion) |
| Verification | Dual DRC (Magic + KLayout), dual LVS (netgen + KLayout), PEX (magic-pex / kpex, `EXT_MODE=3` full-RC for RF blocks) — per macro *and* top |
| Top-level sign-off | **Analog-on-top**: full-chip xschem schematic, LVS with **no black boxes**; mixed-signal top sim with `digital_core` as XSPICE (`spi2xspice`, template targets exist); GL cocotb of digital; `make all` green in CI |
| Docs | Rewrite `doc/specifications.md` / `pinout.md` / `floorplan.md` from this plan as the design solidifies; Quarto tutorial optional |

---

## 11. Verification plan and tapeout checklist

Per-block exit criteria: CACE all-green at PVT+MC, layout DRC/LVS clean in both engines, post-PEX sim meets spec with margin noted in the macro README.

Chip-level (the de-facto OSICD sign-off, extended):

1. `make all` green: sim-all (RTL+GL cocotb), build-all, dual top DRC, antenna, density/fill.
2. Full-chip un-black-boxed LVS (netgen + KLayout).
3. Mixed-signal top transients: (a) SPI write/readback of every register through pad models; (b) RX tone → I2S samples end-to-end (XSPICE digital + transistor analog, short run); (c) TX I2S vector → RF spectrum check; (d) mode sequencing incl. PLL lock, with the host band-search algorithm scripted in the testbench.
4. PLL closed-loop PN (VACASK/behavioral hybrid) meets §3 mask at 4 frequencies (144, 223, 435, 520 MHz — includes near-integer-N worst case).
5. STA all six template corners; CDC review (SPI↔core).
6. ESD network review; latch-up guard-ring review.
7. Pad ring: bonding diagram generated; pin-vs-package cross-check against eval-board schematic.
8. Release: `make release VERSION=…` + tag; MPW submission docs.

---

## 12. Schedule — 12–24 months, one graduate student, 10–15 h/week

### 12.1 Hour budget and pacing rules

| Quantity | Value |
| --- | --- |
| Weekly availability | 10–15 h (hard cap — coursework comes first) |
| Yearly budget | ≈ 50 working weeks × 10–15 h = 500–750 h |
| 24-month envelope | ≈ 1 000–1 500 h |
| This plan | ≈ 1 320 h (year 1 ≈ 660 h, year 2 ≈ 660 h) ≈ 13 h/wk average — inside the envelope, with the §12.6 levers as slack |

Three rules keep a first-time designer inside that budget:

1. **Reuse before design.** TinyWhisper's IQ-modulator lineage (inverter-based OTAs, MFB filters, TG passive mixers, 25 % LO), the template's digital/flow infrastructure, and JKU analog-circuit-design course blocks (bias, OTA, bandgap) are starting points, not references — blocks get re-sized, not re-invented.
2. **Host-side smarts.** No on-chip calibration FSMs: the chip exposes a frequency counter, trim registers, and loopbacks over SPI; VCO band search, RC trim, IQ/DC correction all run as host software (SX1255 philosophy, taken further).
3. **De-scope levers, not schedule slips** (§12.6). Fixed checkpoints decide what ships; shuttle dates do not move.

### 12.2 Two staged tapeouts

| Stage | Content | Tapeout | Why this split |
| --- | --- | --- | --- |
| **α — test chip** (months 1–12) | `digital_core` (SPI, registers, I2S, bridge) + `xo_top` + complete synthesizer (`vco_top`, `lodiv_top`, `pll_top`, frequency counter) + `atest_top`, in the final 5-rail padframe/PDN | month 12 (or next shuttle ≤ 14) | Retires the highest risks (R1 octave VCO, R3 multi-domain padframe, R5 spurs) and 100 % of the flow learning; silicon-validates the LO — the block everything else depends on |
| **β — full transceiver** (months 13–24) | RX chain (`bb_filter`, `rx_adc`, `rx_fe`), TX chain (`tx_dac`, `tx_fe`), full assembly reusing the α-proven synth, digital core, and padframe | ≈ month 24 | RX/TX macros drop into a validated environment; α bring-up (months ~15–18, as silicon returns) feeds real PN/leakage/lock data back into the RF front-end design |
| *(Option B: single tapeout ≈ month 18–20)* | everything on one GDS | ≈ month 18–20 | saves one shuttle/package cycle but delays all silicon feedback and stacks every risk on one submission — not recommended for a first chip |

### 12.3 Phase map (P0–P8 → months)

| Phase | Content | Months |
| --- | --- | --- |
| P0 | Spec freeze, decisions D1–D10, shuttle pick | 1 |
| P1 | System model (cascade, NTF, PN budget, spur scan) | 2–3 |
| P2 | Digital core RTL → hardened macro | 4–6 |
| P3a | Synthesizer macros (vco/lodiv/pll/xo/bias) | 6–10 |
| P3b | RX/TX macros (bb_filter, rx_adc, rx_fe, tx_dac, tx_fe) | 13–21 |
| P4 | RF/EM (inductor, LO routing, pads) | continuous |
| P5 | Integration (padframe, PDN, floorplan) | α: 11 · β: 22 |
| P6 | Top verification (§11 checklist) | α: 11–12 · β: 22–23 |
| P7 | Tapeout | α: 12 · β: 24 |
| P8 | Bring-up | α silicon: 15–18 · β silicon: 25+ |

### 12.4 Year 1 month-by-month (α stage)

Each month ≈ 50–65 h. The **Learning track** column is that month's "study first, then apply" material from `literature/` and the template tutorial.

| Mo | Theme | Design work | Learning track | Exit deliverable | ≈ h |
| --- | --- | --- | --- | --- | --- |
| 1 | Flow bootcamp + spec | Template tutorial end-to-end (counter + inverter, `make all`); resolve D1–D7 with advisor; pick shuttles (D10); scaffold macro dirs | OSICD tools, Makefile/git discipline; *SDR for Engineers* ch. 2/4/5 (IQ, zero-IF) | `specifications.md` rev-A; `make all` green locally | 55 |
| 2 | System model I | RX/TX gain–NF–IIP cascade + link budget notebooks; sample-rate and frequency-plan checks | *RF Microelectronics* ch. 2–4 (NF, nonlinearity, architectures) | Gain plan v1 in `scripts/system_model/` | 50 |
| 3 | System model II + regmap | PLL phase-noise budget + fractional-spur scan; ΣΔ NTF study (python-deltasigma); register map v1.0 | *Design of CMOS PLLs* ch. 1–2, 12–14 (frac-N); ΣΔ tutorial papers | **M1 architecture review** with advisor | 55 |
| 4 | Digital I | SPI slave + register bank + mode sequencer, cocotb testbenches | SystemVerilog, cocotb, CDC basics | SPI/regbank sims green | 55 |
| 5 | Digital II | I2S master; CIC + halfband bridge bit-exact vs Python golden; TX ΣΔ modulator; frequency counter + PLL SDM blocks | Multirate DSP (CIC/halfband theory) | Bridge matches golden model; Verilator-clean | 55 |
| 6 | Digital III + VCO start | Harden `digital_core` with LibreLane, GL cocotb (**Checkpoint 1**, §12.6); VCO tank sizing calcs | LibreLane/STA; *CMOS PLLs* ch. 5–6 (LC oscillators) | `digital_core` GDS, STA clean | 55 |
| 7 | VCO | VCO schematic + 6-bit cap bank; phase-noise sims (VACASK); inductor choice + openEMS sanity check | PN theory (*CMOS PLLs* ch. 4); EM tool basics | VCO meets PN/tuning at TT; **D8 decided** (1 vs 2 cores) | 55 |
| 8 | Dividers + PFD/CP | CML ÷2 chain + 25 % quadrature gen; PFD/CP schematic; loop-filter design script; MMD | *CMOS PLLs* ch. 15 (dividers), ch. 7–9 (CP-PLL design) | Open-loop synth blocks clean at corners | 60 |
| 9 | PLL closed loop | Hybrid behavioral/transistor lock + PN sims; host band-search algorithm prototyped against sim; start VCO/divider layout | Mixed-level sim methodology (Kundert ch. 19/32) | Closed-loop PN mask met in sim | 55 |
| 10 | Synth layout + sign-off | PLL/lodiv layout; dual DRC/LVS + PEX re-sim; CACE PVT (+ MC on CP, VCO) (**Checkpoint 2**, §12.6) | Analog layout: matching, guard rings (*Analog CMOS* layout chapters) | Synth macros `final/` views, CACE green | 60 |
| 11 | α integration | `chip_core.sv`; 5-rail padframe + PDN islands (**retires R3**); floorplan; top DRC/LVS loops; mixed-signal top sim (SPI + PLL lock, XSPICE) | Padframe/`config.yaml`/PDN internals | α GDS candidate; §11 checklist (α subset) green | 60 |
| 12 | α tapeout | Fix findings; docs + bonding diagram; `make release`; shuttle submission; eval-board schematic started | Bring-up/test methodology | **M6α: GDS out** | 50 |

### 12.5 Year 2 (β stage)

| Months | Focus | Exit deliverable | ≈ h |
| --- | --- | --- | --- |
| 13–14 | `bb_filter` + PGA (re-size TinyWhisper MFB/OTA lineage), RC trim hooks | Filter macro `final/`, CACE green | 110 |
| 15–17 | `rx_adc`: behavioral NTF → transistor → layout, MC on matching ∥ **α silicon bring-up** as parts return (board assembly, SPI/clock, lock map over 130–520 MHz, PN measurement, host cal scripts) | ADC macro final; **α silicon report** | 170 |
| 18–19 | `rx_fe`: balun-LNA + TG passive mixer — with α-measured PN/leakage/lock data as design inputs | rx_fe final, CACE green | 110 |
| 20–21 | `tx_dac` FIR-DAC + `tx_fe` (TG upmixer + class-AB driver + RF-loopback tap) (**Checkpoint 3**, §12.6) | TX macros final | 110 |
| 22–23 | β integration on the α-proven padframe/PDN; full §11 checklist | Full-chip GDS candidate, checklist green | 110 |
| 24 | **β tapeout**; datasheet draft from CACE data; LinHT bring-up plan | **M6β: GDS out** | 50 |

Post-month-24 (silicon lead time ~3–4 months): β bring-up per §14, LinHT SoM integration, M17 over-the-air demo, errata → rev B scope (LDOs).

### 12.6 De-scope levers (pull at checkpoints, never move a shuttle date)

Checkpoints: **C1** end month 6 (digital hardened?), **C2** end month 10 (synth macros final?), **C3** end month 21 (TX macros final?). If behind, pull levers top-down:

| Lever | What ships instead | Saves |
| --- | --- | --- |
| L1 | Fixed 500 kS/s I2S rate (drop R-programmability), 16-bit only | ~15 h digital + verif |
| L2 | Fixed 32-tap FIR-DAC, no tap programmability | ~10 h |
| L3 | Drop on-chip digital IQ correction (host does it); keep TX DC trim DACs | ~20 h |
| L4 | RX ±250 kHz only (drop the ±500 kHz reduced-ENOB mode) | ~15 h ADC/bridge config |
| L5 | Single analog test pad instead of two | ~5 h |
| L6 | **Emergency exit:** α slips content (e.g. no atest), or β content moves to the next shuttle — dates hold, scope moves | bounded by shuttle cadence |

Supervision cadence: biweekly advisor reviews; each macro's CACE spec doubles as the acceptance rubric, so "done" stays machine-checkable (`make all` green month over month).

---

## 13. Risk register

| # | Risk | L×S | Mitigation |
| --- | --- | --- | --- |
| R1 | Octave VCO tuning range not met over PVT | M×H | P1 dual-core decision with MC data; cap-bank margin ≥ 15 %; band-overlap ≥ 2 bands |
| R2 | CT ΣΔ ADC instability / RC spread | M×H | 3rd-order (not 5th) loop; RC cal; behavioral→transistor equivalence checks; VACASK trannoise sign-off; scaled-back 2nd-order bailout mode via `adc_bw` |
| R3 | Multi-domain padframe/PDN not supported by template | H×M | Prototype the 5-rail pad ring + PDN islands **early in P2** on a dummy floorplan; upstream findings to JKU template |
| R4 | SG13G2 I/O cell issues (#962: taps, sim convergence) | M×M | Pin container version; re-run template regression; custom pad variants in `ip/sg13g2_io_custom` if needed |
| R5 | Fractional spurs on near-integer channels degrade ACPR | M×M | P1 spur scan; MASH dithering; loop-BW register; worst channels documented for host to avoid ±ε offsets (digital low-IF gives freedom) |
| R6 | Integrated loop-filter area blow-up | M×L | Capacitance multiplier or slightly higher PFD current; 2.2 mm die fallback |
| R7 | Zero-IF DC/1/f kills narrowband RX | L×H (mitigated) | Digital low-IF operation (§4.6) is the primary plan, not a fallback; verify image rejection budget in P1 |
| R8 | TX driver stability / ESD C on RF pads | M×M | K-factor over corners with PEX+package model; ESD C budget in tx_fe/rx_fe CACE specs from day one |
| R9 | ngspice/VACASK PN capability gaps for closed-loop PLL | M×M | Hybrid methodology: transistor PN of open-loop blocks + behavioral loop assembly (Kundert-style); Xyce HB cross-check |
| R10 | Schedule: single-designer bandwidth | H×M | Macro granularity invites collaborators (each macro self-contained); digital core is fully parallel work |
| R11 | I2S rate vs host expectations (SoM as slave, clock domains) | L×M | Chip-master-only, integer dividers of TCXO; bench-verify against LinHT SoM early with FPGA mock of the digital core |

---

## 14. Bring-up plan (summary)

- **Eval board**: QFN-32, SMA on RFI/RFO (balun for RFO), 32 MHz TCXO + optional XTAL footprint, FTDI/RPi header for SPI, I2S header pin-compatible with the LinHT SoM, per-rail jumpers + current-sense, ATEST SMA.
- **Test plan mirrors CACE specs**: each datasheet-style parameter measured with the same stimulus philosophy as its simulation testbench. Instruments: spectrum analyzer w/ PN measurement, VNA (S11), RF siggen ×2 (IIP3), audio analyzer via SDR host.
- **Sequence**: supplies/POR → SPI readback (VERSION) → XO/CLK → PLL lock across band (lock map vs FRF) → VCO band map readback → RX chain (gain steps, NF via Y-factor, filter corners, ADC DR) → TX (power, spectrum, ACPR, LO leakage before/after cal) → loopback cals → I2S with LinHT SoM → M17 over-the-air demo.
- **Deliverables**: silicon report, datasheet (from CACE + measurements), errata + rev B scope (LDOs, refinements).

---

## 15. Open decisions (input needed)

| # | Decision | Options | Recommended default |
| --- | --- | --- | --- |
| D1 | Reference frequency | 32 / 36.864 / 38.4 MHz | **32 MHz** (SX1255 ecosystem, clean I2S rates; confirm LinHT board TCXO) |
| D2 | Duplex | half-duplex single PLL vs full-duplex dual PLL | **Half-duplex** (HT use; saves ~0.2 mm² + 15 mA) |
| D3 | TX power | +5 vs +8 dBm sat | **+8 dBm** target, spec +5 min (external PA input level?) |
| D4 | Supplies | external 1.5 V rails vs on-chip LDOs from 3.3 V | **External rails** first silicon; LDOs rev B |
| D5 | Package | QFN-32 vs QFN-48 (more grounds/DIOs) | **QFN-32** (matches template + SX1255 footprint class) |
| D6 | Coverage edges | strict 144–450 vs extended 130–520 (airband RX 118+?) | **130–520 MHz** design target (airband would push to 118 — say no for now) |
| D7 | LNA input Z option | 50 Ω only vs 50/200 Ω selectable | **50 Ω only** (simpler; LinHT front-end is 50 Ω) |
| D8 | VCO cores | 1 octave core vs 2 overlapping cores | decide at M1 with sim data (**lean dual-core**) |
| D9 | Dedicated CLK_OUT pin to SoM | yes (drop a DIO) vs no (BCLK suffices) | **No** — BCLK serves as system clock reference |
| D10 | Shuttle | which IHP open-source MPW / date; die-size seat & cost | research at P0 — schedule anchors to it |

---

## 16. Immediate next steps (first two weeks)

1. Resolve D1–D7 (one review session); freeze §3 numbers into `doc/specifications.md` rev-A.
2. Confirm shuttle options/dates/seat sizes for SG13G2 open-source runs (D10) — this anchors the whole schedule.
3. Scaffold macro directories (`macros/{bias_top,xo_top,vco_top,lodiv_top,pll_top,rx_fe,bb_filter,rx_adc,tx_dac,tx_fe,atest_top,digital_core}/`) from the inverter/counter patterns; wire into `build-macros`.
4. Start `scripts/system_model/`: RX cascade + ΣΔ NTF + PLL PN budget notebooks (P1).
5. Start register map RTL + cocotb SPI testbench (P2 head start — zero analog dependencies).
6. Prototype the 5-rail padframe/PDN on a dummy floorplan (retire R3 early).

---

## 17. Abbreviations

| Abbreviation | Meaning |
| --- | --- |
| ACPR | Adjacent-Channel Power Ratio |
| ADC | Analog-to-Digital Converter |
| AGC | Automatic Gain Control |
| ATEST | Analog test (pin / mux) |
| AVDD/AVSS, DVDD/DVSS, IOVDD/IOVSS | Analog / digital / I/O-ring supply and ground rails |
| BCLK | Bit Clock (I2S) |
| BiCMOS | Bipolar + CMOS process (SG13G2: CMOS + SiGe HBTs) |
| BW | Bandwidth |
| CACE | Circuit Automatic Characterization Engine (open-source spec-driven characterization harness) |
| CDC | Clock-Domain Crossing |
| CDL | Circuit Description Language (netlist format used by KLayout LVS) |
| CI | Continuous Integration |
| CIC | Cascaded Integrator–Comb (multiplierless decimation/interpolation filter) |
| CIFF | Cascade of Integrators, Feed-Forward (ΣΔ loop topology) |
| CML | Current-Mode Logic (high-speed differential logic) |
| CMOS | Complementary Metal-Oxide-Semiconductor |
| CP | Charge Pump (PLL) |
| CSN | Chip Select, active low (SPI) |
| CT ΣΔ | Continuous-Time Sigma-Delta (modulator) |
| DAC | Digital-to-Analog Converter |
| DC | Direct Current (zero frequency / offset) |
| DIO | Digital I/O pin (SX1255-style status/control output) |
| DR | Dynamic Range |
| DRC | Design-Rule Check |
| DSB / SSB | Double- / Single-Sideband bandwidth convention (complex ±f vs per-rail f) |
| DSP | Digital Signal Processing |
| EM | Electromagnetic (simulation) |
| ENOB | Effective Number Of Bits |
| ESD | Electrostatic Discharge |
| EVM | Error Vector Magnitude |
| FF / TT / SS | Fast / typical / slow process corners |
| FIR | Finite Impulse Response (filter) |
| FIR-DAC | Semi-digital DAC: 1-bit stream shifts through an FIR whose taps are analog current weights (DAC + reconstruction filter in one) |
| FM / NBFM | (Narrowband) Frequency Modulation |
| FPGA | Field-Programmable Gate Array |
| FRF | RF-frequency register word (SX1255 naming) |
| FSM | Finite State Machine |
| FTDI | USB-to-SPI/serial bridge (eval-board context) |
| GDS | GDSII layout database format |
| GE / kGE | (kilo-)Gate Equivalent (digital size unit) |
| GL | Gate-Level (post-synthesis simulation) |
| HB | Halfband filter (digital); in simulator context: Harmonic Balance analysis |
| HBM | Human-Body Model (ESD test standard) |
| HBT | Heterojunction Bipolar Transistor (SiGe) |
| HPF | High-Pass Filter |
| HT | Handheld Transceiver ("handy-talkie") |
| HV / LV | High- / Low-Voltage MOS flavors in SG13G2 (3.3 V / 1.5 V) |
| I2S | Inter-IC Sound — 3-wire serial audio/IQ bus (BCLK, WS, data) |
| IHP | The foundry behind SG13G2 (Leibniz-Institut für innovative Mikroelektronik) |
| IIP2 / IIP3 | Input-referred 2nd- / 3rd-order Intercept Point (linearity) |
| IISM | I2S-mode control register (name inherited from SX1255) |
| IQ | In-phase / Quadrature signal pair |
| IRQ | Interrupt Request |
| JKU | Johannes Kepler University Linz (template/flow authors) |
| KVCO | VCO tuning gain (Hz per volt) |
| LC | Inductor–Capacitor (resonant tank) |
| LDO | Low-DropOut voltage regulator |
| LEF / LIB | Library Exchange Format (abstract layout) / Liberty timing views |
| LNA | Low-Noise Amplifier |
| LO | Local Oscillator |
| LPF | Low-Pass Filter |
| LSB / MSB | Least / Most Significant Bit (or Byte) |
| LVDS | Low-Voltage Differential Signaling (not used on this chip) |
| LVS | Layout Versus Schematic check |
| M17 | Open amateur-radio digital-voice protocol (4FSK), primary LinHT mode |
| MANT | Mantissa of the rate-change factor R = MANT·3^m·2^n |
| MASH | Multi-stAge noise SHaping (cascaded ΣΔ modulator, e.g. MASH 1-1-1) |
| MC | Monte-Carlo (mismatch/statistical simulation) |
| MCU | Microcontroller Unit (not present on this chip) |
| MDS | Minimum Detectable Signal |
| MFB | Multiple-FeedBack (active-RC filter topology) |
| MIM | Metal-Insulator-Metal capacitor |
| MISO / MOSI | SPI data lines: Master In Slave Out / Master Out Slave In |
| MMD | Multi-Modulus Divider (PLL feedback divider) |
| MPW | Multi-Project Wafer (shared, low-cost shuttle run) |
| NDR | Non-Default Rule (wider/spaced routing for sensitive nets) |
| NF | Noise Figure |
| NTF | Noise Transfer Function (of a ΣΔ modulator) |
| OSICD | Open-Source IC Design (flow) |
| OSR | OverSampling Ratio |
| OTA | Operational Transconductance Amplifier |
| PA | Power Amplifier (external on LinHT; on-chip block is the PA *driver*) |
| PDK | Process Design Kit |
| PDN | Power Distribution Network |
| PEX | Parasitic EXtraction |
| PFD | Phase-Frequency Detector (PLL) |
| PGA | Programmable-Gain Amplifier |
| PLL | Phase-Locked Loop |
| PN | Phase Noise |
| POR | Power-On Reset |
| PTAT | Proportional To Absolute Temperature (bias current) |
| PVT | Process, Voltage, Temperature (corner space) |
| QFN | Quad Flat No-lead package |
| RC | Resistor–Capacitor (time constant; "RC trim" = tuning it) |
| RF | Radio Frequency |
| RFI / RFO_P / RFO_N | RF input pin / differential RF output pins |
| RMS | Root Mean Square |
| RTL | Register-Transfer Level (synthesizable digital description) |
| RX / TX | Receive / Transmit |
| S11 | Input reflection coefficient (S-parameter; matching quality) |
| S2D | Single-ended-to-Differential converter |
| SCK | SPI clock |
| SDI / SDO | I2S serial data in (TX samples) / out (RX samples) |
| SDM | Sigma-Delta Modulator |
| SDR | Software-Defined Radio |
| SiGe | Silicon-Germanium (HBT material system) |
| SMA | SubMiniature version A coaxial RF connector |
| SNR | Signal-to-Noise Ratio |
| SoM | System-on-Module (LinHT's Linux host computer) |
| SPI | Serial Peripheral Interface (control bus) |
| SQNR | Signal-to-Quantization-Noise Ratio |
| STA | Static Timing Analysis |
| TCXO | Temperature-Compensated Crystal Oscillator |
| TDD | Time-Division Duplex (half-duplex TX/RX switching) |
| TG | Transmission Gate (complementary MOS switch) |
| TIA | TransImpedance Amplifier |
| TM1 / TM2 | TopMetal1 / TopMetal2 (SG13G2 thick top metal layers) |
| VACASK | Verilog-A Circuit Analysis Kernel (open-source simulator: HB, transient noise, …) |
| VCO | Voltage-Controlled Oscillator |
| VHF / UHF | Very / Ultra High Frequency (30–300 MHz / 300–3000 MHz) |
| VNA | Vector Network Analyzer |
| WS | Word Select — I2S frame clock (= sample rate) |
| XO | Crystal Oscillator |
| XSPICE | Code-model extension of SPICE (digital blocks inside analog top-level simulation) |
| XTA / XTB | Crystal/TCXO reference pins |
| ΣΔ | Sigma-Delta (noise-shaping modulation principle) |
