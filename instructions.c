#include "func.h"

void generateInput(Statement entry)
{
	int pos, cell; // Number of memory cell
	int newEntryPos;

	NEWLINE;
	printf(" In 'generateInput'\n");
	NEWLINE;

	pos = findEntry(entry.var, 'V');

	// if (pos == NOT_FOUND) {
		// cell = CPU.dc--;

		// newEntryPos = findFreeEntry();
	
		// TABLEENTRY[newEntryPos].symbol = entry.var;
		// TABLEENTRY[newEntryPos].type = 'V';
		// TABLEENTRY[newEntryPos].location = cell;
	// } else {
		cell = TABLEENTRY[pos].location;
	// }
	
	memory[CPU.ic++] = READ * 100 + cell;
}


void generatePrint(Statement entry)
{
	int pos, cell; // Number of memory cell
	int newEntryPos;

	NEWLINE;
	printf(" In 'generatePrint'\n");
	NEWLINE;

	pos = findEntry(entry.var, 'V');

	// if (pos == NOT_FOUND) {
		// cell = CPU.dc--;

		// newEntryPos = findFreeEntry();
	
		// TABLEENTRY[newEntryPos].symbol = entry.var;
		// TABLEENTRY[newEntryPos].type = 'V';
		// TABLEENTRY[newEntryPos].location = cell;
	// } else {
		cell = TABLEENTRY[pos].location;
	// }
	
	memory[CPU.ic++] = WRITE * 100 + cell;
}

void generateEnd(Statement entry)
{
	NEWLINE;
	printf(" In 'generateEnd'\n");
	NEWLINE;

	memory[CPU.ic++] = HALT * 100;
}

void generateJump(int jumpto, OpCode jType)
{
	int pos;
	
	NEWLINE;
	printf(" In 'generateJump'\n");
	NEWLINE;

	pos = findEntry(jumpto, 'L');

	// If pos not found it returns 255
	if (pos > SYMBOL_TABLE_SIZE) {
		memory[CPU.ic] = jType * 100; // incomplete cell jump
		flags[CPU.ic++] = jumpto;
	} else {
		memory[CPU.ic++] = jType * 100 + pos;
	}
}

void generateLet(Statement entry, int valueCell)
{
	int pos, cell; // Number of memory cell
	// int newEntryPos;

	// NEWLINE;
	// printf(" In 'generateLet Start'\n");
	// NEWLINE;

	pos = findEntry(entry.var, 'V');
   printf("FPOS=%d\n", pos);
	// if (pos == NOT_FOUND) {
		// cell = TABLEENTRY[pos].location;

		// newEntryPos = findFreeEntry();
	
		// TABLEENTRY[newEntryPos].symbol = entry.var;
		// TABLEENTRY[newEntryPos].type = 'V';
		// TABLEENTRY[newEntryPos].location = cell;
	// } else {
		cell = TABLEENTRY[pos].location;
	// }
	printf("FCELL=%d\n", cell);
	// If valueCell == 255 it means that expression 
	// have operator only one math operator
	// In this case the value has stored in CPU accumulator
	if (valueCell != 255) {
		memory[CPU.ic++] = LOAD * 100 + valueCell;
	}

	memory[CPU.ic++] = STORE * 100 + cell;

	
	NEWLINE;
	printf(" In 'generateLet Start END'\n");
	NEWLINE;
}

void generateIf(uint8_t lValue, uint8_t rValue, char *condition, int jumpto)
{
	NEWLINE;
	printf(" In 'generate -IF-' : ");
	// NEWLINE;

	if (strcasecmp(condition, "==") == 0) {
		printf("EQ\n");
		memory[CPU.ic++] = LOAD * 100 + lValue;
		memory[CPU.ic++] = SUB * 100 + rValue;
		
		generateJump(jumpto, JZERO);

		return;
	}

	if (strcasecmp(condition, ">") == 0) {
		printf("GT\n");
		memory[CPU.ic++] = LOAD * 100 + rValue;
		memory[CPU.ic++] = SUB * 100 + lValue;
		
		generateJump(jumpto, JNEG);

		return;
	}

	if (strcasecmp(condition, "<") == 0) {
		printf("LT\n");
		memory[CPU.ic++] = LOAD * 100 + lValue;
		memory[CPU.ic++] = SUB * 100 + rValue;
		
		generateJump(jumpto, JNEG);

		return;
	}

	if (strcasecmp(condition, "<=") == 0) {
		printf("LTE\n");
		memory[CPU.ic++] = LOAD * 100 + lValue;
		memory[CPU.ic++] = SUB * 100 + rValue;
		
		generateJump(jumpto, JNEG);
		generateJump(jumpto, JZERO);

		return;
	}

	if (strcasecmp(condition, ">=") == 0) {
		printf("GTE\n");
		memory[CPU.ic++] = LOAD * 100 + rValue;
		memory[CPU.ic++] = SUB * 100 + lValue;
		
		generateJump(jumpto, JNEG);
		generateJump(jumpto, JZERO);
	}
}



int checkVar(char varName)
{
	int pos, cell; // Number of memory cell
	// int newEntryPos;

	// NEWLINE;
	// printf(" In 'checkVar'\n");
	// NEWLINE;

	pos = findEntry(varName, 'V');

	// if (pos == NOT_FOUND) {
		// cell = CPU.dc--;

		// newEntryPos = findFreeEntry();
	
		// TABLEENTRY[newEntryPos].symbol = varName;
		// TABLEENTRY[newEntryPos].type = 'V';
		// TABLEENTRY[newEntryPos].location = cell;
	// } else {
		cell = TABLEENTRY[pos].location;
	// }
	
	return cell;
}

int checkConst(const char *number)
{
	int pos, cell; // Number of memory cell
	// int newEntryPos;
	int num;

	// NEWLINE;
	// printf(" In 'checkConst'\n");
	// NEWLINE;

	num = atoi(number);
	// If enry hasn't been found findEntry do search first free cell
	// of the TABLEENTRY and manipulate with CPU.dc
	pos = findEntry(num, 'C');
	// printf("NUM=%d NUMB=%s POS=%d\n", num, number, pos);
	// if (pos == NOT_FOUND) {
		// cell = CPU.dc;

		// newEntryPos = findFreeEntry();
	
		// TABLEENTRY[newEntryPos].symbol = num;
		// TABLEENTRY[newEntryPos].type = 'C';
		// TABLEENTRY[newEntryPos].location = cell;

	// } else {
		cell = TABLEENTRY[pos].location;
	// }
	
	// if (memory[cell] == UNOP_CMD) {
		// memory[CPU.dc] = num;
	// }

	return cell;
}
