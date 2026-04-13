/**
 * @file dump.c
 * @author lemadior (https://github.com/lemadior/simpletron)
 * @brief A module responsible for printing 'CPU' registers and memory
 * @version 0.1
 * @date 2026-03-12
 * * @copyright Copyright (c) 2026
 * */

#include "sbc.h"

void showDump(void)
{
	int i, j, row;
	
	row = MEMORY_SIZE / 10;

	NEWLINE;

	printf(" REGISTERS:\n");
	printf(" InstructionCounter:  %5.2d\n", CPU.ic);
	printf(" Accumulator:         %5.4d\n", CPU.acc);
	printf(" Instruction:         %5.4d\n", CPU.instr);
	printf(" Command:             %5.2d\n", CPU.cmd);
	printf(" Operand:             %5.2d\n", CPU.op);

	NEWLINE;

	printf(" MEMORY:\n   ");

	for (i = 0; i< row; i++) {
		printf(" %6.1d", i);
	}
	
	NEWLINE;
	
	for(i = 0; i< MEMORY_SIZE; i+=10) {
		printf(" %2.2d", i);

		for (j = 0; j < row; j++) {
			printf(" %6.4d", memory[i+j] >= UNOP_CMD ? 0 : memory[i+j]);
		}

		NEWLINE;
	}
}

