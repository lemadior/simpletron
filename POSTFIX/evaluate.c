/*
 * Here an evaluate the math expression prepared by INFIX
 * Instead of direct calculation of values the memory cells
 * used to it.
 */

#include "evaluate.h"
#include "func.h"

#define BUFF_SIZE 2

uint8_t getNumber(char);
uint8_t getNumAddr(char *);
STACKNODEPTR stack;
uint8_t getVarAddr(char var);

int evaluatePostfixExpression(const char *source)
{
	char chr;
	char buff[2] = {E_VALUE, E_VALUE}; // buff[0] first digit
									   // buff[0] second or only digit
	int x, y, cell;
	uint8_t bufPos = BUFF_SIZE - 1; // Counter for buff (to allow 2 digit numbers) 
	uint8_t isCalc = 0; // Flag to indicate success math operation 
	uint8_t isVar = 0;  // Flag to indicate that previous value was a var!
    uint8_t tmp;

	printf("IN EVALUATE FUNCTION %s\n", source);
	printf("pSTACK BEF: ");
	printStack(stack);

	// If expression just variable or constant number
	if (checkOperationsAmount(source) == 0) {
		printf("IF source: %s\n", source);
		/*
		 * Because expression (source) doesn't have any math operators,
		 * so it means that 'source' contains or just number or var name
		 * NOTE: number can be more than one digit!
		 */
		if(isAllNumeric(source)) {
			return TABLEENTRY[findEntry(atoi(source), 'C')].location;	
		} else {
			return TABLEENTRY[findEntry(source[0], 'V')].location;
		}	
	}

	// return 0;
	while((chr = *source++) != '\0') {
		// printf("CHR=%c\n", chr);
		if (chr == ' ') {
			// If previous symbol was a math operator just skip this SPACE
			if (isCalc) {
				isCalc = 0;

				continue;
			}

			// If previous symbol was a variable symbol
			if (isVar) {
				isVar = 0;

				continue;
			}

			// Get number from string representation
			tmp = getNumAddr(buff);
			// printf("N-Tmp=%d\n", tmp);
			if (tmp >= E_VALUE || tmp <= E_VALUE*(-1)) {
				ERROR("Const value %d is out of allowed range (-99:99)!", tmp);
			}

			push(&stack, tmp);

			// printStack(stack);			
			
			// Clean the buffer

		    memset(buff, E_VALUE, sizeof(buff)); 
			// for (i = 0; i < BUFF_SIZE; i++) {
				// buff[i] = E_VALUE;
			// }
			
			bufPos = BUFF_SIZE - 1;

			continue;
		}

		// If chr is numeric symbol just store it to the postfix
		if (isdigit(chr)) {
			if (bufPos < BUFF_SIZE - 1) {
				buff[bufPos] = buff[bufPos+1]; // Shift unit to decimal 
			}

			buff[BUFF_SIZE - 1] = chr;	
			bufPos--;

			continue;
		}

		if (isalpha(chr)) {
			tmp = getVarAddr(chr);

			if (tmp >= E_VALUE || tmp <= E_VALUE*(-1)) {
				ERROR("Var value %c = %d is out of allowed range (-99:99)!", chr, tmp);
			}

			printf("A-tmp %d\n", tmp);
			push(&stack, tmp);

			isVar = 1;

			continue;
		}

		// If we go here it means that we got some of math operator 
		x = pop(&stack);
		y = pop(&stack);

		// Calculate the value and push it back to the stack
		// First argument should be y!
		tmp = calculate(y, x, chr);
		// printf("CALC=%d\n", tmp);
		push(&stack, tmp);

		// printStack(stack);

		isCalc = 1;
	}

	cell = pop(&stack);
	
	printf("pSTACK AFT: ");
	printStack(stack);

	return cell;
}

// Convert value from string
uint8_t getNumAddr(char *buff)
{
	uint8_t result = 0;
	if (*buff != E_VALUE) {
		printf("BUFF =%c", *buff);
		result = getNumber(*buff) * 10;
	}

	if (*(buff+1) != E_VALUE) {
		printf("%c\n", *(buff+1));
		result += getNumber(*(buff+1));
	}

	return TABLEENTRY[findEntry(result, 'C')].location;
}

uint8_t getVarAddr(char var)
{
	printf("VARR=%c\n", var);
	return TABLEENTRY[findEntry(var, 'V')].location;
}

// Get number from char
uint8_t getNumber(char num)
{
	return num - 48; // 48 is value for '0' symbol
}

bool isAllNumeric(const char *str)
{
	while(*str != '\0') {
		if(!isdigit(*str++)) {
			return false;
		}
	}

	return true;
}
