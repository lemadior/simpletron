/**
 * @file list.c
 * @author lemadior (https://github.com/lemadior/simpletron)
 * @brief A module responsible for printing program to terminal
 * @version 0.1
 * @date 2026-03-12
 * * @copyright Copyright (c) 2026
 * */

#include "sml.h"

void listProgram(void)
{
	uint8_t i = 0;
	short opcode;

	printf(" Program Listing...\n");
	NEWLINE;

	if (memory[0] < UNOP_CMD) {
		while ((opcode = memory[i]) != UNOP_CMD && i < MEMORY_SIZE) {
			dumpCommand(opcode, i);
			
			i++;
		}
			
	} else {
		printf(" No program to list!\n");
	}
}

