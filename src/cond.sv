module cond (
    input logic flagz,
    input logic flagc,
    input logic jumpen,
    input logic [1:0] jumpopc,
    input logic jumpinv,
    input logic [1:0] immc2,
    input logic [3:0] Ra,
    input logic [1:0] addr_extension,
    input logic [5:0] pcin,
    input logic [5:0] pcxin,
    input logic extended_select,
    input logic extend_active,

    output logic jump,
    output logic [5:0] destination,
    output logic saveadress
);

logic [5:0] offset;
logic [5:0] extended_reg;
logic [5:0] extended_offset;

always_comb begin
    saveadress = 1'b0;
    jump = 1'b0;
    destination = 6'b000000;

    case (immc2) // correct for immc2 weirdness
        2'b00: offset = 6'b000010; // +2
        2'b01: offset = 6'b000011; // +3
        2'b10: offset = 6'b111110; // -2
        2'b11: offset = 6'b111101; // -3
    endcase

    extended_reg[3:0] = Ra;
    extended_reg[5:4] = addr_extension;

    extended_offset = {{2{addr_extension[1]}}, addr_extension, immc2};

    if (jumpen) begin
        saveadress = 1'b0;
        case (jumpopc)
            2'b00: begin // JMP/NOP
                if (jumpinv) begin // NOP
                    if (extended_select) begin // MRK
                        jump = 1'b0;
                        saveadress = 1'b1;
                    end else begin // NOP
                        jump = 1'b0;
                    end
                end else begin // JMP
                    jump = 1'b1;
                    if (extend_active) begin
                        destination = pcin + extended_offset;
                    end else begin
                        destination = pcin + offset;
                    end
                end
            end
            2'b01: begin // JEQ/JNE
                if (jumpinv) begin // JNE
                    jump = ~flagz;
                    if (extend_active) begin
                        destination = pcin + extended_offset;
                    end else begin
                        destination = pcin + offset;
                    end
                end else begin // JEQ
                    jump = flagz;
                    if (extend_active) begin
                        destination = pcin + extended_offset;
                    end else begin
                        destination = pcin + offset;
                    end
                end
            end
            2'b10: begin // JCS/JCC
                if (jumpinv) begin // JCC
                    jump = ~flagc;
                    if (extend_active) begin
                        destination = pcin + extended_offset;
                    end else begin
                        destination = pcin + offset;
                    end
                end else begin // JCS
                    jump = flagc;
                    if (extend_active) begin
                        destination = pcin + extended_offset;
                    end else begin
                        destination = pcin + offset;
                    end
                end
            end
            2'b11: begin // JSR/RET
                if (jumpinv) begin // RET
                    jump = 1'b1;
                    destination = pcxin;
                end else begin // JSR or computed jump
                    if (extended_select) begin // register jump
                        jump = 1'b1;
                        destination = extended_reg;
                        saveadress = 1'b0;
                    end else begin // JSR
                        jump = 1'b1;
                        destination = extended_reg;
                        saveadress = 1'b1;
                    end
                end
            end
        endcase
    end else begin
        jump = 1'b0;
    end
end

endmodule
