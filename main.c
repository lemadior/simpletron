/**
 * @file main.c
 * @author lemadior (https://github.com/lemadior/simpletron)
 * @brief Main (start) module for the project
 * @details contains main control procedure and call appropriate functions for the user's comamnd.
 * Initialize main data structure and operands
 * @version 1.0.0
 * @date 2026-04-12
 * * @copyright Copyright (c) 2026
 * */

#include "slc.h"

#define DEFAULT_OUT_NAME "prog.sml"

short memory[MEMORY_SIZE];
uint8_t flags[MEMORY_SIZE];
TableEntry TABLEENTRY;
OpCode OPCODE;
Cpu CPU = { 0, 0, 99, 0, 0, 0};


int main(int argc, char *argv[])
{
	// Flags
	uint8_t isDump = 0;    // 1 - show dump of compiled program
	uint8_t isTarget = 0;  // 1 - next argv is grogram name
	uint8_t stop = 0;      // 1 - exit from inner 'while' for argv


	// Common vars
	char programName[80] = {0};
	char sourceName[80] = {0};
	int c, oldArgc;

	// Set default program name to the 'prog.sml'
	strcpy(programName, DEFAULT_OUT_NAME);

	// uint8_t command = -1;
	// uint8_t exit = 1;
	// char *source = "source";
	// char *target = "target";

	// convertToPostfix(source, target);
	// evaluatePostfixExpression(source);
	// welcomeMsg();
	printf("\n SIMPLE compiler starting...\n\n");

		while (--argc > 0) { 
			// oldArgc = argc;
			// stop = 0;

			++argv;

			if (isTarget == 1) {
				// Check if the next argv is the filename
				if (*argv[0] == '-') {
					ERROR("missing argument for command key: '-o'!");
				}
					
				strcpy(programName, *argv);
				strcat(programName, ".sml");

				isTarget = 0;

				continue;
			}

			if (*argv[0] == '-') {
				while ((c = *++argv[0])) {
					if (c == '-') {
						ERROR("double dash not allowed!");
					}
				
					switch(c) {
					case 'h':
						showHelp();
						break;
					case 'd':
						isDump = 1;
						break;
					case 'c':
						break;
					case 'o':
						if (argc <= 1) {
							// If the '-o' key is last key but filename is miss
							ERROR("missing argument for '-o' key!");
						}
						isTarget = 1;

						break;
					default:
						printf(" Unknown parameter: %c\n", c);
						argc = 0;
						break;
					}
				} 
			} else {
				// Gget source filename
				if (sourceName[0] == 0) {
					strcpy(sourceName, *argv);
				} else {
					ERROR("duplicate input of source file!");
				}
			}
		}


	if (sourceName[0] == 0) {
		printf("\n ERROR: no source SIMPLE file is founded!\n\n");
		printf("\n Short hint:\n");
		printf(" ------------------------------\n");
		printf(" USAGE: slc filename.slp\n");
		printf(" Use '-h' key to get short help\n\n");

		exit(EXIT_SUCCESS);
	} 


	memoryInit();

	NEWLINE;

	printf(" Source SIMPLE file is: %s\n", sourceName);
	printf(" Output program name: %s\n", programName);
	if (isDump == 1) {
		printf(" Dump program\n");
	}
	printf(" SIMPLE compiler shutdown now...\n");

	NEWLINE;

	return EXIT_SUCCESS;
}

