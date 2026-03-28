#include "evaluate.h"

int calculate(uint8_t op1, uint8_t op2, char operator)
{
	int result;

	switch(operator) {
		case '+':
			result = op1 + op2;
			break;
		case '-':
			result = op1 - op2;
			break;
		case '*':
			result = op1 * op2;
			break;
		case '/':
			result = op1 / op2;
			break;
		case '%':
			result = op1 % op2;
			break;
		case '^':
			result = pow(op1, op2);
			break;
		default:
			result = 0;
	};

	return result;
}

/*
uint8_t isOperator(char c)
{
	if (isdigit(c) || c == ')' || c == '(') {
		return false;
	}

	return true;
}


// '(' has lowest priority
// '-' and '+' has middle priority
// other expression symbols has higher priority
int8_t precendence(char op1, char op2)
{
	int8_t priority[2] = {1, 1};

	if (op1 == OP_ADD || op1 == OP_SUB) {
		priority[0] = 0;
	}

	if (op2 == OP_ADD || op2 == OP_SUB) {
		priority[1] = 0;
	} else if (op2 == '(') {
		priority[1] = -1;
	}

	if (priority[0] < priority[1]) {
		return -1; 
	} else if (priority[0] == priority[1]) {
		return 0;
	} 
	
	return 1;
}
*/
