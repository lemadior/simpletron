/**
 * @file save.c
 * @author lemadior (https://github.com/lemadior/simpletron)
 * @brief A module responsible for saving a program to the file
 * @details after entering the command system will ask for the file name
 * Need type ONLY the name of file. The extension will add by system.
 * All the program will divided by the one byte and save it to the file.
 * WARNING: this module is very basic one! No checking existency file to save
 * @version 0.1.2
 * @date 2026-03-18
 * * @copyright Copyright (c) 2026
 * */
#include "slc.h"

#define EXT_PICK_UP 6

void saveProgram()
{
	//int ch;	 	// Store a current loaded symbol
	//short cmd;  // store the command to save
	FILE *fd;   // File descriptor (pointer to it)
	char name[FILENAME_LENGTH - EXT_PICK_UP];
	char fname[FILENAME_LENGTH];

	if (memory[0] == UNOP_CMD) {
		NEWLINE;
		printf(" Nothing to save!");
		NEWLINE;
		
		return;
	}	

	// Cut 6 symbols from name: '\n', '\0' and extension
	getFileName(name, FILENAME_LENGTH - EXT_PICK_UP);

	sprintf(fname, "%s.sml", name);

	NEWLINE;

	if ((fd = fopen(fname, "w")) == NULL) {
		printf(" Cannot create the file %s!\n", fname);

		return;
	}

	if (fwrite(memory, sizeof(short), MEMORY_SIZE, fd) != MEMORY_SIZE) {
		printf(" Error through saving the file!\n");
	} else {
		printf(" The program was saved to the %s file", fname);
	}

	fclose(fd);

	NEWLINE;
}

