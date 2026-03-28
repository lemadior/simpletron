#include "postfix.h"


char postfix[INPUT_SIZE];
STACKNODEPTR stack;

int main(void)
{	
	int result;

	stack = NULL;

	getExpression();

	result = evaluatePostfixExpression(postfix);

	if (result == E_VALUE) {
		printf("ERROR: wrong input value!");

		return 0;
	}

	printf("Result: %d\n", result);

	printf("Coniec\n");

	return 0;
}


