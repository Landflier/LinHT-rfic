# -*- coding: utf-8 -*-
# SPDX-FileCopyrightText: 2026 TODO
# SPDX-License-Identifier: Apache-2.0 WITH SHL-2.1
# Author: TODO
# Created: July 17, 2026
# Description: Circuit specifications for the pll macro sizing.
#
# This file is the single input of sizing_pll.py (`make sizing`) — edit
# the values here, not the sizing script, when the specifications change.
# Constants and trivially derived values only (VCM_IN = VDD / 2 is fine);
# anything touching a pygmid lookup belongs in sizing_pll.py.
# The whole file is echoed verbatim into the generated report
# scripts/sizing/sizing_pll.md, so keep the comments meaningful.
# ============================================

# Block envelope from doc/design_plan.md §3 (target specs), §4.3 (frequency
# plan) and §6.5 (block plan). Loop-parameter derivation (I_CP, R1, C1, C2,
# R3, C3, zeta, omega_n) belongs in sizing_pll.py, not here.

VDD = 1.5          # Supply voltage (V)
TEMP = 27          # Nominal temperature (degC)

# Channel length (um): minimum L (0.13) maximizes bandwidth and minimizes
# area, at the cost of gain and mismatch; long L increases gain and matching,
# at the cost of area and bandwidth.
L = 1.0

# ============================================
# Reference and frequency plan (§4.3)
# ============================================
F_XOSC = 32e6              # PFD/CP comparison frequency (Hz), = reference
F_VCO_MIN = 2.08e9         # VCO tuning range (Hz), one octave
F_VCO_MAX = 4.16e9
N_MIN = 65                 # Multi-modulus divider range (VCO / F_XOSC)
N_MAX = 130
LO_DIV = (8, 16)           # VCO-to-RF divider select (÷8: 260–520 MHz, ÷16: 130–260 MHz)
F_STEP = F_XOSC / 2**20    # Synthesizer step at RF (Hz), SX1255 semantics (~30.5 Hz)
SDM_BITS = 20              # MASH 1-1-1 fractional word width (SDM is in digital_core)

# ============================================
# Loop dynamics (§4.3)
# ============================================
F_BW_MIN = 75e3            # Programmable closed-loop bandwidth range (Hz),
F_BW_MAX = 300e3           # SX1255 semantics; pll_bw[1:0] register
T_TURNAROUND = 150e-6      # TDD TX/RX turnaround budget (s), §3 — PLL settling
                           # to within F_STEP must fit inside it at F_BW_MIN

# ============================================
# Phase noise and jitter targets, referred to RF (§3)
# ============================================
# RF = VCO / LO_DIV; dividing by 8 (16) subtracts 18 (24) dB from VCO-referred
# phase noise. In-band floor is set by ref/PFD/CP/SDM noise ×N².
PN_RF_25K = -100.0         # Phase noise at 25 kHz offset (dBc/Hz), in-band
PN_RF_1M = -128.0          # Phase noise at 1 MHz offset (dBc/Hz), VCO-dominated
PN_INBAND_FLOOR = -95.0    # In-band PLL floor at RF (dBc/Hz), target −95…−100
JITTER_RMS_DEG = 1.0       # Integrated phase error (deg RMS), 500 Hz – 125 kHz

# ============================================
# Spurs and charge pump (§6.5)
# ============================================
SPUR_DBC = -60.0           # Reference and fractional spurs (dBc), worst channel
CP_MISMATCH = 0.02         # CP up/down current mismatch budget (fraction)

# ============================================
# Loop filter (§4.3, §8 area budget)
# ============================================
# Integrated 3rd-order passive filter; capacitance-multiplier fallback if the
# MIM area explodes (§6.5 "LF area" risk).
LF_C_BUDGET = 300e-12      # Total MIM capacitance budget (F), ~100–300 pF

# ============================================
# Assumed VCO parameters (inputs from vco_top, §6.3 — budgetary until
# vco_top sizing fixes them; revisit after D8 (1 vs 2 cores) is decided)
# ============================================
K_VCO = None               # TODO(pll_top): assumed VCO gain (Hz/V) per band
PN_VCO_1M = -110.0         # Free-running VCO phase noise at 1 MHz (dBc/Hz),
                           # at 3.6 GHz carrier
