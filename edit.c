/**
 * @file edit.c
 * @author lemadior (https://github.com/lemadior/simpletron)
 * @brief A module responsible for edit SML for existed program
 * @details to edit a command need to specify an action's number 
 * and the cell number to edit
 * @version 0.1.2
 * @date 2026-03-14
 * * @copyright Copyright (c) 2026
 * */


#include "sml.h"

void showEditProgramModeHelp(void);

void editProgram(void)
{
	short reserved = 0, reg;
	uint8_t code, operand, prevCode, prevOperand;

	CPU.ic = 0;
	
	printf(" Edit existent program...\n");
	printf(" -------------------------\n");
	
	if (memory[0] >= UNOP_CMD) {
		printf(" No program found. Exited from edit mode.\n");
		NEWLINE;

		return;
	}

	showEditProgramModeHelp();

	NEWLINE;

	while((reg = getCommand(PROGRAM_EDIT)) != UNOP_CMD) {
		prevCode = getCode(reserved);
		prevOperand = getOperand(reserved);

		if (reg == ERROR_CMD) {
			continue;
		}

		code = getCode(reg);
		operand = getOperand(reg);

		// Exit from new program mode
		if (reg == STOP && prevCode != EDIT) {
			NEWLINE;
			
			printf(" Edit program mode exited...\n");
			
			CPU.ic = 0;

			return;
		}
	
		if (code == HELP && prevCode != EDIT) {
			// Repeat intro help if command has code=01 & operand=00
			if (getOperand(reg) == 0) {
				showEditProgramModeHelp();
				NEWLINE;
			} else {
				showSmlHelp(operand);
			}	

			continue;
		}

		if (reg == LIST && prevCode != EDIT) {
			NEWLINE;
			listProgram();
			NEWLINE;

			continue;
		}
		
		// Skip unknown command
		if (strcmp(opcodeToString(code), "UNKNOWN") == 0 && prevCode != EDIT) {
			NEWLINE;
			printf(" Unknown commad. Try again...\n");
			NEWLINE;

			continue;
		}

		// If previous command is DATA then current mode is 
		// enter the value stored in cell specified by prevOperand
		if (prevCode == EDIT) {
			memory[prevOperand] = reg;

			dumpCommand(reg, prevOperand);

			reserved = 0;
		} else {
			reserved = reg;
		} 
	}

	NEWLINE;

	printf(" Program saved into memory");

	NEWLINE;
}

void showEditProgramModeHelp(void)
{
	printf(" Type '1' short help for command operand is command num)\n");
	printf(" Type '2' Show the program.\n");
	printf(" Type '3' to edit specified address. Exmp: 0310 - edit line #10\n");
	printf(" Type '5' Exit from edit program mode.\n");
}


