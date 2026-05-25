#include "func.h"
#include "convert.h"

int checkVar(char);

// Generate the postfix representation of arithmetic expression
// Each element will be divided by SPACE symbol!
void convertToPostfix(const char *source, char *target)
{
	char chr;

	printf("IN CONVERT FUNCTION\n");

	return;

	while((chr = *source++) != '\0') {
		if (chr == ' ') {
			continue;
		}
			
		// printStack(stack);

		// If chr is numeric symbol just store it to the postfix
		if (isdigit(chr)) {
			*target++ = chr;

			continue;
		}
		
		if (*(target-1) != ' ') {
			*target++ = ' ';
		}

		// If start parenthensis just save it to the stack
		if (chr == '(') {
			push(&stack, (int)chr);

			continue;
		}

		// If chr is closed parenthensis - save to postfix all the stack
		// until opened '(' is occurs 
		if (chr == ')') {
			while ((chr = (char)pop(&stack)) != '(') {
				*target++ = chr;

				*target++ = ' ';
			}

			continue;
		}

		// Here need to check if chr is alphabetic char 
		// If so - the new var saved int the TABLEENTRY or just saved into the INFIX
		// TODO: correctly add the name of variable to the INFIX
		if (isalpha(chr)) {
			checkVar(chr);
			
			continue;
		}

		// Here the chr contains some of math operator
		// If stack is empty - put into any expression operator
		// here don't worry about priority
		if (isEmpty(stack)) {
			push(&stack, (int)chr);

			continue;
		}

		while(!isEmpty(stack) && (char)stackTop(&stack) != '(' && precendence(chr, (char)stackTop(&stack)) <= 0) {
			// printStack(stack);
			
			*target++ = (char)pop(&stack);

			*target++ = ' '; // This need to add SPACE after last operator
							 // returned from stack
		}
		
		push(&stack, (int)chr);
	}

	// Get the rest of the stack
	while(!isEmpty(stack)) {
		// printStack(stack);
		*target++ = ' ';

		*target++ = (char)pop(&stack);
	}
	
	*target = '\0';
}

int checkVar(char varName)
{
	int pos, cell; // Number of memory cell
	int newEntryPos;

	NEWLINE;
	printf(" In 'checkVar'\n");
	NEWLINE;

	pos = findEntry(varName, 'V');

	if (pos == NOT_FOUND) {
		cell = CPU.dc--;

		newEntryPos = findFreeEntry();
	
		TABLEENTRY[newEntryPos].symbol = varName;
		TABLEENTRY[newEntryPos].type = 'V';
		TABLEENTRY[newEntryPos].location = cell;
	} else {
		cell = TABLEENTRY[pos].location;
	}
	
	return cell;
}

