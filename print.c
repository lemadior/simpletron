#include "evaluate.h"

void printStack(STACKNODEPTR currentPtr)
{
	printf("The stack is:\n");

	while(currentPtr != NULL) {
		printf("%d> ", currentPtr->data);
		currentPtr = currentPtr->nextPtr;
	}

	printf("NULL\n\n");
}

