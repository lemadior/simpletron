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

/* SIMPLE language command */
typedef enum {
	SL_UNKNOWN = 0,		// All not defined values
	SL_REM = 1,			// Command for comment
	SL_REM_SM = 11,		// Shortcut for REM
	SL_INPUT = 2,		// Save value to variable from sdtin
	SL_INPUT_SM = 21,	// Shortcut for INPUT
	SL_LET = 3,			// Save value to variable
	SL_LET_SM = 31,		// Shortcut for LET
	SL_PRINT = 4,		// Print value to stdout from variable
	SL_PRINT_SM = 41,	// Shortcut for PRINT
	SL_GOTO = 5,		// Jump to specified line
	SL_GOTO_SM = 51,	// Shortcut for GOTO
	SL_IF = 6,			// Conditions
	SL_IF_SM = 61,		// Shortcut for IF
	SL_END = 7,			// End of program (terminete execution)
	SL_END_SM = 71		// Shortcut for END
} Commands;

// TableEntry Entites
typedef enum {
	E_SYMBOL = 0,
	E_TYPE = 1,
	E_LOCATION = 2
} Entries;

#endif

