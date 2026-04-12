#ifndef FUNC_H
#define FUNC_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NEWLINE printf("\n")

#define MEMORY_SIZE 100
#define SYMBOL_TABLE_SIZE 100
#define UNOP_CMD 10000
#define ERROR_CMD -10000
#define SYSTEM_CMD 0
#define PROGRAM_NEW 1
#define PROGRAM_EDIT 2
#define FILENAME_LENGTH 64

extern short memory[MEMORY_SIZE];
extern uint8_t flags[MEMORY_SIZE];

typedef struct {
	short acc;	  // Accumulator (stored temporary value)
	uint8_t ic;	  // Instruction Counter (next command to use)
	uint8_t dc;	  // Data counter (next cell to store data)
	short instr;  // Current instruction (command + operand)
	uint8_t cmd;  // Command code (operation code)
	uint8_t op;	  // Command operand (it used to be memory adress) 
} Cpu;

typedef struct {
	int symbol;
	char type;   // 'C', 'L' or 'V'
	int location; // cell address (0 to 99)
} TableEntry;

extern Cpu CPU;
extern TableEntry TABLEENTRY;

short getOnlyNumbers();

const char *opcodeToString(OpCode);
uint8_t getCode(short);
uint8_t getOperand(short);

short getCommand(uint8_t);

#endif
