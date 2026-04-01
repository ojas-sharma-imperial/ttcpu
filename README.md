![](../../workflows/gds/badge.svg) ![](../../workflows/docs/badge.svg) ![](../../workflows/test/badge.svg) ![](../../workflows/fpga/badge.svg)

# ttcpu - a custom 4-bit RISC microprocessor for the Tiny Tapeout ASIC

The ttcpu is a 4-bit RISC microprocessor design and ISA designed around the constraints of the IO ports available on the Tiny Tapeout 1x1 tile, and designed such that as much 4-bit computational ability can be put on the chip.

The chip is designed around an 8-bit instruction word and a custom-defined ISA, which is laid out in the [ISA documentation](docs/isa.md). The largest constraint on the abilities of this microprocessor occur due to the limited instruction word available for use by a RISC architecture. The 1x1 Tiny Tapeout tile provides more than enough logic space for the (relatively) simple logical circuitry of the ttcpu.

## Functional Overview

The ttcpu contains many commonly-found instructions on RISC microprocessors, though some limited due to size constraints on the instruction word. The ttcpu can address 64 8-bit-word instructions, and 32 4-bit-word RAM locations, this being possible largely due to the use of the Harvard model of CPU.

There are largely 4 categories of instruction present on the ttcpu:

- ALU Instructions (ie. MOV, ADD, SUB, SHIFT)
- Memory Instructions (ie. LDR, STR)
- Jump Instructions (ie. JMP, JEQ, JSR)
- Extend Instructions (allowing computed addressing of greater than 4-bits)

The exact use of these instructions, along with assembly instructions for the ISA are defined in the [ISA documentation](docs/isa.md).

## External Hardware

Due to the limited IO ports available on a 1x1 Tiny Tapeout tile, the distribution of IO pins for different ttcpu pins may seem a bit strange. Additionally, the ROM and RAM interface are non-standard and not available as off-the-shelf parts. This project provides Arduino-compatible code to allow an external microcontroller to be connected to the ttcpu to emulate an external RAM and ROM of specification expected by the ttcpu.

The ttcpu expects a:

- 64 8-bit-word instruction ROM
- 32 4-bit-word data RAM, where the RAM.din and RAM.dout lines are the same (bidirectional lines due to limited pins available on the Tiny Tapeout tile) and the direction of the data lines is controlled by a RAM.wen output pin.