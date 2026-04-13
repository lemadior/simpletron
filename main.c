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
// Commands CMD;
Cpu CPU = { 0, 0, 99, 0, 0, 0};


int main(int argc, char *argv[])
{
	// Flags
	uint8_t isDump = 0;    // 1 - show dump of compiled program
	uint8_t stop = 0;      // 1 - exit from iiner while for argv checking

	// Common vars
	char programName[80] = {0};
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

	if (argc == 1) {
		printf("\n ERROR: no source SIMPLE file is founded!\n\n");
		printf("\n Short hint:\n");
		printf(" ------------------------------\n");
		printf(" USAGE: slc filename.sbl\n");
		printf(" Use '-h' key to get short help\n\n");
	} else {
		while (--argc > 0 && (*++argv)[0] == '-') {
			oldArgc = argc;
			stop = 0;
			while ((c = *++argv[0])) {
				if (stop == 1) {
					break;
				}

				if (c == '-') {
					if (oldArgc == argc) {
						printf("\n Error: double dash not allowed!\n\n");
					} 

					exit(EXIT_FAILURE);
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
					if (argc > 1) {
						--argc;
						++argv;
					} else {
						// If the '-o' key is last key but filename is miss
						printf("\n Error: missing argument for '-o' key!\n\n");

						exit(EXIT_FAILURE);
					}

					// Check if the next argv is the filename
					if (*argv[0] == '-') {
						printf("\n Error: missing argument for command key: '-o'!\n\n");

						exit(EXIT_FAILURE);
					}
					
					strcpy(programName, *argv);
					strcat(programName, ".sml");
					
					stop = 1;

					break;
				default:
					printf(" Unknown parameter: %c\n", c);
					argc = 0;
					break;
				}
			}
		}
	}

	memoryInit();

	NEWLINE;

	printf(" Output program name: %s\n", programName);
	printf(" SIMPLE compiler shutdown now...\n");

	NEWLINE;

	return EXIT_SUCCESS;
}

