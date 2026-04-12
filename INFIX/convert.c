#include "func.h"
#include "convert.h"

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

