/**
 * @file save.c
 * @author lemadior (https://github.com/lemadior/simpletron)
 * @brief A module responsible for saving a program to the file
 * @details after entering the command system will ask for the file name
 * Need type ONLY the name of file. The extension will add by system.
 * All the program will divided by the one byte and save it to the file.
 * WARNING: this module is very basic one! No checking existency file to save
 * @version 0.1.1
 * @date 2026-03-17
 * * @copyright Copyright (c) 2026
 * */
#include "sml.h"

void saveProgram()
{
	int ch;	 	// Store a current loaded symbol
	short cmd;  // store the command to save
	FILE *fd;   // File descriptor (pointer to it)
	char fname[FILENAME_LENGTH];

	getFileName(fname, FILENAME_LENGTH);

	NEWLINE;

	if (memory[0] == UNOP_CMD) {
		NEWLINE;
		printf(" Nothing to save!");
		NEWLINE;
		
		return;
	}	


}

