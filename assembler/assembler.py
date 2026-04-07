#!/usr/bin/env python3
"""
Assembler for custom 8-bit ISA.
Reads assembly from <base>.txt, writes binary to <base>.ram

Verilog-confirmed field layout:
  instruction[7:6] = sectionopc
  instruction[6:3] = imms4        (4-bit signed immediate)
  instruction[6:5] = shiftcount   (2-bit shift count)
  instruction[4:3] = shiftopc     (2-bit shift type discriminator)
  instruction[5]   = Ra           (1-bit: A or B)
  instruction[4]   = Rb           (1-bit: A or B)
  instruction[5]   = imm1         (1-bit immediate, EXT1)
  instruction[4:3] = imm2         (2-bit immediate, LDR/STR)
  instruction[5:4] = immc2        (2-bit jump offset)
  instruction[3]   = jumpinv      (jump invert flag)
  instruction[2:1] = jumpopc      (2-bit jump condition)
  instruction[2:0] = aluopc       (3-bit ALU operation)

Registers: only A (0) and B (1) exist — 1 bit each.
"""

import sys
import os
import re


# ---------------------------------------------------------------------------
# Helpers
# ---------------------------------------------------------------------------

def is_register(token: str) -> bool:
    """Return True if token is a valid register name (A or B)."""
    return token.strip().upper() in ('A', 'B')


def parse_register(token: str) -> int:
    """Parse 'A' -> 0, 'B' -> 1"""
    token = token.strip().upper()
    if token == 'A':
        return 0
    elif token == 'B':
        return 1
    else:
        raise ValueError(f"Invalid register '{token}': only A and B exist")


def parse_imm(token: str, bits: int, signed: bool = False) -> int:
    """
    Parse an immediate value (decimal or 0x hex).
    For signed fields, accepts BOTH:
      - Signed representation:   -1, -8, etc.
      - Unsigned representation: 15, 8,  etc.  (raw bit pattern)
    Returns the raw bit pattern in all cases.
    """
    token = token.strip().lstrip('#')
    value = int(token, 0)

    mask = (1 << bits) - 1

    if signed:
        lo_signed   = -(1 << (bits - 1))
        hi_signed   =  (1 << (bits - 1)) - 1
        hi_unsigned =  (1 << bits) - 1

        if lo_signed <= value <= hi_signed:
            return value & mask
        elif 0 <= value <= hi_unsigned:
            return value & mask
        else:
            raise ValueError(
                f"Immediate {value} out of range: "
                f"signed [{lo_signed}, {hi_signed}] or "
                f"unsigned [0, {hi_unsigned}] for {bits} bits"
            )
    else:
        hi = (1 << bits) - 1
        if not (0 <= value <= hi):
            raise ValueError(
                f"Unsigned immediate {value} out of range [0, {hi}] for {bits} bits"
            )
        return value

def parse_immc2(token: str, raw: bool = False) -> int:
    """
    Parse a jump offset.
    Normal (corrected) mapping:
      +2 -> 0b00
      +3 -> 0b01
      -2 -> 0b10
      -3 -> 0b11
    Raw (after EXT instruction): encode directly as 2-bit unsigned value.
      0 -> 0b00
      1 -> 0b01
      2 -> 0b10
      3 -> 0b11
    """
    token = token.strip().lstrip('#')
    value = int(token, 0)

    if raw:
        if not (0 <= value <= 3):
            raise ValueError(
                f"Invalid raw jump offset {value}: must be 0-3 after an EXT instruction"
            )
        return value
    else:
        mapping = {
            2:  0b00,
            3:  0b01,
            -2: 0b10,
            -3: 0b11,
        }
        if value not in mapping:
            raise ValueError(
                f"Invalid jump offset {value}: must be one of -3, -2, 2, 3"
            )
        return mapping[value]

def parse_indirect(token: str):
    """
    Parse '[A]' / '[B]' -> ('reg', 0|1)
    Parse '[#n]'         -> ('imm', n)
    """
    token = token.strip()
    m = re.fullmatch(r'\[(.+)\]', token)
    if not m:
        raise ValueError(f"Expected indirect operand like [A], [B] or [#n], got '{token}'")
    inner = m.group(1).strip()
    if is_register(inner):
        return ('reg', parse_register(inner))
    else:
        return ('imm', parse_imm(inner, 2, signed=False))


# ---------------------------------------------------------------------------
# Encoders  — every function returns an int in [0, 255]
# ---------------------------------------------------------------------------

# --- Section 00: Immediate ALU  (bit7=0, imms4=[6:3], aluopc=[2:0]) --------

