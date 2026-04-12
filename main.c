/**
 * @file main.c
 * @author lemadior (https://github.com/lemadior/simpletron)
 * @brief Main (start) module for the project
 * @details contains main control procedure and call appropriate functions for the user's comamnd.
 * Initialize main data structure and operands
 * @version 1.0.0
 * @date 2026-03-18
 * * @copyright Copyright (c) 2026
 * */

#include "sbc.h"


OpCode OPCODE;
// Commands CMD;
Cpu CPU = { 0, 0, 99, 0, 0, 0};

int main(void)
{
	// uint8_t command = -1;
	uint8_t exit = 1;

	// welcomeMsg();

	memoryInit();
	while (exit) {
		// command = (uint8_t)getCommand(SYSTEM_CMD);
/*
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
			case CMD_LOAD:
			case CMD_LOAD_SM:
				loadProgram();
				break;
			case CMD_SAVE:
			case CMD_SAVE_SM:
				saveProgram();
				break;
			case CMD_EXIT:
			case CMD_EXIT_SM:
				exit = 0;
				break;
			default:
				printf("Unknown command!\n");
		}

		NEWLINE;
		*/
	}

	printf(" SIMPLETRON shutdown now...\n");
	NEWLINE;

	return EXIT_SUCCESS;
}

