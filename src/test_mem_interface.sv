// =============================================================
//  mem_interface.sv
//  Simulated RAM + ROM interface for CPU pinout testing.
//
//  RAM:  4-bit data, 5-bit address (32 locations), WEN pin
//  ROM:  8-bit data, 6-bit address (64 locations), read-only
//        Loaded from a.mem hex file at simulation start.
// =============================================================

module test_mem_interface #(
    parameter ROM_INIT_FILE = "program.mem"
)(
    // ── Global ────────────────────────────────────────────────
    input  logic        clk,
    input  logic        reset,

    // ── RAM Interface ─────────────────────────────────────────
    input  logic [4:0]  ram_addr,
    input  logic [3:0]  ram_data_in,
    input  logic        WEN,
    output logic [3:0]  ram_data_out,

    // ── ROM Interface ─────────────────────────────────────────
    input  logic [5:0]  rom_addr,       // 6-bit address (64 locations)
    output logic [7:0]  rom_data_out
);

    // ── Memory Arrays ─────────────────────────────────────────

    // RAM: 32 locations × 4 bits
    logic [3:0] ram_mem [0:31];

    // ROM: 64 locations × 8 bits
    logic [7:0] rom_mem [0:63];

    // ── ROM Initialisation ────────────────────────────────────
    initial begin
        if (ROM_INIT_FILE != "") begin
            $display("[mem_interface] Loading ROM from: %s", ROM_INIT_FILE);
            $readmemh(ROM_INIT_FILE, rom_mem);
            $display("[mem_interface] ROM load complete.");
        end else begin
            $display("[mem_interface] WARNING: No ROM file specified. ROM will be uninitialised.");
        end
    end

    // ── RAM: Synchronous Write, Asynchronous Read ─────────────
    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            integer i;
            for (i = 0; i < 32; i = i + 1)
                ram_mem[i] <= 4'h0;
        end else begin
            if (WEN) begin
                ram_mem[ram_addr] <= ram_data_in;
            end
        end
    end

    assign ram_data_out = ram_mem[ram_addr];

    // ── ROM: Asynchronous Read (read-only) ────────────────────
    assign rom_data_out = rom_mem[rom_addr];

endmodule