ALU_OPC = {
    'MOV':  0b000,
    'ADD':  0b001,
    'SUB':  0b010,
    'ADC':  0b011,
    'SBC':  0b100,
    'NAND': 0b101,
    'CMP':  0b110,
}

def enc_imm_alu(aluopc: int, imms4: int) -> int:
    """
    bit7=0 | imms4[3:0] @ bits[6:3] | aluopc[2:0] @ bits[2:0]
    """
    return (0 << 7) | ((imms4 & 0xF) << 3) | (aluopc & 0x7)


# --- Section 00: Shifts  (bit7=0, shiftcount=[6:5], shiftopc=[4:3], bits[2:0]=111) ---

SHIFT_OPC = {
    'LSL': 0b00,
    'LSR': 0b01,
    'ASR': 0b10,
    'XSR': 0b11,
}

def enc_shift(shiftopc: int, shiftcount: int) -> int:
    """
    bit7=0 | shiftcount[1:0] @ bits[6:5] | shiftopc[1:0] @ bits[4:3] | 111 @ bits[2:0]
    """
    return (0 << 7) | ((shiftcount & 0x3) << 5) | ((shiftopc & 0x3) << 3) | 0b111


# --- Section 10: Register ALU  (bits[7:6]=10, Ra=[5], Rb=[4], aluopc=[2:0]) ---

def enc_reg_alu(aluopc: int, ra: int, rb: int) -> int:
    """
    bits[7:6]=10 | Ra @ bit[5] | Rb @ bit[4] | 0(X) @ bit[3] | aluopc @ bits[2:0]
    """
    return (0b10 << 6) | ((ra & 0x1) << 5) | ((rb & 0x1) << 4) | (0 << 3) | (aluopc & 0x7)


# --- Section 10: EXT1 #IMM1 ------------------------------------------------

def enc_ext1_imm(imm1: int) -> int:
    """
    EXT1 #IMM1
    bits[7:6]=10 | imm1 @ bit[5] | 0 @ bit[4] | 0 @ bit[3] | 111 @ bits[2:0]
    """
    return (0b10 << 6) | ((imm1 & 0x1) << 5) | (0 << 4) | (0 << 3) | 0b111


# --- Section 10: EXT2 Ra ---------------------------------------------------

def enc_ext2_ra(ra: int) -> int:
    """
    EXT2 Ra
    bits[7:6]=10 | Ra @ bit[5] | 1 @ bit[4] | 0 @ bit[3] | 111 @ bits[2:0]
    """
    return (0b10 << 6) | ((ra & 0x1) << 5) | (1 << 4) | (0 << 3) | 0b111


# --- Section 10: EXT2 #IMM2 ------------------------------------------------

def enc_ext2_imm(imm2: int) -> int:
    """
    EXT2 #IMM2
    bits[7:6]=10 | imm2[1:0] @ bits[5:4] | 1 @ bit[3] | 111 @ bits[2:0]
    """
    return (0b10 << 6) | ((imm2 & 0x3) << 4) | (1 << 3) | 0b111


# --- Section 11: LDR/STR with immediate  (imm2=[4:3]) ----------------------

def enc_ldr_imm(ra: int, imm2: int) -> int:
    """
    LDR Ra, [#IMM2]
    bits[7:6]=11 | Ra @ bit[5] | imm2[1:0] @ bits[4:3] | 000 @ bits[2:0]
    """
    return (0b11 << 6) | ((ra & 0x1) << 5) | ((imm2 & 0x3) << 3) | 0b000


def enc_str_imm(ra: int, imm2: int) -> int:
    """
    STR Ra, [#IMM2]
    bits[7:6]=11 | Ra @ bit[5] | imm2[1:0] @ bits[4:3] | 010 @ bits[2:0]
    """
    return (0b11 << 6) | ((ra & 0x1) << 5) | ((imm2 & 0x3) << 3) | 0b010


# --- Section 11: LDR/STR with register  (Rb=[4]) ---------------------------

def enc_ldr_rb(ra: int, rb: int) -> int:
    """
    LDR Ra, [Rb]
    bits[7:6]=11 | Ra @ bit[5] | Rb @ bit[4] | 0(X) @ bit[3] | 100 @ bits[2:0]
    """
    return (0b11 << 6) | ((ra & 0x1) << 5) | ((rb & 0x1) << 4) | (0 << 3) | 0b100


def enc_str_rb(ra: int, rb: int) -> int:
    """
    STR Ra, [Rb]
    bits[7:6]=11 | Ra @ bit[5] | Rb @ bit[4] | 0(X) @ bit[3] | 110 @ bits[2:0]
    """
    return (0b11 << 6) | ((ra & 0x1) << 5) | ((rb & 0x1) << 4) | (0 << 3) | 0b110


