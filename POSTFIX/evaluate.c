/*
 * Here an evaluate the math expression prepared by INFIX
 * Instead of direct calculation of values the memory cells
 * used to it.
 *
 * Return: address of memory cell where has stored the result value
 */

#include "evaluate.h"
#include "func.h"

#define BUFF_SIZE 3

uint8_t getNumber(char);
uint8_t getNumAddr(char *);
STACKNODEPTR stack;
uint8_t getVarAddr(char var);

int evaluatePostfixExpression(const char *source)
{
	char  prevChr = '\0', chr;
	char buff[3] = {0, 0, 0}; // buff[0] first digit
									   // buff[0] second or only digit
	int x, y, cell;
	uint8_t bufPos = 0; // Counter for buff (to allow 2 digit numbers) 
	uint8_t isCalc = 0; // Flag to indicate success math operation 
	uint8_t isVar = 0;  // Flag to indicate that previous value was a var!
    uint8_t tmp, opCount = 0;

	printf("IN EVALUATE FUNCTION %s\n", source);
	printf("pSTACK BEF: ");
	printStack(stack);

	// Count of math operator(s) in expression
	opCount = checkOperationsAmount(source);

	// If expression just variable or constant number
	if (opCount == 0) {
		/* Because expression (source) doesn't have any math operators,
		 * so it means that 'source' contains or just number or var name
		 * NOTE: number can be more than one digit!
		 */
		if(isAllNumeric(source)) {
			// tmp = findEntry(atoi(source), 'C');
			// memory[CPU.dc] = atoi(source);
			// return TABLEENTRY[tmp].location;
			return checkConst(source);
		} else {
			// return TABLEENTRY[findEntry(source[0], 'V')].location;
			return checkVar(source[0]);
		}	
	}

	while((chr = *source++) != '\0') {
		// printf("CHR=%c\n", chr);
		if (chr == ' ') {
			prevChr = chr;
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
			tmp = checkConst(buff);

			// printf("N-Tmp=%d\n", tmp);
			if (tmp >= E_VALUE || tmp <= E_VALUE*(-1)) {
				ERROR("Const value %d is out of allowed range (-99:99)!", tmp);
			}

			push(&stack, tmp);

			// printStack(stack);			
			
			// Clean the buffer

		    memset(buff, 0, sizeof(buff)); 
			// for (i = 0; i < BUFF_SIZE; i++) {
				// buff[i] = E_VALUE;
			// }
			
			// bufPos = BUFF_SIZE - 1;
			bufPos = 0;
			continue;
		}

		// If chr is numeric symbol just store it to the postfix
		if (isdigit(chr)) {
			// if (bufPos < BUFF_SIZE - 1) {
				// buff[bufPos] = buff[bufPos+1]; // Shift unit to decimal 
			// }

			// buff[BUFF_SIZE - 1] = chr;	
			// bufPos--;

			if (bufPos == 2) {
				continue;
			}

			buff[bufPos++] = chr; 

			continue;
		}

		if (isalpha(chr)) {
			tmp = checkVar(chr);

			if (tmp >= E_VALUE || tmp <= E_VALUE*(-1)) {
				ERROR("Var value %c = %d is out of allowed range (-99:99)!", chr, tmp);
			}

			// printf("A-tmp %d\n", tmp);
			push(&stack, tmp);

			isVar = 1;

			continue;
		}

		// If we go here it means that we got some of math operator 
		x = pop(&stack);
		y = pop(&stack);

		// Calculate the value and push it back to the stack
		// First argument should be y!
		tmp = calculate(y, x, chr, opCount);
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
// uint8_t getNumAddr(char *buff)
// {
	// uint8_t result = 0;

	// printf("CONST=%d\n", atoi(buff));
	// if (*buff != E_VALUE) {
		// printf("BUFF =%c", *buff);
		// result = getNumber(*buff) * 10;
	// }

	// if (*(buff+1) != E_VALUE) {
		// printf("%c\n", *(buff+1));
		// result += getNumber(*(buff+1));
	// }
	
	// result = findEntry(atoi(buff), 'C');
	// printf("CONST ADDR = %d FIUND=%d\n", TABLEENTRY[result].location, TABLEENTRY[findEntry(atoi(buff), 'C')].location);
	// return TABLEENTRY[result].location;
// }

// uint8_t getVarAddr(char var)
// {
	// printf("VARR=%c\n", var);
	// return TABLEENTRY[findEntry(var, 'V')].location;
// }

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
