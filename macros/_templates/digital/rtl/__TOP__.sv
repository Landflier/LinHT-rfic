// SPDX-FileCopyrightText: 2026 __DESIGNER__
// SPDX-License-Identifier: Apache-2.0 WITH SHL-2.1
// Description: Top-level wrapper module of the __NAME__ macro.
//
// The wrapper owns the hardening-facing interface (reset polarity, port
// naming) so the core module stays testbench-friendly.

`default_nettype none
`ifndef __TOP___SV
`define __TOP___SV

module __TOP__ (
  input  logic clock_i,
  input  logic reset_n_i,
  input  logic enable_i,

  output logic tick_o
);

  // Internal active-high reset (wrapper handles polarity conversion)
  logic reset;
  assign reset = ~reset_n_i;

  // Embed core module
  __CELL__ __CELL___0 (
    .clock_i (clock_i),
    .reset_i (reset),
    .enable_i(enable_i),
    .tick_o  (tick_o)
  );

endmodule // __TOP__

`endif
`default_nettype wire
