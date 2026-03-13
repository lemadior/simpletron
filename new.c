/**
 * @file new.c
 * @author lemadior (https://github.com/lemadior/simpletron)
 * @brief A module responsible for entering SML instructions and store it
 * @details here the entered command is stored into machine memory
 * @version 0.1 
 * @date 2026-03-12
 * * @copyright Copyright (c) 2026
 * */


#include "sml.h"

uint8_t getNextInstrPointer(uint8_t prevCode, uint8_t prevOperand);

void showNewProgramModeHelp(void);

void newProgram(void)
{
	short reserved = 0, reg;
	uint8_t code, operand, prevCode, prevOperand;

	CPU.ic = 0;
	
	printf(" Start type new program...\n");
	printf(" -------------------------\n");
	
	showNewProgramModeHelp();

	NEWLINE;

	while((reg = getCommand(PROGRAM_CMD)) != UNOP_CMD) {
		// Prev code and operand need to correctly operate DATA instruction
		prevCode = getCode(reserved);
		prevOperand = getOperand(reserved);

		if (reg == ERROR_CMD) {
			continue;
		}

		// Current code and operand
		code = getCode(reg);
		operand = getOperand(reg);

		// Exit from new program mode
		if (reg == STOP && prevCode != DATA) {
			NEWLINE;
			
			printf(" New program mode exited...\n");
			
			CPU.ic = 0;

			return;
		}
	
		if (code == HELP && prevCode != DATA) {
			// Repeat intro help if command has code=01 & operand=00
			if (getOperand(reg) == 0) {
				showNewProgramModeHelp();
				NEWLINE;
			} else {
				showSmlHelp(operand);
			}	

			continue;
		}

		if (reg == LIST && prevCode != DATA) {
			NEWLINE;
			listProgram();
			NEWLINE;

			continue;
		}
		
		// Skip unknown command
		if (strcmp(opcodeToString(code), "UNKNOWN") == 0 && prevCode != DATA) {
			NEWLINE;
			printf(" Unknown commad. Try again...\n");
			NEWLINE;

			continue;
		}

		if (code != DATA && prevCode != DATA) {
			memory[CPU.ic] = reg;

			dumpCommand(reg, CPU.ic);
		}

		// If previous command is DATA then current mode is 
		// enter the value stored in cell specified by prevOperand
		if (prevCode == DATA) {
			memory[prevOperand] = reg;

			dumpCommand(reg, prevOperand);

			reserved = 0;
		} else {
			reserved = reg;
		} 
	
		if (code != DATA) {
			CPU.ic = getNextInstrPointer(prevCode, prevOperand);
		}
	}

	NEWLINE;

	printf(" Program saved into memory");

	NEWLINE;
}

// Next pointer value may be not going sequentally due to DATA cells
uint8_t getNextInstrPointer(uint8_t prevCode, uint8_t prevOperand)
{
	uint8_t ic, i = 0;

	ic = CPU.ic;

	// Check if next memory cell for instruction pointer
	// is not occupied by data value
	while (memory[ic + i++] != UNOP_CMD) {};
	
	ic += --i;
	
	if (ic >= MEMORY_SIZE) {
		printf(" No available memory!");

		return CPU.ic;
	}

	return ic;
}

void showNewProgramModeHelp(void)
{
	printf(" Type '1' short help for command operand is command num)\n");
	printf(" Type '2' Show the program.\n");
	printf(" Type '5' Exit from new program mode.\n");
}


