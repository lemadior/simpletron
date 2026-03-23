#include "postfix.h"

void convertToPostfix(const char *source, char *target)
{
	char chr;
	//char stackChr;
	//uint8_t comparation;

	while((chr = *source++) != '\0') {
		printStack(stack);

		// If chr is numeric symbol just store it to teh postfix
		if (isdigit(chr)) {
			*target++ = chr;

			continue;
		}

		// If start parenthensis just save it to the stack
		if (chr == '(') {
			push(&stack, chr);

			continue;
		}

		// If chr is closed parenthensis - save to postfix all the stack
		// until opened '(' is occurs 
		if (chr == ')') {
			while ((chr = pop(&stack)) != '(') {
				*target++ = chr;
			}

			continue;
		}

		// Here the chr contains some of math operator
		// If stack is empty - put into any expression operator
		// here don't worry about priority
		if (isEmpty(stack)) {
			push(&stack, chr);

			continue;
		}

		//if (chr == OP_ADD || chr == OP_SUB) {
		//stackChr = stackTop(&stack);
		
		while(!isEmpty(stack) && stackTop(&stack) != '(' && precendence(chr, stackTop(&stack)) <= 0) {
			printStack(stack);
			*target++ = pop(&stack);
		}
		
		push(&stack, chr);
	}
	
	*target = chr;
}

