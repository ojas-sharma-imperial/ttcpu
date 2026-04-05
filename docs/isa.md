# ttcpu ISA

This file outlines the exact (custom) instruction set architecture defined for the ttcpu, as well as how to assemble code for the ttcpu.

## Design Philosophy

The goal of ttcpu was to create a computationally-sufficient RISC CPU architecture. We define computationally-sufficient as having enough instructions such that general programmatic concepts (such as if/else, while, for statements) can all be implemented in a meaningful way, allowing general-purpose computer programs to be loaded and executed.

The RISC architecture requires more information to be defined in the instruction than CISC, with all instructions taking exactly 1 clock cycle to occur. Hence the 8-bit instruction word has been designed around being able to load full 4-bit immeditate values without any sign-extending of smaller inputs.

## Design Overview

### Accumulator Registers

The ttcpu contains two main 'accumulator' registers, named `A` and `B`, both 4-bit registers. All instructions can occur on register `A`, whereas operations concerning immediate values or shifts can only occur on register `A` (due to instruction word size constraints).

### Program Counters

The ttcpu also contains two 6-bit registers, `PC` and `PCX`. `PC` (program counter) stores the address of the instruction currently being executed, and can be modified through the use of jump instructions (along with extend instructions). `PCX` (subroutine program counter) allows native non-nested subroutines to be implemented, allowing for the ttcpu to return to the base program after a subroutine is complete automatically upon a `RET` (return) instruction.

### Flags

The ttcpu has two flags:

- `FlagZ` (zero flag)
- `FlagC` (carry flag)

`FlagZ` is written to by all ALU instructions, as well as memory load instructions. The value of FlagZ is 1 only if the data value is exactly equal to 0. FlagZ has associated jump instructions `JEQ` & `JNE`.

`FlagC` is written to by all ALU instructions except `MOV` and `NAND`. The value of `FlagC` is 1 if the full adder/subtracter in the ALU has a MSB carry-out or, in the case of shifts, the value of the bit last shifted out. `FlagC` has associated jump instructions `JCS` & `JCC`.

### Extend Register

The ttcpu is a Harvard-architecture CPU, which makes it easier for address buses to be of a different width to data buses. However, this complicates memory instructions as well as computed jump instructions, requiring additional instructions to extend the width of registers to achieve the full range of (wider) addresses.

The ttcpu achieves this using a single 2-bit additional register `X` which can have values stored into it which, upon **only** the subsequent clock cycle, will be interpreted as the MSBs of the address word.

Note that, since RAM addresses are 5-bit and ROM addresses are 6-bit, there are extend instructions for both 1-bit extensions and 2-bit extensions, though they both store to the same register `X` as both instructions can not be simultaneously active.

## Instruction Set Architecture

The full, machine-code-level ISA is defined in the [machine code ISA](isa.png) however the sections below explain exact functionality of instructions at an assembly-programmer level of abstraction.

### Immediate Values

There are five types of immediate value that can be inputted into various instructions. Note that they vary in binary representation, and their individual syntaxes are outlined below:

- `#IMMS4`: 4-bit signed (two's complement) -> domain [-16, 15]
- `#SHIFTCNT`: 2-bit unsigned -> domain [0, 3]
- `#IMM2`: 2-bit unsigned -> domain [0, 3]
- `#IMM1`: 1-bit unsigned -> domain [0, 1]
- `#IMMC2`: 2-bit with correcting offset -> domain {-3, -2, 2, 3}

### Individual Instruction Definitions

This section outlines the syntax and detailed function of each ttcpu instruction from the perspective of an assembly-language programmer, simplifying some of the machine-code-level nuances.

| Instruction Opcode | Operation | Writes to Register? | Writes to Flags? | Affected by EXT? |
| :---: | :---: | :---: | :---: | :---: |
| `MOV` | `A := #IMMS4`; `Ra := Rb` | `A` for immediate; `Ra` | `Z` | No |
| `ADD` | `A := A + #IMMS4`; `Ra := Ra + Rb` | `A` for immediate; `Ra` | `Z`, `C` | No |
| `SUB` | `A := A - #IMMS4`; `Ra := Ra - Rb` | `A` for immediate; `Ra` | `Z`, `C` | No |
| `ADC` | `A := A - #IMMS4`; `Ra := Ra - Rb + FlagC` | `A` for immediate; `Ra` | `Z`, `C` | No |
| `SBC` | `A := A - #IMMS4`; `Ra := Ra - Rb + (FlagC - 1)` | `A` for immediate; `Ra` | `Z`, `C` | No |
| `NAND` | `A := ~(A && #IMMS4)`; `Ra := ~(Ra && Rb)` | `A` for immediate; `Ra` | `Z` | No |
| `CMP` | `A := A - #IMMS4`; `Ra - Rb` | \- | `Z`, `C` | No |
| `LSL` | `A := A << #SHIFTCNT`; 0 loaded in | `A` | `Z`, `C` | No |
| `LSR` | `A := A >> #SHIFTCNT`; 0 loaded in | `A` | `Z`, `C` | No |
| `ASR` | `A := A << #SHIFTCNT`; sign-bit loaded in | `A` | `Z`, `C` | No |
| `XSR` | `A := A << #SHIFTCNT`; `FlagC` loaded in | `A` | `Z`, `C` | No |
| `LDR` | `Ra := RAM[#IMM2]`; `Ra := RAM[Rb]` | `Ra` | `Z` | `EXT1` extends `Rb` |
| `STR` | `RAM[#IMM2] := Ra`; `RAM[Ra] := Rb` | \- | \- | `EXT1` extends `Ra` |
| `JMP` | `PC := PC + #IMMC2`; `PC := Ra` | `PC` | \- | `EXT2` extends `Ra` |
| `JEQ` | `PC := PC + #IMMC2` if `FlagZ = 1` | `PC` | \- | No |
| `JNE` | `PC := PC + #IMMC2` if `FlagZ = 0` | `PC` | \- | No |
| `JCS` | `PC := PC + #IMMC2` if `FlagC = 1` | `PC` | \- | No |
| `JCC` | `PC := PC + #IMMC2` if `FlagC = 0` | `PC` | \- | No |
| `JSR` | `PCX := PC + 1`; `PC := Ra` | `PC`, `PCX` | \- | `EXT2` extends `Ra` |
| `RET` | `PC := PCX` | `PC` | \- | No |
| `EXT1` | `X[0] := #IMM1` | `X` | \- | \- |
| `EXT2` | `X[1:0] := #IMM2`; `X[1:0] := Ra[1:0]` | `X` | \- | \- |
| `MRK` | `PCX := PC + 1` | `PCX` | \- | No |
| `NOP` | \- | \- | \- | No |

## Assembling ttcpu Programs

Programs for the ttcpu should be written in plaintext, and stored in a `.txt` file. The included assembler program can be used to produce a machine-code `.ram` file that can be inspected, as well as a `.mem` file that can be loaded into the `test_mem_interface.sv` file to simulate programs easily using Verilator.
