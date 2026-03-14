/**
 * @file run.c
 * @author lemadior (https://github.com/lemadior/simpletron)
 * @brief A module responsible for execution SML instructions
 * @details here the progrem is executed
 * @version 0.2.0
 * @date 2026-03-12
 * * @copyright Copyright (c) 2026
 * */

#include "sml.h"

void readData(short *);
short addNum(uint8_t);
short subNum(uint8_t);
short divNum(uint8_t);
short mulNum(uint8_t);

void runProgram(void)
{
	short tmp;
	uint8_t stop = 1; // Flag to determine that program should be stopped 

	NEWLINE;
	if (memory[0] >= UNOP_CMD) {
		printf(" No program found in memory! Exiting...\n");
		
		return;
	}

	printf(" Run current program...\n");
	printf(" ----------------------\n");
	
	NEWLINE;

	CPU.ic = 0;
	CPU.acc = 0;
	CPU.instr = 0;
	CPU.cmd = 0;
	CPU.op = 0;

	while((CPU.instr = memory[CPU.ic]) != HALT && stop != 0) {
		CPU.cmd = getCode(CPU.instr);
		CPU.op = getOperand(CPU.instr);

		if (++CPU.ic >= MEMORY_SIZE) {
			printf(" ERROR: out of range! Exiting...\n");

			break;
		}

		switch(CPU.cmd) {
			case NOP:
				break;
			case READ:
				readData(&memory[CPU.op]);
				NEWLINE;
				break;
			case WRITE:
				printf("Out:(%2.2d)", CPU.op);
				printf("# %4.4d\n", memory[CPU.op]);
				break;
			case LOAD:
				CPU.acc = memory[CPU.op];
				break;
			case STORE:
				memory[CPU.op] = CPU.acc;
				break;
			case ADD:
				tmp = addNum(CPU.op);

				if (tmp == ERROR_CMD) {
					stop = 0;
				} else {
					CPU.acc = tmp;
				}

				break;
			case SUB:
				tmp = subNum(CPU.op);

				if (tmp == ERROR_CMD) {
					stop = 0;
				} else {
					CPU.acc = tmp;
				}

				break;
			case DIV:
				tmp = divNum(CPU.op);

				if (tmp == ERROR_CMD) {
					stop = 0;
				} else {
					CPU.acc = tmp;
				}

				break;
			case MUL:
				tmp = mulNum(CPU.op);

				if (tmp == ERROR_CMD) {
					stop = 0;
				} else {
					CPU.acc = tmp;
				}

				break;
		}
	}

	NEWLINE;
	printf(" SML program ended!\n");
}

// Read value from STDIO
void readData(short *cell)
{
	short var;
	
	var = ERROR_CMD;

	while (var == ERROR_CMD) {

		printf("In:[%2.2d]? ", CPU.op);

		// Get number or error if value has wrong format
		var = getOnlyNumbers();

		if (var == ERROR_CMD) {
			printf(" Wrong value! Try again\n");
			NEWLINE;

			continue;
		} 
		
		break;
	}

	*cell = var;
}

// Add value from addr to accumulator's value
short addNum(uint8_t addr)
{
	short tmp = CPU.acc + memory[addr];

	if (tmp >= UNOP_CMD || tmp <= ERROR_CMD) {
		printf(" Err: CMD:%2.2d OP:%2.2d caused out of range!\n", CPU.cmd, CPU.op);
		printf(" Program will stop\n");
		
		return ERROR_CMD;
	}
		
	return tmp;
}


// Sub accumulator's value a value from memory (by addr)
short subNum(uint8_t addr)
{
	short tmp = CPU.acc - memory[addr];

	if (tmp <= ERROR_CMD || tmp >= UNOP_CMD) {
		printf(" Err: CMD:%2.2d OP:%2.2d caused out of range!\n", CPU.cmd, CPU.op);
		printf(" Program will stop\n");
		
		return ERROR_CMD;
	}
		
	return tmp;
}

// Divide value from accumulator by value in memory
short divNum(uint8_t addr)
{	
	if (memory[addr] == 0) {
		printf(" Err: CMD:%2.2d OP:%2.2d caused divide by zero!\n", CPU.cmd, CPU.op);
		printf(" Program will stop\n");

		return ERROR_CMD;
	} else if (memory[addr] <= ERROR_CMD || memory[addr] >= UNOP_CMD) {
		printf(" Err: CMD:%2.2d OP:%2.2d caused out of range!\n", CPU.cmd, CPU.op);
		printf(" Program will stop\n");
				
		return ERROR_CMD;	
	}
	
	return CPU.acc / memory[addr];
}

// Multiple value in accumulator by valye from memory
short mulNum(uint8_t addr)
{
	int tmp;

	tmp = memory[addr] * CPU.acc;
	
	if (tmp <= ERROR_CMD || tmp >= UNOP_CMD) {
		printf(" Err: CMD:%2.2d OP:%2.2d caused out of range!\n", CPU.cmd, CPU.op);
		printf(" Program will stop\n");
				
		return ERROR_CMD;	
	}
	
	return (short)tmp;
}

