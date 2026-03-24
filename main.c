#include "postfix.h"


//void push(STACKNODEPTR *,int);
//int pop(STACKNODEPTR *);
//int isEmpty(STACKNODEPTR);
//void printStack(STACKNODEPTR);
//void instructions(void);


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


