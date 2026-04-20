#ifndef FUNC_H
#define FUNC_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "commands.h"
#include "stack.h"

#define NEWLINE printf("\n")

#define MEMORY_SIZE 100
#define SYMBOL_TABLE_SIZE 256
#define UNOP_CMD 10000
#define ERROR_CMD -10000
#define SYSTEM_CMD 0
#define PROGRAM_NEW 1
#define PROGRAM_EDIT 2
#define FILENAME_LENGTH 64

#define ERROR(...) \
	do { \
		fprintf(stderr, " ERROR: "); \
		fprintf(stderr, __VA_ARGS__); \
		fprintf(stderr, "\n\n"); \
		exit(EXIT_FAILURE); \
	} while (0)

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

typedef struct {
	FILE *fdSRC;
	FILE *fdTGT;
} Descriptors;

extern Cpu CPU;
extern TableEntry TABLEENTRY;
extern Descriptors FDESCR;

short getOnlyNumbers();

const char *opcodeToString(OpCode);
uint8_t getCode(short);
uint8_t getOperand(short);

short getCommand(uint8_t);

#endif
