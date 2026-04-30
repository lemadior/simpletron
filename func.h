#ifndef FUNC_H
#define FUNC_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include "commands.h"
#include "stack.h"


#define NEWLINE printf("\n")

#define MEMORY_SIZE 100
#define MAX_LINE_SIZE 128
#define SYMBOL_TABLE_SIZE 256
#define UNOP_CMD 10000
#define ERROR_CMD -10000
#define SYSTEM_CMD 0
#define PROGRAM_NEW 1
#define PROGRAM_EDIT 2
#define FILENAME_LENGTH 64
#define EXPRESSION_LENGTH 64

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

// SIMPLE lsnguage statement (for store per line)
typedef struct { 
	int line;			// Number of line
	char cmd[6];	    // name of the SIMPLE command
	char var;           // variable (main for expression)
	char exprleft[EXPRESSION_LENGTH];	// Mainly for IF (left part of comparsion)
	char exprright[EXPRESSION_LENGTH];  // For most expression or comparstion (right part)
	char varright;      // Second var (exmp, i = y). This will store 'y'
	char cond[3];		// Condition (==, != etc.)
	int jumpto;			// Line number to jump
} Statement;

extern Cpu CPU;
extern TableEntry TABLEENTRY;
extern Descriptors FDESCR;

short getOnlyNumbers();
int getline(char *, int, FILE *);
const char *opcodeToString(OpCode);
int cmdnameToCode(char *);
uint8_t getCode(short);
uint8_t getOperand(short);
void firstPass();
short getCommand(uint8_t);

#endif
