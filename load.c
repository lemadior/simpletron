/**
 * @file load.c
 * @author lemadior (https://github.com/lemadior/simpletron)
 * @brief A module responsible for loading a program from the file
 * @details after entering the command system will ask for the file name
 * Need type ONLY the name of file. The extension will add by the system.
 * @version 0.1
 * @date 2026-03-16
 * * @copyright Copyright (c) 2026
 * */
#include "sml.h"

void loadProgram()
{
	char answer;
	FILE *fd;   // File descriptor (pointer to it)
	char name[FILENAME_LENGTH - 5];
	char fname[FILENAME_LENGTH];

	if (memory[0] != UNOP_CMD) {
		NEWLINE;
		printf(" WARNING: this command delete the current program!\n");
		printf(" Continue [Y/N]: ");
		answer = (uint8_t)getCommand(SYSTEM_CMD);
		
		if (answer != CMD_YES) {
			return;
		}
	}	

	NEWLINE;

	getFileName(name, FILENAME_LENGTH - 5);

	sprintf(fname, "%s.sml", name);

	NEWLINE;

	if ((fd = fopen(fname, "r")) == NULL) {
		printf("Cannot create the file %s!\n", fname);

		return;
	}

	fread(memory, sizeof(short), MEMORY_SIZE, fd);

	fclose(fd);

	NEWLINE;

	printf("The program was loaded from the %s file", fname);

	NEWLINE;
}

