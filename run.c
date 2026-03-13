/**
 * @file run.c
 * @author lemadior (https://github.com/lemadior/simpletron)
 * @brief A module responsible for execution SML instructions
 * @details here the progrem is executed
 * @version 0.1
 * @date 2026-03-12
 * * @copyright Copyright (c) 2026
 * */

#include "sml.h"

void readData(short *);

void runProgram(void)
{
	NEWLINE;
	if (memory[0] >= UNOP_CMD) {
		printf(" No program found in memory! Exiting...\n");
		
		return;
	}

	printf(" Run current program...\n");
	printf(" ----------------------\n");
	
	NEWLINE;

	CPU.ic = 0;
	CPU.acc = 0;
	CPU.instr = 0;
	CPU.cmd = 0;
	CPU.op = 0;

	while((CPU.instr = memory[CPU.ic]) != HALT) {
		CPU.cmd = getCode(CPU.instr);
		CPU.op = getOperand(CPU.instr);

		if (++CPU.ic >= MEMORY_SIZE) {
			printf(" ERROR: out of range! Exiting...\n");

			break;
		}

		switch(CPU.cmd) {
			case NOP:
				break;
			case READ:
				readData(&memory[CPU.op]);
				NEWLINE;
				break;
			case WRITE:
				printf("Out:(%2.2d)", CPU.op);
				printf("# %4.4d\n", memory[CPU.op]);
				break;
		}
	}

	NEWLINE;
	printf(" SML program ended!\n");
}

void readData(short *cell)
{
	short var;
	
	var = ERROR_CMD;

	while (var == ERROR_CMD) {

		printf("In:[%2.2d]? ", CPU.op);

		// Get number or error if value has wrong format
		var = getOnlyNumbers();

		if (var == ERROR_CMD) {
			printf(" Wrong value! Try again\n");
			NEWLINE;

			continue;
		} 
		
		break;
	}

	*cell = var;
}

