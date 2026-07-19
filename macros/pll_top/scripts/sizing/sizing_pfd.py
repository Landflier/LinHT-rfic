# -*- coding: utf-8 -*-
# SPDX-FileCopyrightText: 2026 TODO
# SPDX-License-Identifier: Apache-2.0 WITH SHL-2.1
# Author: TODO
# Created: July 19, 2026
# Description: Analytical (gm/ID) sizing of the pfd macro.
#
# The specifications live in specs_pfd.py — edit that file, not this
# one, when they change; this script holds only the topology-specific gm/ID
# equations. Run from the macro root:
#   make sizing
# which prints the results and writes the committed Markdown report
# scripts/sizing/sizing_pfd.md (specs + computed sizing).
#
# The SG13G2 gm/ID lookup tables (.mat) are shared repo-wide in
# <repo>/scripts/sizing/data/ — do not copy them into the macro.
# See macros/inverter/scripts/sizing/ for a complete, worked example of this
# structure.
# ============================================

# Imports
import sys
from pathlib import Path

import numpy as np

# Shared sizing helpers (Report, load_table, calculate_finger_options)
REPO_ROOT = Path(__file__).resolve().parents[4]
sys.path.insert(0, str(REPO_ROOT / "scripts" / "sizing"))
from sizing_common import Report, load_table

# Specifications (plain-Python constants module next to this script)
sys.path.insert(0, str(Path(__file__).resolve().parent))
import specs_pfd as specs

SPECS_FILE = Path(__file__).resolve().parent / "specs_pfd.py"
REPORT_FILE = Path(__file__).resolve().parent / "sizing_pfd.md"
# ============================================


def main():
    r = Report("pfd", generator=Path(__file__).name)
    r.specs(SPECS_FILE)

    # ============================================
    # Load SG13G2 data tables
    # ============================================
    lv_nmos = load_table("sg13g2_lv_nmos")
    lv_pmos = load_table("sg13g2_lv_pmos")
    # hv_nmos = load_table("sg13g2_hv_nmos")
    # hv_pmos = load_table("sg13g2_hv_pmos")

    # ============================================
    # Sizing
    # ============================================
    # TODO(pll_top): size the devices with gm/ID lookups, e.g.:
    #
    # r.section("NMOS sizing")
    # gm_id = 10                          # chosen inversion level (uS/uA)
    # gm = ...                            # from the small-signal requirement
    # id_w = lv_nmos.lookup("ID_W", GM_ID=gm_id, L=specs.L,
    #                       VDS=specs.VDD / 2, VSB=0)
    # w = (gm / gm_id) / id_w
    # r.value("W", float(w), "um")

    r.text("TODO(pll_top): implement the sizing calculations.")

    r.write(REPORT_FILE)


# Main Execution
if __name__ == "__main__":
    main()
