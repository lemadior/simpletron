/**
 * @file load.c
 * @author lemadior (https://github.com/lemadior/simpletron)
 * @brief A module responsible for loading a program from the file
 * @details after entering the command system will ask for the file name
 * Need type ONLY the name of file. The extension will add by the system.
 * @version 0.1.1
 * @date 2026-03-18
 * * @copyright Copyright (c) 2026
 * */
#include "slc.h"

#define EXT_PICK_UP 6

void loadProgram()
{
	char answer;
	FILE *fd;   // File descriptor (pointer to it)
	char name[FILENAME_LENGTH - EXT_PICK_UP];
	char fname[FILENAME_LENGTH];
/*
	if (memory[0] != UNOP_CMD) {
		NEWLINE;
		printf(" WARNING: this command delete the current program!\n");
		printf(" Continue [Y/N]: ");
		answer = (uint8_t)getCommand(SYSTEM_CMD);
		
		if (answer != CMD_YES && answer != CMD_YES_SM) {
			return;
		}

		NEWLINE;
	}	

	// Cut 6 symbols from name: '\n', '\0' and extension
	getFileName(name, FILENAME_LENGTH - EXT_PICK_UP);

	sprintf(fname, "%s.sml", name);

	NEWLINE;

	if ((fd = fopen(fname, "r")) == NULL) {
		printf(" Cannot open the file %s!\n", fname);

		return;
	}

	if (fread(memory, sizeof(short), MEMORY_SIZE, fd) != MEMORY_SIZE) {
		printf(" Error loading program!\n");
	} else {
		printf(" The program was loaded from the %s file", fname);
	} 

	fclose(fd);
*/
	NEWLINE;
}

