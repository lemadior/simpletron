#include "func.h"

void generateInput(Statement entry)
{
	int pos, cell; // Number of memory cell
	int newEntryPos;

	NEWLINE;
	printf(" In 'generateInput'\n");
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

	if (pos != NOT_FOUND) {
		cell = TABLEENTRY[pos].location;
	} else {
		cell = CPU.dc--;
	}
	
	newEntryPos = findFreeEntry();
	
	TABLEENTRY[newEntryPos].symbol = entry.var;
	TABLEENTRY[newEntryPos].type = 'V';
	TABLEENTRY[newEntryPos].location = cell;

	memory[CPU.ic++] = WRITE * 100 + cell;
}