# --- Section 11: Jumps by immediate ----------------------------------------
#
#  JMP:  jumpinv=0, jumpopc=00  ->  bits[3:0] = 0_00_1
#  JEQ:  jumpinv=0, jumpopc=01  ->  bits[3:0] = 0_01_1
#  JNE:  jumpinv=1, jumpopc=01  ->  bits[3:0] = 1_01_1
#  JCS:  jumpinv=0, jumpopc=10  ->  bits[3:0] = 0_10_1
#  JCC:  jumpinv=1, jumpopc=10  ->  bits[3:0] = 1_10_1
#  bit0 always 1

JUMP_PARAMS = {          # (jumpinv, jumpopc)
    'JMP': (0, 0b00),
    'JEQ': (0, 0b01),
    'JNE': (1, 0b01),
    'JCS': (0, 0b10),
    'JCC': (1, 0b10),
}

def enc_jump_imm(immc2: int, jumpinv: int, jumpopc: int) -> int:
    """
    bits[7:6]=11 | immc2[1:0] @ bits[5:4] | jumpinv @ bit[3] | jumpopc[1:0] @ bits[2:1] | 1 @ bit[0]
    """
    return (
        (0b11     << 6) |
        ((immc2   & 0x3) << 4) |
        ((jumpinv & 0x1) << 3) |
        ((jumpopc & 0x3) << 1) |
        0b1
    )


# --- Section 11: JSR Ra  ---------------------------------------------------

def enc_jsr(ra: int) -> int:
    """
    JSR Ra
    bits[7:6]=11 | Ra @ bit[5] | 0 @ bit[4] | 0 @ bit[3] | 111 @ bits[2:0]
    Table row: 1 1 Ra 0 0 1 1 1
    """
    return (0b11 << 6) | ((ra & 0x1) << 5) | (0 << 4) | (0 << 3) | 0b111


# --- Section 11: JMP Ra  ---------------------------------------------------

def enc_jump_ra(ra: int) -> int:
    """
    JMP Ra
    bits[7:6]=11 | Ra @ bit[5] | 1 @ bit[4] | 0 @ bit[3] | 111 @ bits[2:0]
    Table row: 1 1 Ra 1 0 1 1 1
    """
    return (0b11 << 6) | ((ra & 0x1) << 5) | (1 << 4) | (0 << 3) | 0b111


# --- Section 11: RET  ------------------------------------------------------

def enc_ret() -> int:
    """
    RET
    bits[7:6]=11 | 0(X) @ bit[5] | 0(X) @ bit[4] | 1 @ bit[3] | 111 @ bits[2:0]
    Table row: 1 1 X X 1 1 1 1  -> 0b11001111 = 0xCF
    """
    return 0b11001111


# ---------------------------------------------------------------------------
# Line assembler
# ---------------------------------------------------------------------------

