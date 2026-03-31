#include "postfix.h"

char infix[INPUT_SIZE];
char postfix[INPUT_SIZE];
STACKNODEPTR stack;

int main(void)
{	
	stack = NULL;

	getExpression();

	convertToPostfix(infix, postfix);

	printf("Postfix: %s\n", postfix);

	printf("Coniec\n");

	return 0;
}


