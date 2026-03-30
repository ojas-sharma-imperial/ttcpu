/*
 * Copyright (c) 2026 Ojas Sharma
 * SPDX-License-Identifier: Apache-2.0
 */

`default_nettype none
//`include <ttcpu.sv>

module tt_um_ttcpu_ojas_sharma_imperial (
    input  wire [7:0] ui_in,    // Dedicated inputs
    output wire [7:0] uo_out,   // Dedicated outputs
    input  wire [7:0] uio_in,   // IOs: Input path
    output wire [7:0] uio_out,  // IOs: Output path
    output wire [7:0] uio_oe,   // IOs: Enable path (active high: 0=input, 1=output)
    input  wire       ena,      // always 1 when the design is powered, so you can ignore it
    input  wire       clk,      // clock
    input  wire       rst_n     // reset_n - low to reset
);

  wire reset;
  wire [4:0] memaddr;
  wire [3:0] memdout;

  assign reset = ~rst_n;
  assign uio_oe = 8'b11110000;
  assign uo_out[0] = memaddr[4];
  assign uio_out[7:4] = memaddr[3:0];

  ttcpu main_cpu (
    .clk (clk),
    .reset (reset),

    .memdin (uio_in[3:0]),
    .memaddr (memaddr),
    .memdout (memdout),
    .memwen (uo_out[1]),

    .romdin (ui_in),
    .romaddr (uo_out[7:2])
  );

  // List all unused inputs to prevent warnings
  wire _unused = &{uio_out[3:0], uio_in[7:4], ena, 1'b0};

endmodule
