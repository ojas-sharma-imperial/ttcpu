`include "tt_um_ojas_sharma_imperial_ttcpu.sv"
`include "test_mem_interface.sv"

module testing (
    input logic clk,
    input logic reset,
    output logic [7:0] uio_oe
);

logic [7:0] ui_in;
logic [7:0] uo_out;
logic [7:0] uio_in;
logic [7:0] uio_out;

logic [4:0] ram_addr;
assign ram_addr[4] = uo_out[6];
assign ram_addr[3:0] = uio_out[7:4];

tt_um_ojas_sharma_imperial_ttcpu main_cpu (
    .clk (clk),
    .rst_n (~reset),
    .ena (1'b1),

    .ui_in (ui_in),
    .uo_out (uo_out),
    .uio_in (uio_in),
    .uio_out (uio_out),
    .uio_oe (uio_oe)
);

test_mem_interface #(
    .ROM_INIT_FILE("romdata.mem")
) main_memory (
    .clk          (clk),
    .reset        (reset),
    .ram_addr     (ram_addr),
    .ram_data_in  (uio_out[3:0]),
    .WEN          (uo_out[7]),
    .ram_data_out (uio_in[3:0]),
    .rom_addr     (uo_out[5:0]),
    .rom_data_out (ui_in)
);

endmodule
