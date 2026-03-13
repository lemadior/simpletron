/**
 * @file main.c
 * @author lemadior (https://github.com/lemadior/simpletron)
 * @brief Main (start) module for the project
 * @details contains main control procedure and call appropriate functions for the user's comamnd.
 * Initialize main data structure and operands
 * @version 0.1
 * @date 2026-03-12
 * * @copyright Copyright (c) 2026
 * */

#include "sml.h"


OpCode OPCODE;
Commands CMD;
Cpu CPU = { 0, 0, 0, 0, 0};
short memory[MEMORY_SIZE] = {11, 12};

void welcomeMsg(void);
void showHelp(void);
//void showSmlHelp(uint8_t);
short getCommand(uint8_t);
void showDump(void);
void newProgram(void);
void editProgram(void);
void listProgram(void);
void runProgram();
//void commandsInit(void);

int main(void)
{
	uint8_t command = -1;
	uint8_t exit = 1;

	welcomeMsg();

	memoryInit();
	while (exit) {
		command = (uint8_t)getCommand(SYSTEM_CMD);
		//printf("CODE=%d\n", command);

		switch(command) {
			case CMD_HELP:
				showHelp();
				break;
			case CMD_DUMP:
			case CMD_DUMP_SM:
				showDump();
				break;
			case CMD_NEW:
			case CMD_NEW_SM:
				memoryInit();
				newProgram();
				break;
			case CMD_EDIT:
			case CMD_EDIT_SM:
				editProgram();
				break;
			case CMD_LIST:
			case CMD_LIST_SM:
				listProgram();
				break;
			case CMD_RUN:
			case CMD_RUN_SM:
				runProgram();
				break;
			case CMD_SML_HELP:
			case CMD_SML_HELP_SM:
				showSmlHelp(command);
				break;
			case CMD_EXIT:
			case CMD_EXIT_SM:
				exit = 0;
				break;
			default:
				printf("Unknown command!\n");
		}

		NEWLINE;
	}

	printf(" SIMPLETRON shutdown now...\n");
	NEWLINE;

	return CMD_EXIT;
}

