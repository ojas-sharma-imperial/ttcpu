# ttcpu ISA

This file outlines the exact (custom) instruction set architecture defined for the ttcpu, as well as how to assemble code for the ttcpu.

## Design Philosophy

The goal of ttcpu was to create a computationally-sufficient RISC CPU architecture. We define computationally-sufficient as having enough instructions such that general programmatic concepts (such as if/else, while, for statements) can all be implemented in a meaningful way, allowing general-purpose computer programs to be loaded and executed.

The RISC architecture requires more information to be defined in the instruction than CISC, with all instructions taking exactly 1 clock cycle to occur. Hence the 8-bit instruction word has been designed around being able to load full 4-bit immeditate values without any sign-extending of smaller inputs.

## Design Overview

### Accumulator Registers

The ttcpu contains two main 'accumulator' registers, named A and B, both 4-bit registers. All instructions can occur on register A, whereas operations concerning immediate values or shifts can only occur on register A (due to instruction word size constraints).

### Program Counters

The ttcpu also contains two 6-bit registers, PC and PCX. PC (program counter) stores the address of the instruction currently being executed, and can be modified through the use of jump instructions (along with extend instructions). PCX (subroutine program counter) allows native non-nested subroutines to be implemented, allowing for the ttcpu to return to the base program after a subroutine is complete automatically upon a RET (return) instruction.

### Flags

The ttcpu has two flags:

- FlagZ (zero flag)
- FlagC (carry flag)

FlagZ is written to by all ALU instructions, as well as memory load instructions. The value of FlagZ is 1 only if the data value is exactly equal to 0. FlagZ has an associated jump instruction JEQ/JNE.

FlagC is written to by all ALU instructions except MOV and NAND. The value of FlagC is 1 if the full adder/subtracter in the ALU has a MSB carry-out or, in the case of shifts, the value of the bit last shifted out. FlagC has an associated jump instruction JCS/JCC.

## Instruction Set Architecture

The ISA is defined in the tables below, as well as in ![](isa.png):

> **Key:** `X` = don't care (ideally set to zero), `#IMM` = immediate value, `Ra`/`Rb` = register select

---

### Immediate Operations (Bit 7 = 0)

| Instruction     | 7 | 6—3      | 2 | 1 | 0 |
|-----------------|---|----------|---|---|---|
| MOV A, #IMM     | 0 | #IMMS4   | 0 | 0 | 0 |
| ADD A, #IMM     | 0 | #IMMS4   | 0 | 0 | 1 |
| SUB A, #IMM     | 0 | #IMMS4   | 0 | 1 | 0 |
| ADC A, #IMM     | 0 | #IMMS4   | 0 | 1 | 1 |
| SBC A, #IMM     | 0 | #IMMS4   | 1 | 0 | 0 |
| NAND A, #IMM    | 0 | #IMMS4   | 1 | 0 | 1 |
| CMP A, #IMM     | 0 | #IMMS4   | 1 | 1 | 0 |

---

### Shift Operations (Bit 7 = 0, Bits 1—0 = 11)

| Instruction      | 7 | 6—4      | 3 | 2 | 1 | 0 |
|------------------|---|----------|---|---|---|---|
| LSL A, #SHIFTCNT | 0 | #SHIFTCNT| 0 | 0 | 1 | 1 |
| LSR A, #SHIFTCNT | 0 | #SHIFTCNT| 0 | 1 | 1 | 1 |
| ASR A, #SHIFTCNT | 0 | #SHIFTCNT| 1 | 0 | 1 | 1 |
| XSR A, #SHIFTCNT | 0 | #SHIFTCNT| 1 | 1 | 1 | 1 |

---

### Register Operations (Bits 7—6 = 10)

| Instruction  | 7 | 6 | 5—4 | 3—2 | 1 | 0 |
|--------------|---|---|-----|-----|---|---|
| MOV Ra, Rb   | 1 | 0 | Ra  | Rb  | 0 | 0 |
| ADD Ra, Rb   | 1 | 0 | Ra  | Rb  | 0 | 1 |
| SUB Ra, Rb   | 1 | 0 | Ra  | Rb  | 1 | 0 |
| ADC Ra, Rb   | 1 | 0 | Ra  | Rb  | 1 | 1 |
| SBC Ra, Rb   | 1 | 0 | Ra  | Rb  | 0 | 0 |
| NAND Ra, Rb  | 1 | 0 | Ra  | Rb  | 0 | 1 |
| CMP Ra, Rb   | 1 | 0 | Ra  | Rb  | 1 | 0 |
| EXT1 #IMM1   | 1 | 0 | #IMM1 | 0 | 1 | 1 |
| EXT2 Ra      | 1 | 0 | Ra  | 1   | 1 | 1 |
| EXT2 #IMM2   | 1 | 0 | #IMM2   | 1 | 1 | 1 |

---

### Memory Operations (Bits 7—6 = 11)

| Instruction    | 7 | 6 | 5—4 | 3—2   | 1 | 0 |
|----------------|---|---|-----|-------|---|---|
| LDR Ra, [#IMM2]| 1 | 1 | Ra  | #IMM2 | 0 | 0 |
| LDR Ra, [Rb]   | 1 | 1 | Ra  | Rb    | 0 | 0 |
| STR Ra, [#IMM2]| 1 | 1 | Ra  | #IMM2 | 1 | 0 |
| STR Ra, [Rb]   | 1 | 1 | Ra  | Rb    | 1 | 0 |

---

### Control Flow (Bits 7—6 = 11)

| Instruction | 7 | 6 | 5—4    | 3 | 2 | 1 | 0 |
|-------------|---|---|--------|---|---|---|---|
| JMP #IMMC2  | 1 | 1 | #IMMC2 | 0 | 0 | 0 | 1 |
| NOP         | 1 | 1 | X      | 1 | 0 | 0 | 1 |
| JEQ #IMMC2  | 1 | 1 | #IMMC2 | 0 | 0 | 1 | 1 |
| JNE #IMMC2  | 1 | 1 | #IMMC2 | 1 | 0 | 1 | 1 |
| JCS #IMMC2  | 1 | 1 | #IMMC2 | 0 | 1 | 0 | 1 |
| JCC #IMMC2  | 1 | 1 | #IMMC2 | 1 | 1 | 0 | 1 |
| JSR Ra      | 1 | 1 | Ra     | 0 | 1 | 1 | 1 |
| RET         | 1 | 1 | X      | 1 | 1 | 1 | 1 |