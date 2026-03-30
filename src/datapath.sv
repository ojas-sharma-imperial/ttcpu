//`include "dpdecode.sv"
//`include "extend.sv"
//`include "regfile.sv"
//`include "alu4.sv"

module datapath (
    input logic clk,
    input logic reset,
    input logic [7:0] instruction,
    input logic flagcin,

    output logic flagc,
    output logic flagz,
    output logic memwen,
    output logic [1:0] addr_extension,

    output logic [4:0] memaddr,
    input logic [3:0] memdin,
    output logic [3:0] memdout,
    output logic [3:0] Raout
);

logic ad1toregfile;
logic ad2toregfile;
logic wen1toregfile;
logic [3:0] din1toalu;
logic [3:0] din2toalu;
logic [3:0] regfiledin;
logic [3:0] general_data;
logic [3:0] aludout;

logic [1:0] sectionopc;
logic [2:0] aluopc;
logic [3:0] imms4;
logic [1:0] shiftcount;
logic [1:0] shiftopc;
logic imm1;
logic [1:0] imm2;
logic [1:0] immc2;
logic jumpinv;
logic [1:0] jumpopc;
logic aluen;
logic shiften;
logic extenden;
logic op2sel;
logic jumpen;
logic memldr;
logic memstr;

dpdecode datapath_decode (
    .instruction (instruction),
    .sectionopc (sectionopc),
    .aluopc (aluopc),
    .imms4 (imms4),
    .shiftcount (shiftcount),
    .shiftopc (shiftopc),
    .Ra (ad1toregfile),
    .Rb (ad2toregfile),
    .imm1 (imm1),
    .imm2 (imm2),
    .immc2 (immc2),
    .jumpinv (jumpinv),
    .jumpopc (jumpopc),
    .aluen (aluen),
    .shiften (shiften),
    .extenden (extenden),
    .wen1 (wen1toregfile),
    .op2sel (op2sel),
    .jumpen (jumpen),
    .memldr (memldr),
    .memstr (memstr)
);

regfile main_registers (
    .clk (clk),
    .reset (reset),
    .ad1 (ad1toregfile),
    .ad2 (ad2toregfile),
    .wen1 (wen1toregfile),
    .din1 (regfiledin),
    .dout1 (din1toalu),
    .dout2 (din2toalu)
);

alu4 main_alu (
    .Ra (din1toalu),
    .Rb (din2toalu),
    .imms4 (imms4),
    .aluopc (aluopc),
    .shiftcount (shiftcount),
    .shiftopc (shiftopc),
    .op2sel (op2sel),
    .flagcin (flagcin),
    .out (aludout), // temporarily :)
    .flagc (flagc)
);

extend addr_ext (
    .clk (clk),
    .reset (reset),
    .extenden (extenden),
    .shiftopc (shiftopc),
    .Ra (din1toalu),
    .imm1 (imm1),
    .imm2(immc2),
    .extension (addr_extension)
);

always_comb begin
    memwen = memstr;
    memdout = din1toalu;
    Raout = din1toalu;
    case (aluopc[2]) // memory address output
        1'b0: begin // imm2, no extension
            memaddr[4:2] = 3'b000;
            memaddr[1:0] = imm2;
        end
        1'b1: begin // field Rb, with extension
            memaddr[4] = addr_extension[0];
            memaddr[3:0] = din2toalu;
        end
    endcase

    if (memldr) begin // data load from memory or from ALU output?
        general_data = memdin;
    end else begin
        general_data = aludout;
    end

    case (general_data) // set flagz on any data inputted in the general_data stream - LDR and ALU output
        4'b0000: flagz = 1;
        default: flagz = 0;
    endcase

    regfiledin = general_data;
end

endmodule
