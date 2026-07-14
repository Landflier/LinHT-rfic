// SPDX-FileCopyrightText: 2026 __DESIGNER__
// SPDX-License-Identifier: Apache-2.0 WITH SHL-2.1
// Description: Shared constants for the __NAME__ macro.
//
// Implemented as `define macros (not a SystemVerilog package) for Yosys
// compatibility — its Verilog frontend cannot parse `import pkg::*;` in a
// module header. Compile constants.sv before any module that references the
// macros (the Makefiles list it first in MODULES_SIM/MODULES_SYNTH).

`ifndef __CELL___CONSTANTS_SV
`define __CELL___CONSTANTS_SV

// Default clock frequency for simulations and testbenches (Hz)
// LinHT_IC runs its digital core at F_XOSC = 32 MHz (doc/design_plan.md §5).
`define CLK_FREQ_DEFAULT      32.0e6

// TODO(__NAME__): add shared design constants here.

`endif