def assemble_line(line: str, lineno: int, prev_mnemonic: str | None = None) -> int | None:
    """
    Assemble one line. Returns an int (0–255), or None for blank/comment lines.
    prev_mnemonic: the mnemonic of the last assembled instruction (None if first).
    Raises ValueError on any error.
    """
    # Strip inline comments (; or //)
    line = re.split(r'\s*[;]|\s*//', line)[0].strip()
    if not line:
        return None

    tokens = re.split(r'[\s,]+', line)
    tokens = [t for t in tokens if t]
    if not tokens:
        return None

    mnemonic = tokens[0].upper()

    # whether the previous real instruction was an EXT
    after_ext = prev_mnemonic in ('EXT1', 'EXT2')

    # ------------------------------------------------------------------ RET
    if mnemonic == 'RET':
        return enc_ret()

    # ------------------------------------------------------------------ NOP
    if mnemonic == 'NOP':
        return 0b11001001

    # ------------------------------------------------------------------ MRK
    if mnemonic == 'MRK':
        return 0b11011001

    # ------------------------------------------------------------------ JSR
    if mnemonic == 'JSR':
        if len(tokens) < 2:
            raise ValueError(f"Line {lineno}: JSR requires a register operand")
        return enc_jsr(parse_register(tokens[1]))

    # ------------------------------------------------------------------ JMP
    if mnemonic == 'JMP':
        if len(tokens) < 2:
            raise ValueError(f"Line {lineno}: JMP requires an operand")
        if is_register(tokens[1]):
            return enc_jump_ra(parse_register(tokens[1]))
        else:
            immc2 = parse_immc2(tokens[1], raw=after_ext)        # <-- pass raw flag
            inv, opc = JUMP_PARAMS['JMP']
            return enc_jump_imm(immc2, inv, opc)

    # --------------------------------------------------------- Other Jumps
    if mnemonic in JUMP_PARAMS:
        if len(tokens) < 2:
            raise ValueError(f"Line {lineno}: {mnemonic} requires an immediate operand")
        immc2 = parse_immc2(tokens[1], raw=after_ext)            # <-- pass raw flag
        inv, opc = JUMP_PARAMS[mnemonic]
        return enc_jump_imm(immc2, inv, opc)

    # ----------------------------------------------------------------- EXT1
    if mnemonic == 'EXT1':
        if len(tokens) < 2:
            raise ValueError(f"Line {lineno}: EXT1 requires an immediate operand")
        return enc_ext1_imm(parse_imm(tokens[1], 1, signed=False))

    # ----------------------------------------------------------------- EXT2
    if mnemonic == 'EXT2':
        if len(tokens) < 2:
            raise ValueError(f"Line {lineno}: EXT2 requires an operand")
        op = tokens[1]
        if is_register(op):
            return enc_ext2_ra(parse_register(op))
        else:
            return enc_ext2_imm(parse_imm(op, 2, signed=False))

    # --------------------------------------------------------------- Shifts
    if mnemonic in SHIFT_OPC:
        if len(tokens) < 2:
            raise ValueError(f"Line {lineno}: {mnemonic} requires a shift count")
        shiftcount = parse_imm(tokens[1], 2, signed=False)
        return enc_shift(SHIFT_OPC[mnemonic], shiftcount)

    # --------------------------------------------------------------- LDR/STR
    if mnemonic in ('LDR', 'STR'):
        if len(tokens) < 3:
            raise ValueError(f"Line {lineno}: {mnemonic} requires Ra and an address operand")
        ra = parse_register(tokens[1])
        kind, val = parse_indirect(tokens[2])
        if mnemonic == 'LDR':
            return enc_ldr_imm(ra, val) if kind == 'imm' else enc_ldr_rb(ra, val)
        else:
            return enc_str_imm(ra, val) if kind == 'imm' else enc_str_rb(ra, val)

    # ----------------------------------------- ALU: immediate or register form
    if mnemonic in ALU_OPC:
        if len(tokens) < 2:
            raise ValueError(f"Line {lineno}: {mnemonic} requires an immediate or register operand")

        if is_register(tokens[1]) and len(tokens) > 2:
            ra = parse_register(tokens[1])
            rb = parse_register(tokens[2])
            return enc_reg_alu(ALU_OPC[mnemonic], ra, rb)
        else:
            imms4 = parse_imm(tokens[1], 4, signed=True)
            return enc_imm_alu(ALU_OPC[mnemonic], imms4)

    raise ValueError(f"Line {lineno}: Unknown mnemonic '{mnemonic}'")

# ---------------------------------------------------------------------------
# Top-level assembler
# ---------------------------------------------------------------------------

def assemble(input_path: str, output_path: str):
    instructions = []
    errors       = []
    prev_mnemonic = None                                          # <-- track previous mnemonic

    with open(input_path, 'r') as f:
        lines = f.readlines()

    print(f"{'Line':<6} {'Source':<28} {'Hex':<6} {'Binary'}")
    print("-" * 58)

    for lineno, line in enumerate(lines, start=1):
        try:
            result = assemble_line(line, lineno, prev_mnemonic)  # <-- pass prev_mnemonic
            if result is not None:
                instructions.append(result)
                print(f"{lineno:<6} {line.rstrip():<28} "
                      f"0x{result:02X}   {result:08b}")
                # update prev_mnemonic only on successfully assembled instructions
                # strip comments and extract mnemonic
                clean = re.split(r'\s*[;]|\s*//', line)[0].strip()
                if clean:
                    prev_mnemonic = clean.split()[0].upper()     # <-- update after success
        except ValueError as e:
            errors.append(str(e))
            print(f"{'ERROR':<6} {line.rstrip():<28} {e}")

    print("-" * 58)

    if errors:
        print(f"\nAssembly FAILED — {len(errors)} error(s). No output written.")
        sys.exit(1)

    with open(output_path, 'w') as f:
        for instruction in instructions:
            f.write(f"{instruction:08b}\n")

    print(f"\nAssembled {len(instructions)} instruction(s)  ->  '{output_path}'")

# ---------------------------------------------------------------------------
# Entry point
# ---------------------------------------------------------------------------

if __name__ == '__main__':
    base        = sys.argv[1] if len(sys.argv) > 1 else 'code'
    input_file  = base + '.txt'
    output_file = base + '.ram'

    if not os.path.exists(input_file):
        print(f"Error: '{input_file}' not found.")
        sys.exit(1)

    print(f"Assembling '{input_file}'  ->  '{output_file}'\n")
    assemble(input_file, output_file)