#include "../func.h"
#include "convert.h"

// int checkVar(char);
// int checkConst(char *number);
// STACKNODEPTR stack;

// void printStack(STACKNODEPTR);
// Generate the postfix representation of arithmetic expression
// Each element will be divided by SPACE symbol!
void convertToPostfix(const char *source, char *target)
{
	char chr;
	char nums[16] = {0};
	char *num = &nums[0];
	uint8_t isNum = 0, isSpace = 0;
	printf("--- IN CONVERT FUNCTION ---: %s\n", source);
	printf("iSTACK BEF: ");
	printStack(stack);

	while((chr = *source++) != '\0') {
		// printf("CHR=%c\n", chr);
		// printf("TARGET=%s\n", target);
		// printStack(stack);
		if (chr == ' ') {
			continue;
		}
			
		// If chr is numeric symbol just store it to the postfix
		if (isdigit(chr)) {
			*target++ = chr;
			
			isNum = 1;
			*num++ = chr;

			continue;
		}
	
		// Here is alphabet symbol only passed
		// Check if previos symbol is not the SPACE
		// and if the at least one symbol is passed to `target'
		if (*(target-1) != ' ' && *(target-1) != 0) {
			// printf("CHECK isNum=%d CHR=%c\n", isNum, *(target-1)); 
			
			*target++ = ' ';
			
			if (isNum == 1) {
				// printf("IN NUM\n");
				isNum = 0;
				*num = '\0';
				num = &nums[0];	
		
				checkConst(num);
			}
		}

		// Here need to check if chr is alphabetic char 
		// If so - the new var saved into the TABLEENTRY or just saved into the INFIX
		if (isalpha(chr)) {
			checkVar(chr);
		
			*target++ = chr;

			continue;
		}

		// If start parenthensis just save it to the stack
		if (chr == '(') {
			push(&stack, (int)chr);

			continue;
		}

		// If chr is closed parenthensis - save to postfix all the stack
		// until opened '(' is occurs 
		if (chr == ')') {
			// printf("In close parenthensis\n");
			isSpace = *target == ' ';

			while ((chr = (char)pop(&stack)) != '(') {
				*target++ = chr;
				
				*target++ = ' ';
			}

			if (isSpace) {
				target--;
			}

			continue;
		}

		// Here the chr contains some of math operator
		// If stack is empty - put into any expression operator
		// here don't worry about priority
		if (isEmpty(stack)) {
			push(&stack, (int)chr);
			// printf("IN Stack at FIRST CHR=%c\n", chr);
			continue;
		}

		while(!isEmpty(stack) && (char)stackTop(&stack) != '(' && precendence(chr, (char)stackTop(&stack)) <= 0) {
			// printStack(stack);
			// printf("IN STACKi=%c\n", (char)stackTop(&stack));			
			*target++ = (char)pop(&stack);

			*target++ = ' '; // This need to add SPACE after last operator
							 // returned from stack
		}
		
		push(&stack, (int)chr);
	}

	if (isNum == 1) {
		*num = '\0';
		// printf("IN LAST NUM NUM=%s\n", num);
	
		checkConst(&nums[0]);
	}

	// Get the rest of the stack
	while(!isEmpty(stack)) {
		// printStack(stack);
		if (*(target-1) != ' ') {
			*target++ = ' ';
		}

		*target++ = (char)pop(&stack);
	}

	// printf("iSTACK AFT: ");
	// printStack(stack);

	*target = '\0';
}

