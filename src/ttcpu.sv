//`include "controlpath.sv"
//`include "datapath.sv"

module ttcpu (
    input logic clk,
    input logic reset,

    input logic [3:0] memdin,
    output logic [4:0] memaddr,
    output logic [3:0] memdout,
    output logic memwen,

    input logic [7:0] romdin,
    output logic [6:0] romaddr
);

logic [7:0] instruction;
logic flagctocp;
logic flagztocp;
logic flagctoalu;
logic [2:0] address_extension;
logic [3:0] Ratocp;

datapath main_datapath (
    .clk (clk),
    .reset (reset),
    .instruction (instruction),
    .flagcin (flagctoalu),
    .flagc (flagctocp),
    .flagz (flagztocp),
    .memwen (memwen),
    .addr_extension (address_extension),
    .memaddr (memaddr),
    .memdin (memdin),
    .memdout (memdout),
    .Raout (Ratocp)
);

controlpath main_controlpath (
    .clk (clk),
    .reset (reset),
    .flagcin (flagctocp),
    .flagzin (flagztocp),
    .Ra (Ratocp),
    .addr_extension (address_extension),
    .romdin (romdin),
    .romaddr (romaddr),
    .instruction (instruction),
    .flagcout (flagctoalu)
);

endmodule
