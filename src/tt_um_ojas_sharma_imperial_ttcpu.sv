/*
 * Copyright (c) 2026 Ojas Sharma
 * SPDX-License-Identifier: Apache-2.0
 */

`default_nettype none
//`include <ttcpu.sv>

module tt_um_ojas_sharma_imperial_ttcpu (
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

  ttcpu main_cpu (
    .clk (clk),
    .reset (reset),

    .memdin (uio_in[3:0]), // INPUT: data from RAM
    .memaddr (memaddr), // OUTPUT: address to ROM
    .memdout (uio_out[3:0]), // OUTPUT: data to RAM
    .memwen (uo_out[7]), // OUTPUT: RAM write-enable

    .romdin (ui_in), // INPUT: data from ROM
    .romaddr (uo_out[5:0]) // OUTPUT: address to ROM
  );

  // dynamically update the values of input pins to match the ttcpu expectation

  assign reset = ~rst_n;

  assign uio_oe[7:4] = 4'b1111;
  assign uio_oe[3:0] = {4{uo_out[7]}};

  // split up the RAM address output to correct pinout

  //assign memaddr[4] = uo_out[6];
  //assign memaddr[3:0] = uio_out[7:4];

  assign uo_out[6] = memaddr[4];
  assign uio_out[7:4] = memaddr[3:0];

  // set unused pins to respective constant values

  //assign uio_in[7:4] = 4'b0;

  // List all unused inputs to prevent warnings
  wire _unused = &{uio_in[7:4], ena, 1'b0};

endmodule
