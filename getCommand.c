/**
 * @file getCommand.c 
 * @author lemadior (https://github.com/lemadior/simpletron)
 * @brief A module responsible for retreiving command from std input
 * @details used in system common mode, in the new and edit mode
 * For each of modes the logic of retrieving data is different
 * @version 0.1.2
 * @date 2026-03-15
 * * @copyright Copyright (c) 2026
 * */

#include "sml.h"

void cleanInputBuffer(short);
//short getOnlyNumbers(void);

short getCommand(uint8_t type)
{
	char cvar;
	short var, status;
	static short prevCommand = 0; // Previous command  
	uint8_t code, op;

	code = getCode(prevCommand);
	op = getOperand(prevCommand);

	printf("> ");

	// Get command symbol for SML itself
	if (type == SYSTEM_CMD) {
		status = scanf(" %c", &cvar);

		// Drop all other symbols except first one
		cleanInputBuffer(status);

		var = (short)cvar;

	} else if (type == PROGRAM_NEW || type == PROGRAM_EDIT) { // command symbol for program
		//printf("PrevComamnd=%4.4d\n", prevCommand);
		if (code == DATA || code == EDIT) {
			printf("m[%2.2d]> ", op);
		} else {
			printf("[%2.2d]? ", CPU.ic);
		}

		// Get number or error if value has wrong format
		var = getOnlyNumbers();

		if (var == ERROR_CMD) {
			printf(" Wrong value! Try again\n");
			status = 0;
		} else if (getCode(var) == EDIT && type == PROGRAM_NEW) {
			NEWLINE;
			printf(" The command is not allowd here!\n");
			status = 0;
			NEWLINE;
		} else if (getCode(var) == DATA && type == PROGRAM_EDIT) {
			NEWLINE;
			printf(" The command is not allowd here!\n");
			status = 0;
			NEWLINE;
		} else {
			status = 1;
		
			if (code == DATA || code == EDIT) {
				prevCommand = 0;
			} else {
				prevCommand = var;
			}
		}
	}

	if (status == 0) {
		while (getchar() != '\n');
		var = ERROR_CMD;
	} 

	return var;
}

// Drop all symbols if it present in the buffer
void cleanInputBuffer(short status)
{
	int c;

	if (status == 1) {
		while ((c = getchar()) != '\n' && c != EOF);		
	}
}

