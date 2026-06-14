#include "func.h"

void generateInput(Statement entry)
{
	int pos, cell; // Number of memory cell
	int newEntryPos;

	NEWLINE;
	printf(" In 'generateInput'\n");
	NEWLINE;

	pos = findEntry(entry.var, 'V');

	if (pos == NOT_FOUND) {
		cell = CPU.dc--;

		newEntryPos = findFreeEntry();
	
		TABLEENTRY[newEntryPos].symbol = entry.var;
		TABLEENTRY[newEntryPos].type = 'V';
		TABLEENTRY[newEntryPos].location = cell;
	} else {
		cell = TABLEENTRY[pos].location;
	}
	
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

	if (pos == NOT_FOUND) {
		cell = CPU.dc--;

		newEntryPos = findFreeEntry();
	
		TABLEENTRY[newEntryPos].symbol = entry.var;
		TABLEENTRY[newEntryPos].type = 'V';
		TABLEENTRY[newEntryPos].location = cell;
	} else {
		cell = TABLEENTRY[pos].location;
	}
	
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
		memory[CPU.ic] = 4000; // incomplete cell jump
		flags[CPU.ic++] = jumpto;
	} else {
		memory[CPU.ic++] = jType * 100 + pos;
	}
}

void generateLet(Statement entry, int valueCell)
{
	int pos, cell; // Number of memory cell
	int newEntryPos;

	NEWLINE;
	printf(" In 'generateLet'\n");
	NEWLINE;

	pos = findEntry(entry.var, 'V');

	if (pos != NOT_FOUND) {
		cell = TABLEENTRY[pos].location;
	} else {
		cell = CPU.dc--;
	}
	
	newEntryPos = findFreeEntry();
	
	TABLEENTRY[newEntryPos].symbol = entry.var;
	TABLEENTRY[newEntryPos].type = 'V';
	TABLEENTRY[newEntryPos].location = cell;

	memory[CPU.ic++] = LOAD * 100 + valueCell;
	memory[CPU.ic++] = STORE * 100 + cell;
}

void generateIf(uint8_t lValue, uint8_t rValue, char *condition, int jumpto)
{
	if (strcasecmp(condition, "==") == 0) {
		memory[CPU.ic++] = LOAD * 100 + lValue;
		memory[CPU.ic++] = SUB * 100 + rValue;
		
		generateJump(jumpto, JZERO);
	}

	if (strcasecmp(condition, ">") == 0) {
		memory[CPU.ic++] = LOAD * 100 + rValue;
		memory[CPU.ic++] = SUB * 100 + rValue;
		
		generateJump(jumpto, JNEG);
	}

	if (strcasecmp(condition, "<") == 0) {
		memory[CPU.ic++] = LOAD * 100 + lValue;
		memory[CPU.ic++] = SUB * 100 + rValue;
		
		generateJump(jumpto, JNEG);
	}

	if (strcasecmp(condition, "<=") == 0) {
		memory[CPU.ic++] = LOAD * 100 + lValue;
		memory[CPU.ic++] = SUB * 100 + rValue;
		
		generateJump(jumpto, JNEG);
		generateJump(jumpto, JZERO);
	}

	if (strcasecmp(condition, ">=") == 0) {
		memory[CPU.ic++] = LOAD * 100 + rValue;
		memory[CPU.ic++] = SUB * 100 + lValue;
		
		generateJump(jumpto, JNEG);
		generateJump(jumpto, JZERO);
	}
}

