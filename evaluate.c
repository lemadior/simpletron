#include "evaluate.h"


uint8_t getNumber(char);
int getValue(char *);

int evaluatePostfixExpression(const char *source)
{
	char chr;
	char buff[2] = {E_VALUE, E_VALUE}; 
	uint8_t x, y, tmp, i = 0;

	while((chr = *source++) != '\0') {
		if (chr == ' ') {
			tmp = getValue(buff);
	
			if (tmp >= E_VALUE || tmp <= E_VALUE*(-1)) {
				printf("Value %d is out of allowd range (-99:99)!\n");

				return E_VALUE;
			}

			push(&stack, tmp);

			printStack(stack);			
			
			buff[0] = E_VALUE;
			buff[1] = E_VALUE;
			i = 0;

			continue;
		}

		// If chr is numeric symbol just store it to teh postfix
		if (isdigit(chr)) {
			buff[i++] = chr;	

			continue;
		}

		// If we go here it means that we got some of math operator 
		x = pop(&stack);
		y = pop(&stack);

		// Calculate the value and push it back to teh stack
		// First argument should be y!
		push(&stack, calculate(y, x, chr));

		printStack(stack);
	}

	return pop(&stack);
}


// Convert value from
int getValue(char *buff)
{
	int result = 0;
	
	if (*buff != E_VALUE) {
		result = getNumber(*buff) * 10; // 48 is value for '0' symbol
	}
	
	buff++;

	if (*buff != E_VALUE) {
		result += getNumber(*buff);
	}


	return result;
}

uint8_t getNumber(char num)
{
	return num - 48; // 48 is value for '0' symbol
}

