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

#include "slc.h"

void showHelp(void)
{
	NEWLINE;

	printf(" SIMPLE language compiler commands HELP:\n");
	printf(" ---------------------------------------\n");
	printf("\n '-h' - Show the short help\n");
	printf(" '-d' - print memory and cpu vaiables\n");
	printf(" '-o' - specify program filename (just specify ONLY the name)\n");
}

