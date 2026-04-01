module regfile (
    input logic clk,
    input logic reset,
    input logic ad1,
    input logic ad2,
    input logic wen1,
    input logic [3:0] din1,
    output logic [3:0] dout1,
    output logic [3:0] dout2
);

logic [3:0] regA;
logic [3:0] regB;

always_ff @(posedge clk) begin
    if (reset) begin
        regA <= 4'b0000;
        regB <= 4'b0000;
    end else begin
        if (wen1) begin
            case (ad1)
                1'b0: regA <= din1;
                1'b1: regB <= din1;
            endcase
        end
    end
end

always_comb begin
    case (ad1)
        1'b0: dout1 = regA;
        1'b1: dout1 = regB;
    endcase

    case (ad2)
        1'b0: dout2 = regA;
        1'b1: dout2 = regB;
    endcase
end

endmodule
