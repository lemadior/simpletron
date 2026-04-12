#include "func.h"
#include "evaluate.h"

int calculate(int op1, int op2, char operator)
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

