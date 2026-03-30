#include "evaluate.h"

uint8_t getNumber(char);
int getValue(char *);

int evaluatePostfixExpression(const char *source)
{
	char chr;
	char buff[2] = {E_VALUE, E_VALUE}; // buff[0] first digit
									   // buff[0] second or only digit
	uint8_t x, y;
	uint8_t i = 1; // Counter for buff (to allow 2 digit numbers) 
	uint8_t isCalc = 0; // Flag to indicate success math operation 
    int tmp;

	while((chr = *source++) != '\0') {
		if (chr == ' ') {
			// If previous symbol was a math operator
			if (isCalc == 1) {
				isCalc = 0;

				continue;
			}

			// Get number from string representation
			tmp = (uint8_t)getValue(buff);

			if (tmp >= E_VALUE || tmp <= E_VALUE*(-1)) {
				printf("Value %d is out of allowd range (-99:99)!\n", tmp);

				return E_VALUE;
			}

			push(&stack, tmp);

			printStack(stack);			
			
			buff[0] = E_VALUE;
			buff[1] = E_VALUE;
			i = 1;

			continue;
		}

		// If chr is numeric symbol just store it to the postfix
		if (isdigit(chr)) {
			buff[i--] = chr;	

			continue;
		}

		// If we go here it means that we got some of math operator 
		x = pop(&stack);
		y = pop(&stack);

		// Calculate the value and push it back to teh stack
		// First argument should be y!
		push(&stack, calculate(y, x, chr));

		printStack(stack);

		isCalc = 1;
	}

	return pop(&stack);
}

// Convert value from string
int getValue(char *buff)
{
	int result = 0;


	if (*(buff) != E_VALUE) {
		result = getNumber(*buff) * 10;
	}

	if (*(buff+1) != E_VALUE) {
		result += getNumber(*(buff+1));
	}

	return result;
}

// Get number from char
uint8_t getNumber(char num)
{
	return num - 48; // 48 is value for '0' symbol
}

