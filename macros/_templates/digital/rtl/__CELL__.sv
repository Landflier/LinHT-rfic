// SPDX-FileCopyrightText: 2026 __DESIGNER__
// SPDX-License-Identifier: Apache-2.0 WITH SHL-2.1
// Description: Core module of the __NAME__ macro.
//
// TODO(__NAME__): replace the placeholder heartbeat register with the real
// design. The placeholder keeps the lint/sim/hardening flow runnable from
// day one.

`default_nettype none
`ifndef __CELL___SV
`define __CELL___SV

module __CELL__ (
  input  logic clock_i,
  input  logic reset_i,   // active-high (wrapper converts polarity)
  input  logic enable_i,

  output logic tick_o
);

  always_ff @(posedge clock_i) begin
    if (reset_i)
      tick_o <= 1'b0;
    else if (enable_i)
      tick_o <= ~tick_o;
  end

endmodule // __CELL__

`endif
`default_nettype wire
