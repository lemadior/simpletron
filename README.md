# Simpletron CPU Simulator (SML)
The study project about emulation of fake CPU named is SIMPLETRON

**Simpletron** is a simulator for a fictional CPU driven by the **SML (Simpletron Machine Language)**. This project allows you to create, edit, and execute low-level programs using a virtual architecture with a single accumulator and 100 memory cells.

## 🚀 Key Features
- **CPU Emulation:** Works with core registers (Instruction Counter, Accumulator, Instruction Register).
- **Memory:** 100 words (ranging from -9999 to +9999).
- **Console Interface:** Supports creating new programs, editing code at specific addresses, and memory dumps.
- **Full SML Support:** From basic I/O to arithmetic operations and conditional branching.
- **Store and Load:** Possibility to store entered program to the file and load it back

## 💻 SML (Simpletron Machine Language) Overview
Each instruction is a 4-digit signed integer: `CCAA`, where `CC` is the Operation Code and `AA` is the Memory Address (operand).

| Code | Instruction | Description |
|------|-------------|-------------|
| 00   | NOP         | Not Operation - just skip this command |
| 10   | READ        | Read a word from the terminal into memory |
| 11   | WRITE       | Write a word from memory to the terminal |
| 20   | LOAD        | Load a word from memory into the accumulator |
| 21   | STORE       | Store the accumulator value into memory |
| 30   | ADD         | Add a word from memory to the accumulator |
| 31   | SUB         | Subtract the value from the accumulator and from the memory|
| 32   | DIV         | DIVIDE the value from the accumulator and from the memory|
| 33   | MUL         | Multiply the value from the accumulator and from the memory|
| 40   | JUMP        | Jump to a specific memory address |
| 41   | JNEG        | Jump into specified address if the accumulator's value < 0 |
| 41   | JZERO       | Jump into specified address if the accumulator's value == 0 |
| 43   | HALT        | Terminate program execution |

## 🛠 Compilation and Usage
To compile the project, use `gcc` to link all `.c` files:

```bash
gcc *.c -o simpletron
./simpletron

Or just type `make`
