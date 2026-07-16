/*
 * Here do some math calculation but instead do direct calculation
 * function opearate with memory cells and instead number's result
 * returns the result as memory cell to store it.
 *
 * If expression has only one math operator then value just stored
 * into the temporary cells without intermediate save/load.
 *
 */
#include "evaluate.h"

// Here op1 & op2 is the cell address in memory
uint8_t calculate(uint8_t op1, uint8_t op2, char operator, uint8_t opCount)
{
	uint8_t result;
	int cmd; 
	// uint8_t tmp = getTempCell(); // Temporary Cell
	// printf("TEMP CELL = %d\n", tmp);

	switch(operator) {
		case '+':
			// Load first value (op1) into accumulator
			cmd = LOAD * 100 + op1;
		    memory[CPU.ic++] = cmd;

			// Add value from op2 to accumulator and store it back to acc
			cmd = ADD * 100 + op2;
			memory[CPU.ic++] = cmd;
	
			if (opCount > 1) {
				// Get temporary data cell
				cmd = STORE * 100 + TMPR;

				// Store result in temporary cell
				memory[CPU.ic++] = cmd;
			}

			// Even the opCount == 1 result will be correctly
			// proceeded from the passes.c calling function
			result = TMPR;
			break;
		case '-':
			// Load first value (op1) into accumulator
			cmd = LOAD * 100 + op1;
		    memory[CPU.ic++] = cmd;

			// Add value from op2 to accumulator and store it back to acc
			cmd = SUB * 100 + op2;
			memory[CPU.ic++] = cmd;

			if (opCount > 1) {
				// Get the next free data cell
				cmd = STORE * 100 + TMPR;

				// Store result in temporary cell
				memory[CPU.ic++] = cmd;
			}

			result = TMPR;
			break;
		case '*':
			// Load first value (op1) into accumulator
			cmd = LOAD * 100 + op1;
		    memory[CPU.ic++] = cmd;

			// Add value from op2 to accumulator and store it back to acc
			cmd = MUL * 100 + op2;
			memory[CPU.ic++] = cmd;

			if (opCount > 1) {
				// Get the next free data cell
				cmd = STORE * 100 + TMPR;

				// Store result in temporary cell
				memory[CPU.ic++] = cmd;
			}

			result = TMPR;
			break;
		case '/':
			// Load first value (op1) into accumulator
			cmd = LOAD * 100 + op1;
		    memory[CPU.ic++] = cmd;

			// Add value from op2 to accumulator and store it back to acc
			cmd = DIV * 100 + op2;
			memory[CPU.ic++] = cmd;

			if (opCount > 1) {
				// Get the next free data cell
				cmd = STORE * 100 + TMPR;

				// Store result in temporary cell
				memory[CPU.ic++] = cmd;
			}

			result = TMPR;
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

