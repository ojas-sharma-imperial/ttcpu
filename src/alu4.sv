module alu_decode (
    input logic flagcin,
    input logic [2:0] aluopc,
    output logic invert,
    output logic addsubcin
);

always_comb begin
    case (aluopc)
            3'b000: begin // MOV
                addsubcin = 1'b0;
                invert = 1'b0;
            end
            3'b001: begin // ADD
                addsubcin = 1'b0;
                invert = 1'b0;
            end
            3'b010: begin // SUB
                addsubcin = 1'b1;
                invert = 1'b1;
            end
            3'b011: begin // ADC
                addsubcin = flagcin;
                invert = 1'b0;
            end
            3'b100: begin // SBC
                addsubcin = flagcin;
                invert = 1'b1;
            end
            3'b101: begin // NAND
                addsubcin = 1'b0;
                invert = 1'b0;
            end
            3'b110: begin // CMP
                addsubcin = 1'b1;
                invert = 1'b1;
            end
            3'b111: begin // SHIFTS
                addsubcin = 1'b0;
                invert = 1'b0;
            end
    endcase
end

endmodule

module shift (
    input logic [1:0] shiftcount,
    input logic [1:0] shiftopc,
    input logic [3:0] din,
    input logic shiftin,
    output logic [3:0] dout,
    output logic shiftout
);

logic [3:0] shift1toshift2data;
logic shift1toshift2out;

shift_n #(.SHIFT_COUNT(1)) shift_1 (
    .shiftopc(shiftopc),
    .din(din),
    .shiftin(shiftin),
    .shiftinc(1'b0),
    .en(shiftcount[0]),
    .dout(shift1toshift2data),
    .shiftoutc(shift1toshift2out)
);

shift_n #(.SHIFT_COUNT(2)) shift_2 (
    .shiftopc(shiftopc),
    .din(shift1toshift2data),
    .shiftin(shiftin),
    .shiftinc(shift1toshift2out),
    .en(shiftcount[1]),
    .dout(dout),
    .shiftoutc(shiftout)
);

endmodule

module shift_n #(parameter int SHIFT_COUNT = 1) ( // parameterised barrel shifter, default 1-bit
    input logic [1:0] shiftopc,
    input logic [3:0] din,
    input logic shiftin,
    input logic shiftinc,
    input logic en,
    output logic [3:0] dout,
    output logic shiftoutc
);

logic [3:0] temp;

always_comb begin
    temp = 4'b0000;
    if (en) begin // shift by SHIFT_COUNT
        case (shiftopc)
            2'b00: begin // LSL
                shiftoutc = din[3];
                dout = din << SHIFT_COUNT;
            end
            2'b01: begin // LSR
                shiftoutc = din[SHIFT_COUNT-1];
                dout = din >> SHIFT_COUNT;
            end
            2'b10: begin // ASR
                shiftoutc = din[SHIFT_COUNT-1];
                dout = din >>> SHIFT_COUNT;
            end
            2'b11: begin // XSR
                shiftoutc = din[SHIFT_COUNT-1];
                if (shiftin) begin // shift in 1's
                    temp = ~din;
                    temp = temp >> SHIFT_COUNT;
                    dout = ~temp;
                end else begin // shift in 0's
                    dout = din >> SHIFT_COUNT;
                end
            end
        endcase
    end else begin // pass input to output
        shiftoutc = shiftinc;
        dout = din;
    end
end

endmodule

module addsub (
    input logic [3:0] din1,
    input logic [3:0] din2,
    input carryin,
    input invert,
    output logic [3:0] dout,
    output logic carryout
);

logic [3:0] secondinput;
logic [4:0] adderout;

always_comb begin
    if (invert) begin
        secondinput = ~din2;
    end else begin
        secondinput = din2;
    end

    adderout = din1 + secondinput + carryin;
    dout = adderout[3:0];
    carryout = adderout[4];
end

endmodule

module alu4 (
    input logic [3:0] Ra,
    input logic [3:0] Rb,
    input logic [3:0] imms4,
    input logic [2:0] aluopc,
    input logic [1:0] shiftcount,
    input logic [1:0] shiftopc,
    input op2sel,
    input flagcin,
    output logic [3:0] out,
    output logic flagc
);

// define some internal wires here
logic inverttoaddsub;
logic cintoaddsub;
logic [3:0] secondinput;
logic [3:0] addsubdout;
logic addsubcout;
logic [3:0] shiftdout;
logic shiftcout;

always_comb begin
    if (op2sel) begin // field 2 immediate value
        secondinput = imms4;
    end else begin // field 2 register Rb
        secondinput = Rb;
    end

    if (aluopc == 3'b111) begin // flagc output for shifts
        flagc = shiftcout;
    end else begin // all other flagc outputs
        flagc = addsubcout;
    end

    case (aluopc) // output multiplexer
        3'b000: out = secondinput; // MOV
        3'b001: out = addsubdout; // ADD
        3'b010: out = addsubdout; // SUB
        3'b011: out = addsubdout; // ADC
        3'b100: out = addsubdout; // SBC
        3'b101: out = (Ra ~& secondinput); // NAND
        3'b110: out = addsubdout; // CMP
        3'b111: out = shiftdout; // SHIFTs
    endcase
end

alu_decode decoder (
    .flagcin (flagcin),
    .aluopc (aluopc),
    .invert (inverttoaddsub),
    .addsubcin (cintoaddsub)
);

addsub main_adder (
    .din1 (Ra),
    .din2 (secondinput),
    .invert (inverttoaddsub),
    .carryin (cintoaddsub),
    .dout (addsubdout),
    .carryout (addsubcout)
);

shift mainShifter (
    .shiftcount (shiftcount),
    .shiftopc (shiftopc),
    .din (Rb),
    .shiftin (flagcin),
    .dout (shiftdout),
    .shiftout (shiftcout)
);

endmodule
