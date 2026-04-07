//`include "controldecode.sv"
//`include "cond.sv"

module controlpath (
    input logic clk,
    input logic reset,

    input logic flagzin,
    input logic flagcin,
    input logic [3:0] Ra,
    input logic [1:0] addr_extension,
    input logic [7:0] romdin,
    input logic extactive,

    output logic [5:0] romaddr,
    output logic [7:0] instruction,
    output logic flagcout
);

// define state hardware

logic flagc;
logic flagz;
logic [5:0] pc;
logic [5:0] pcx;

// define internal signals

logic jump_taken;
logic [5:0] destination;
logic saveaddress;
logic jumpen;
logic flagcwen;
logic flagzwen;
logic [1:0] immc2;
logic jumpinv;
logic [1:0] jumpopc;

cond jump_conditions (
    .flagz (flagz),
    .flagc (flagc),
    .jumpen (jumpen),
    .jumpopc (jumpopc),
    .jumpinv (jumpinv),
    .immc2 (immc2),
    .Ra (Ra),
    .addr_extension (addr_extension),
    .pcin (pc),
    .pcxin (pcx),
    .jump (jump_taken),
    .destination (destination),
    .saveadress (saveaddress),
    .extended_select(instruction[4]),
    .extend_active (extactive)
);

controldecode controlpath_decode (
    .instruction (romdin),
    .jumpen (jumpen),
    .flagcwen (flagcwen),
    .flagzwen (flagzwen),
    .immc2 (immc2),
    .jumpinv (jumpinv),
    .jumpopc (jumpopc)
);

always_ff @(posedge clk) begin
    if (reset) begin
        flagc <= 1'b0;
        flagz <= 1'b0;
        pc <= 6'b000000;
        pcx <= 6'b000000;
    end else begin
        if (jump_taken) begin // jump to destination
            pc <= destination;
        end else begin // no jump taken, iterate pc
            pc <= pc + 1;
        end

        if (saveaddress) begin // update pcx when saveaddress needed
            pcx <= pc + 1;
        end

        if (flagcwen) begin // update flagc
            flagc <= flagcin;
        end

        if (flagzwen) begin // update flagz
            flagz <= flagzin;
        end
    end
end

always_comb begin
    romaddr = pc;
    instruction = romdin;
    flagcout = flagc;
end

endmodule
