# -*- coding: utf-8 -*-
# SPDX-FileCopyrightText: 2026 TODO
# SPDX-License-Identifier: Apache-2.0 WITH SHL-2.1
# Author: TODO
# Created: July 19, 2026
# Description: Circuit specifications for the pfd macro sizing.
#
# This file is the single input of sizing_pfd.py (`make sizing`) — edit
# the values here, not the sizing script, when the specifications change.
# Constants and trivially derived values only (VCM_IN = VDD / 2 is fine);
# anything touching a pygmid lookup belongs in sizing_pfd.py.
# The whole file is echoed verbatim into the generated report
# scripts/sizing/sizing_pfd.md, so keep the comments meaningful.
# ============================================

# TODO(pll_top): fill in the block specifications from doc/design_plan.md.

VDD = 1.5          # Supply voltage (V)
TEMP = 27          # Nominal temperature (degC)

# Channel length (um): minimum L (0.13) maximizes bandwidth and minimizes
# area, at the cost of gain and mismatch; long L increases gain and matching,
# at the cost of area and bandwidth.
L = 1.0
