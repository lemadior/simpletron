/*
 * Here do some math calculation but instead do direct calculation
 * function opearate with memory cells and instead number's result
 * returns the result as memory cell to store it
 *
 */
#include "evaluate.h"

// Here op1 & op2 is the cell address in memory
uint8_t calculate(uint8_t op1, uint8_t op2, char operator)
{
	uint8_t result;
	int cell, cmd; 
	uint8_t tmp = getTempCell(); // Temporary Cell
	printf("TEMP CELL = %d\n", tmp);

	switch(operator) {
		case '+':
			// Load first value (op1) into accumulator
			cmd = LOAD * 100 + op1;
		    memory[CPU.ic++] = cmd;

			// Add value from op2 to accumulator and store it back (acc)
			cmd = ADD * 100 + op2;
			memory[CPU.ic++] = cmd;
			
			// Get the next free data cell
			cmd = STORE * 100 + tmp;

			// Store result in temporary cell
			memory[CPU.ic++] = cmd;

			result = tmp;
			break;
		case '-':
			// Load first value (op1) into accumulator
			cmd = LOAD * 100 + op1;
		    memory[CPU.ic++] = cmd;

			// Add value from op2 to accumulator and store it back (acc)
			cmd = SUB * 100 + op2;
			memory[CPU.ic++] = cmd;
			
			// Get the next free data cell
			cmd = STORE * 100 + tmp;

			// Store result in temporary cell
			memory[CPU.ic++] = cmd;

			result = tmp;
			break;
		case '*':
			// Load first value (op1) into accumulator
			cmd = LOAD * 100 + op1;
		    memory[CPU.ic++] = cmd;

			// Add value from op2 to accumulator and store it back (acc)
			cmd = MUL * 100 + op2;
			memory[CPU.ic++] = cmd;
			
			// Get the next free data cell
			cmd = STORE * 100 + tmp;

			// Store result in temporary cell
			memory[CPU.ic++] = cmd;

			result = tmp;
			break;
		case '/':
			// Load first value (op1) into accumulator
			cmd = LOAD * 100 + op1;
		    memory[CPU.ic++] = cmd;

			// Add value from op2 to accumulator and store it back (acc)
			cmd = DIV * 100 + op2;
			memory[CPU.ic++] = cmd;
			
			// Get the next free data cell
			cmd = STORE * 100 + tmp;

			// Store result in temporary cell
			memory[CPU.ic++] = cmd;

			result = tmp;
			break;
		// case '%':
			// result = op1 % op2;
			// break;
		// case '^':
			// result = pow(op1, op2);
			// break;
		default:
			result = 0;
	};

	return result;
}

