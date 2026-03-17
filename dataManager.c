/**
 * @file dataManager.c
 * @author lemadior (https://github.com/lemadior/simpletron)
 * @brief A library module
 * @details here is the functions used to initialize memory,
 * translate instructions to the string representations,
 * getters for Code and Operand and display commands mnemonic after 
 * its being typed or edited.
 * @version 0.2
 * @date 2026-03-17
 * * @copyright Copyright (c) 2026
 * */

#include "sml.h"


/*
 * Init memory array by UNOP (1000) value.
 * If max valid value is 9999 the UNOP is means that the stored it memory
 * cell is untouched (not yet being modified)
 */
void memoryInit(void)
{
	int i;
	//printf("In memory Init\n");
	for (i = 0; i < MEMORY_SIZE; i++) {
		memory[i] = UNOP_CMD;
	}
}

// Return the name of the opcode
const char *opcodeToString(OpCode code)
{
	switch(code) {
		case READ: return "READ";
		case WRITE: return "WRITE";
		case LOAD: return "LOAD";
		case STORE: return "STORE";
		case ADD: return "ADD";
		case SUB: return "SUB";
		case DIV: return "DIV";
		case MUL: return "MUL";
		case JUMP: return "GOTO";
		case JNEG: return "GOTONEG";
		case JZERO: return "GOTOZERO";
		case HALT: return "HALT";
		case NOP: return "NOP";
		case DATA: return "DATA";
		case EDIT: return "EDIT";
		default: return "UNKNOWN";
	}
}

// Get command code (2 digit)
uint8_t getCode(short opcode)
{
	return opcode < 100 ? opcode : opcode / 100;
}

// Get command's operand (what command should do with it)
uint8_t getOperand(short opcode)
{
	return opcode < 100 ? 0 : opcode % 100;
}

// Print command data (memory cell, command and operand)
void dumpCommand(short instr, uint8_t counter)
{
	const char *command;
	const uint8_t code = getCode(instr);
	
	// Backup value for counter for dumpCommand()
	static uint8_t icReserved = 0;
	
	command = opcodeToString(code);

	if (icReserved == DATA) {
		printf(" Data [%2.2d] %4.4d\n", getOperand(icReserved), instr);
	} else if (strcmp(command, "UNKNOWN") == 0) {
		printf(" Data [%2.2d] %4.4d\n", counter, instr);
	} else if (strcmp(command, "NOP") == 0) {
		printf(" Addr [%2.2d] CMD: %s\n", counter, command);
	} else {
		printf(" Addr [%2.2d] CMD: %s %2.2d\n", counter, command, getOperand(instr));
	}

	icReserved = code;
}

// Check input value for numeric format only!
short getOnlyNumbers()
{
	char c, buffer[6]; // 5 symbols + \0
	int value, i = 0;

	scanf("%5s", buffer);

	while((c = buffer[i++]) != '\0') {
		if (i == 1 && c == '-') {
			continue;
		} 
		
		if (!isdigit(c)) {
			return ERROR_CMD;
		}
	} 
	
	value = atoi(buffer);

	if (value >= UNOP_CMD || value <= ERROR_CMD ) {
		value = ERROR_CMD;
	}

	return (short)value;
}

// Get name of the program file
// buf: where is name will be stored
// length: maximum allowed symbols in filename
void getFileName(char *buf, uint8_t length)
{
    while(1) {
        NEWLINE;
        printf("Enter the filename: ");

		if (fgets(buf, length, stdin) != NULL) {
			// Checki if the first symbol is not an NEWLINE
            // This catch the case of accidentally press ENTER
			if (buf[0] == '\n') {
                continue;
            }
		}

        // Delete the NEWLINE symbol from the end of text line
        buf[strcspn(buf, "\n")] = '\0';

        break;
    }
}

