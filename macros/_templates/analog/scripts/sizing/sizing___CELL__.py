# -*- coding: utf-8 -*-
# SPDX-FileCopyrightText: 2026 __DESIGNER__
# SPDX-License-Identifier: Apache-2.0 WITH SHL-2.1
# Author: __DESIGNER__
# Created: __DATE__
# Description: Analytical (gm/ID) sizing of the __CELL__ macro.
#
# Plain Python script (no Jupyter server needed). Run from this directory:
#   python3 sizing___CELL__.py
# or from the macro root:
#   make sizing
#
# The SG13G2 gm/ID lookup tables (.mat) are shared repo-wide in
# <repo>/scripts/sizing/data/ — do not copy them into the macro.
# See macros/inverter/scripts/sizing/sizing_inverter.py for a complete,
# worked example of this script structure.
# ============================================

# Imports
from pathlib import Path

import numpy as np
from pygmid import Lookup as lk

# Shared SG13G2 lookup tables (generated with the pygmid techsweep flow)
DATA_DIR = Path(__file__).resolve().parents[4] / "scripts" / "sizing" / "data"
# ============================================


# ============================================
# Specifications
# ============================================
# TODO(__NAME__): fill in the block specifications from doc/design_plan.md.
VDD = 1.5        # Supply voltage (V)
temp = 27        # Nominal temperature (degC)
# l = 0.13       # Channel length (um): minimum L maximizes bandwidth, at the
#                # cost of gain and mismatch
l = 1.0          # Channel length (um)

print("=" * 60)
print("__CELL__ - Specifications:")
print("=" * 60)
print(f"Supply Voltage (VDD):          {VDD} V")
print(f"Transistor Length (L):         {l} µm")
print("=" * 60)


# ============================================
# Load SG13G2 Data Tables
# ============================================
lv_nmos = lk(str(DATA_DIR / "sg13g2_lv_nmos.mat"))
lv_pmos = lk(str(DATA_DIR / "sg13g2_lv_pmos.mat"))
# hv_nmos = lk(str(DATA_DIR / "sg13g2_hv_nmos.mat"))
# hv_pmos = lk(str(DATA_DIR / "sg13g2_hv_pmos.mat"))
# List of parameters: VGS, VDS, VSB, L, W, NFING, ID, VT, GM, GMB, GDS, CGG,
# CGB, CGD, CGS, CDD, CSS, STH, SFL.
# If not specified: minimum L, VDS = max(vgs)/2 = 0.75 V and VSB = 0 are used.
# See macros/inverter/scripts/sizing/lookup_commands.py for a tour of the
# pygmid lookup API.


# ============================================
# Sizing
# ============================================
# TODO(__NAME__): size the devices with gm/ID lookups, e.g.:
#
# gm_id = 10                          # chosen inversion level (uS/uA)
# gm = ...                            # from the small-signal requirement
# id_w = lv_nmos.lookup("ID_W", GM_ID=gm_id, L=l, VDS=VDD/2, VSB=0)
# w = (gm / gm_id) / id_w
# print(f"W = {float(w):.2f} um")

print("TODO(__NAME__): implement the sizing calculations.")
