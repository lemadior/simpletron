/**
 * @file shortHelp.c
 * @author lemadior (https://github.com/lemadior/simpletron)
 * @brief Short help for available system commands
 * @details the commands are not a SML instructions. This is a commands
 * for the system operations aka print dump, show program listing etc.
 * @version 0.1.1
 * @date 2026-03-12
 * * @copyright Copyright (c) 2026
 * */

#include "sbc.h"

void showHelp(void)
{
	NEWLINE;
	printf(" Console commands HELP:\n");
	printf(" ----------------------\n");
	printf("\n 'D' - print memory and cpu vaiables dump\n");
	printf(" 'N' - Create new program (old program will gone)\n");
	printf(" 'E' - Edit mode (type program here)\n");
	printf(" 'V' - View program on the terminal (get listing)\n");
	printf(" 'R' - Run the SML program\n");
	printf(" 'H' - Show the SML laguange commands\n");
	printf(" 'L' - Load program from the file (system will ask for the one)\n");
	printf(" 'S' - Save program to the file (just specify ONLY the name)\n");
}

