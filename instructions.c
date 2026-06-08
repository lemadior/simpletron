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
	NEWLINE;
	printf(" In 'generateJump'\n");
	NEWLINE;

	memory[CPU.ic++] = jType * 100 + jumpto;
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

