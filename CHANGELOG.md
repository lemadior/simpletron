# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [1.0.0] - 2026-03-18

### Added
- Load program from file
- Save program to file
- refactoring code

## [0.2.1] - 2026-3-16

### Added

- New command 'L' - for load program, 'S' - to save the program.
- changed 'L' command to 'V' command

## [0.2.0] - 2026-03-12

### Added
- Core CPU simulation logic with Accumulator, Instruction Counter, and Instruction Register.
- Implementation of the SML (Simpletron Machine Language) instruction set (READ, WRITE, LOAD, STORE, ADD, SUB, MUL, DIV, JUMP, etc.).
- Modular project structure:
    - `dataManager.c`: Memory management and opcode decoding.
    - `run.c`: Instruction execution cycle.
    - `new.c` & `edit.c`: Interactive modes for program entry and modification.
    - `dump.c`: Visual memory and register status reporting.
- Advanced help system with detailed SML command descriptions (`showSmlHelp.c`).
- Input validation and buffer cleaning to prevent terminal errors.
- Makefile to more convenient compile the project

### Fixed
- Fixed an issue where the input buffer was not correctly cleared after character input in `getCommand.c`.
- Resolved a potential memory range error during the program execution cycle in `run.c`.
- Corrected the display format for negative values in the memory dump.

### Changed
- Refactored `main.c` to use a cleaner switch-case logic for workspace commands.
- Improved the "New Program" mode to automatically increment the instruction pointer.

---

## [0.1.0] - 2026-02-15

### Added
- Initial project setup.
- Basic memory array initialization.
- Simple workspace command loop.

