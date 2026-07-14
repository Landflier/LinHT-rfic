// SPDX-FileCopyrightText: 2026 __DESIGNER__
// SPDX-License-Identifier: Apache-2.0 WITH SHL-2.1
// Description: SystemVerilog testbench for the __TOP__ module.
//
// TODO(__NAME__): replace the placeholder smoke test with real tests.

`timescale 1ns / 1ps

module __TOP___tb;
  // Parameters
  parameter  real CLK_FREQ      = `CLK_FREQ_DEFAULT;
  localparam real CLK_PERIOD_NS = 1e9 / CLK_FREQ;

  // Signals
  logic clock   = 1'b0;
  logic reset_n = 1'b1; // active-low reset
  logic enable  = 1'b0;
  logic tick;

  // DUT
  __TOP__ dut___CELL__ (
    .clock_i(clock),
    .reset_n_i(reset_n),
    .enable_i(enable),
    .tick_o(tick)
  );

  // Clock generation
  /* verilator lint_off STMTDLY */
  always #(CLK_PERIOD_NS / 2) clock = ~clock;
  /* verilator lint_on STMTDLY */

  // Self-checking stimulus
  initial begin
    $dumpfile("__TOP___tb.vcd");
    $dumpvars;

    // Reset pulse (2 clock cycles)
    reset_n = 1'b0;
    #(2 * CLK_PERIOD_NS);
    reset_n = 1'b1;
    #(CLK_PERIOD_NS);

    if (tick !== 1'b0)
      $fatal(1, "FAIL: tick_o not zero after reset (got %0b)", tick);

    // Hold disabled for a few cycles; value must not change
    #(5 * CLK_PERIOD_NS);
    if (tick !== 1'b0)
      $fatal(1, "FAIL: tick_o changed while disabled (got %0b)", tick);

    // Enable and observe the heartbeat
    enable = 1'b1;
    #(10 * CLK_PERIOD_NS);
    enable = 1'b0;
    #(2 * CLK_PERIOD_NS);

    $display("PASS: simulation complete.");
    $finish;
  end
endmodule // __TOP___tb
