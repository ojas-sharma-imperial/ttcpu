module extend (
    input logic clk,
    input logic reset,
    input logic extenden,
    input logic [1:0] shiftopc,
    input logic [3:0] Ra,
    input logic imm1,
    input logic [1:0] imm2,
    output logic [1:0] extension
);

logic [1:0] regX;
logic extactive;

always_comb begin
    extension = regX;
end

always_ff @(posedge clk) begin
    if (reset) begin
        regX <= 2'b00;
        extactive <= 1'b0;
    end else begin // not being reset
        if (extactive) begin
            extactive <= 1'b0;
            regX <= 2'b00;
        end else if (extenden) begin // not being reset, and not currently active - load value
            extactive <= 1'b1;
            case (shiftopc)
                2'b00: regX[0] <= imm1;
                2'b10: regX <= Ra[1:0];
                2'b01: regX <= imm2;
                2'b11: regX <= imm2;
            endcase
        end
    end
end

endmodule
