# -*- coding: utf-8 -*-
# SPDX-FileCopyrightText: 2026 Simon Dorrer and Harald Pretl
# SPDX-License-Identifier: Apache-2.0 WITH SHL-2.1
# Description: Circuit specifications for the inverter macro sizing.
#
# This file is the single input of sizing_inverter.py (`make sizing`) — edit
# the values here, not the sizing script, when the specifications change.
# Constants and trivially derived values only (VCM_IN = VDD / 2 is fine);
# anything touching a pygmid lookup belongs in sizing_inverter.py.
# The whole file is echoed verbatim into the generated report
# scripts/sizing/sizing_inverter.md, so keep the comments meaningful.
# ============================================

VDD = 1.5             # Supply voltage (V)
VCM_IN = VDD / 2      # Input common-mode voltage (V)
VCM_OUT = VDD / 2     # Output common-mode voltage (V)
I_OUT = 1.5e-3 / 2    # Output current (A)
C_LOAD = 10e-12       # Load capacitance (F)

# Channel length (um), PMOS and NMOS share the same length:
#   0.13 - minimum: maximizes bandwidth, minimizes area, but worst mismatch
#          and lowest gain
#   0.5  - tradeoff between gain, bandwidth, area, and mismatch
#   1.0  - reduces mismatch and increases gain, but larger area and lower
#          bandwidth
L = 1.0

# Finger configuration option (1-based index into the "Finger configuration
# options" table printed by `make sizing` — pick from that table, set the
# number here, and re-run to size with it).
FINGER_OPTION = 4
