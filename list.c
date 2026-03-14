/**
 * @file list.c
 * @author lemadior (https://github.com/lemadior/simpletron)
 * @brief A module responsible for printing program to terminal
 * @version 0.1.1
 * @date 2026-03-12
 * * @copyright Copyright (c) 2026
 * */

#include "sml.h"

void listProgram(void)
{
	uint8_t i, free = 0;
	short opcode;

	printf(" Program Listing...\n");
	NEWLINE;

	// If first cell contains something it means that something is memory
	if (memory[0] < UNOP_CMD) {
		for (i = 0; i < MEMORY_SIZE; i++) {
			if ((opcode = memory[i]) != UNOP_CMD) {
			 dumpCommand(opcode, i);
			} else {
				free++;
			}
		}
		
		NEWLINE;
		printf(" Free memory: %d\n", free);
	} else {
		printf(" No program to list!\n");
	}
}

