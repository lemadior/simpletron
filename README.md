# Simpletron CPU SIMPLE Language Compiler (SLC)

The study project about compiler creation for fake CPU named Simpletron.

**SBC** is a compiler for a fictional CPU driven by the **SIMPLE (Simple language for SML)**. This project allows you to create low-level programs using the virtual machine SML.

```
Implementation of SIMPLE compiler/interpreter for the SIMPLETRON virtual machine is divided into several
interdependent modules:
a. Main Libraries
1. Standard C libraries: stdio.h, stdint.h, stdbool.h
2. Project-specific headers: func.h, infix.h, postfix.h
b. Modules and Features:

1. Input/Output module (input.c, checking.c):
   - Responsible for reading program and processing user input
   - Validates and preprocesses source code

a) Stack implementation (stack.c, stack.h):
   - Manages memory operations through FIFO structure
   - Includes push/pop functionality crucial to VM operations

c) Expression evaluation (POSTFIX/evaluate.c, POSTFIX/calculate.c):
   - Converts infix expressions to postfix notation
   - Evaluates arithmetic expressions in postfix format

d) Program management:
   - Instruction handling (instructions.c)
   - Loading programs from storage
   - Saving program states

e) Virtual machine operations:
   - Core execution logic for SIMPLE programs
   - Implementation of virtual instructions set

f) Data management (dataManager.c):
   - Memory allocation and manipulation functions
   - Core VM data structures

g) Help/documentation module (showHelp.h)

h) Command processing (getCommand.c, commands.h)
   - Translates user commands to VM function calls
    
i) User interface:
      - Main menu system (main.c)
      - Error handling and user messaging
```
## 🚀 Project Overview

This project is a complete compiler and interpreter for a SIMPLE programming language that targets a virtual machine called SML (Simple Machine Language). It implements a full compilation pipeline including lexical analysis, parsing, code generation, and execution in a simulated environment. The system supports basic programming constructs and can compile programs written in the SIMPLE language into machine code for execution on the SML virtual machine.

## 💻 Key Features

- **Compile SIMPLE Language Programs**: Compile `.slp` files into machine code for the Simpletron CPU. 
- **Infix to Postfix Conversion**: Supports conversion and evaluation of infix expressions to postfix notation.  
- **Complete Compiler Pipeline**: Includes lexical analysis, parsing, expression evaluation, validation, and code generation stages.
- **Virtual Machine Implementation with Data Management**: Implements a virtual machine with memory management, program loading, instruction execution
- **Program Management Tools**: Provide tools for program loading, saving, debugging and error handling with user interface.
- **Basic Programming Constructs**: Supports variables definitions, arithmetic expressions (conversion & evaluation), conditional statements, and iterative processes.

## 🛠 Build Instructions 

To compile the project:
1) Make sure you have a C compiler (gcc) installed
2) Run `make` in the project root directory

### Library Dependencies

The project uses standard C libraries:
- stdint.h for integer types definition and manipulation 
- ctype.h for character classification and conversion 
- stdio.h for input/output functions like printf(), scanf() etc.
- string.h for string manipulation functions such as copying or concatenation
- math.h for floating-point mathematical operations  
- stdbool.h for boolean type definitions and logical operations

## 📖 Usage Examples

```
slc -t -d test.slp -o test.slc
```
