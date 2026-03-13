/**
 * @file welcome.c
 * @author lemadior (https://github.com/lemadior/simpletron)
 * @brief Welcome message when simulator has started
 * @details contains short help for usage the system
 * @version 0.1 
 * @date 2026-03-12
 * * @copyright Copyright (c) 2026
 * */

#include "sml.h"

void welcomeMsg(void)
{
	NEWLINE;
	printf(" ### SIMPLETRON ###\n");
	printf(" ------------------\n");
	printf("\n Welcome to the Simpletron!\n");
	printf(" The basic workspace for the SML language.\n");
	NEWLINE;
	printf(" To get short help just type the '?' symbol\n");
	printf(" To exit from console type the 'X' (x) symbol\n");
	NEWLINE;
}

