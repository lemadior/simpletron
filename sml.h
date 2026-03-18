/**
 * @file sml.h
 * @author lemadior
 * @brief header file with main options and settings for the project
 * @version 0.2.1
 * @date 2026-03-18
 * * @copyright Copyright (c) 2026
 * 
 * =================================================================
 *
 * The SIMPLETRON CPU simulator
 *
 * This is a very basic emulation of the fiction CPU.
 * To program it one must use the SML - Simpletron's Machine Language
 * (only basic commands, even no FOR or WHILE but GOTO still present)
 *
 * SPEC:
 * -----------------
 * Memory: 100 words (00 - 99)
 * Word: integer numeric from -9999 up to +9999
 * Command: two-digit representation
 * (program always start from memory cell 00)
 * Accumulator: only storage register
 * Instruction Counter: store address of the next command (00 at the program start)
 * Instruction Register: contains the current instruction (4 digit: 2 for command, 2 for operand) 
 *
 * Program will executed step by step, from start command to end (if no condition goto will used)
 *
 * */

#ifndef SML_H
#define SML_H
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "commands.h"

#define NEWLINE printf("\n")

#define MEMORY_SIZE 100
#define UNOP_CMD 10000
#define ERROR_CMD -10000
#define SYSTEM_CMD 0
#define PROGRAM_NEW 1
#define PROGRAM_EDIT 2
#define FILENAME_LENGTH 64

extern short memory[MEMORY_SIZE];

typedef struct {
	short acc;	  // Accumulator (stored temporary value)
	uint8_t ic;	  // Instruction Counter (next command to use)
	short instr;  // Current instruction (command + operand)
	uint8_t cmd;  // Command code (operation code)
	uint8_t op;	  // Command operand (it used to be memory adress) 
} Cpu;

extern Cpu CPU;
extern Commands CMD;

short getOnlyNumbers();

const char *opcodeToString(OpCode);
uint8_t getCode(short);
uint8_t getOperand(short);

void getFileName(char *, uint8_t);

void listProgram(void);
void saveProgram(void);
void loadProgram(void);

void showSmlHelp(uint8_t);
void showAllHelp(void);

short getCommand(uint8_t);
void dumpCommand(short, uint8_t);

void memoryInit(void);

void input(short *);
void print(short *);

#endif



