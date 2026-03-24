#include "postfix.h"

void printStack(STACKNODEPTR currentPtr)
{
	if (currentPtr == NULL) {
		printf("The stack is empty\n\n");
	} else {
		printf("The stack is:\n");

		while(currentPtr != NULL) {
			printf("%c> ", currentPtr->data);
			currentPtr = currentPtr->nextPtr;
		}

		printf("NULL\n\n");
	}
}

