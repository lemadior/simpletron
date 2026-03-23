#include "postfix.h"


//void push(STACKNODEPTR *,int);
//int pop(STACKNODEPTR *);
//int isEmpty(STACKNODEPTR);
//void printStack(STACKNODEPTR);
//void instructions(void);

int main(void)
{	
	STACKNODEPTR stackPtr = NULL;
	int choice, value;

	char infix[INPUT_SIZE];
	char postfix[INPUT_SIZE];

	getExpression();

	convertToPostfix(infix, postfix);

	printf("Postfix: %s\n", postfix);

	printf("Coniec\n");

	return 0;
}


