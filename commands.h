/**
 * @file commands.h
 * @author lemadior
 * @brief SML as system as operation commands
 * @version 0.2.0
 * @date 2026-03-16
 * * @copyright Copyright (c) 2026
 * */

#ifndef COMMANDS_H
#define COMMANDS_H

typedef enum {
	/* System commands (not microcode) 
	 * use it for enter the new program
	 */
	NOP = 0,			// No Operation
	HELP = 1,			// Show the short help (operand is command value)
	LIST = 2,			// Print the program to terminal (operand is start cell, default = 00)
	EDIT = 3,			// Edit command or data by specified address
	STOP = 5,			// Exit from new program mode
	DATA = 9,			// Enter the value for memory cell (operand is cell address)

	/* I/O command */ 
	READ = 10,			// Read word from terminal
	WRITE = 11,			// Put word to the terminal

	/* Load/Store operations */

	LOAD = 20,			// Put word from specified memory address to the accumulator
	STORE = 21,			// Get word from the accumulator and store it in the specified adddress

	/* Math operations */

	ADD = 30,			// Add the value from accumulator and from the specified address
						// and store the result back into the accumulator

	SUB = 31,				// Subtrct the value from accumulator and from the specified address
						// and store the result back into the accumulator

	DIV = 32,				// Divide the value from accumulator and from the specified address
						// and store the result back into the accumulator

	MUL = 33,				// Multiple the value from accumulator and from the specified address
						// and store teh result back into the accumulator

	/* Jump instructions */

	JUMP = 40,			// Jump into the specified address
	JNEG = 41,		    // Jump into specified address if accumulator's value < 0
	JZERO = 42,		    // Jump into specified address if accumulator's value = 0

	/* System commands */

	HALT = 43			// Stop program execution
} OpCode;

/* Workspace command */
typedef enum {
	CMD_EXIT = 88,			// Exit workspace
	CMD_EXIT_SM = 120,		// Exit program (small letter)
	CMD_DUMP = 68,			// Print memory dump
	CMD_DUMP_SM = 100,		// Print dump (smal letter)
	CMD_NEW = 78,			// Create the new program
	CMD_NEW_SM = 110,		// Create the new program (small letter) 
	CMD_EDIT = 69,			// Edit mode (edit SML program)
	CMD_EDIT_SM = 101,		// Edit program (small letter)
	CMD_LIST = 86,			// Show program listing
	CMD_LIST_SM = 118,		// Show listing (small letter)
	CMD_RUN = 82,			// Run SML program
	CMD_RUN_SM = 114,		// Run program (small letter) 
	CMD_SML_HELP = 72,		// Short help for SML commands
	CMD_SML_HELP_SM = 104,  // SML help (small letter)
	CMD_HELP = 63,			// Short workspace help
	CMD_LOAD = 76,			// Load program from file
	CMD_LOAD_SM = 108,      // Short alias for Load program
	CMD_SAVE = 83,          // Save program to file
	CMD_SAVE_SM = 115       // Short alias for Save program
} Commands;

#endif

