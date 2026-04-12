#include "sbc.h"

uint8_t isEmpty(STACKNODEPTR sPtr)
{
	return (uint8_t)(sPtr == NULL);
}

void push(STACKNODEPTR *sPtr, int info)
{
	STACKNODEPTR newPtr;

	newPtr = malloc(sizeof(STACKNODE));

	if (newPtr != NULL) {
		newPtr->data = info;
		newPtr->nextPtr = *sPtr;

		*sPtr = newPtr;
	} 
	// else {
		// printf("%d not inserted. No memory available.\n", info);
	// }
}


int pop(STACKNODEPTR *sPtr)
{
	STACKNODEPTR tempPtr;
	int popValue;

	tempPtr = *sPtr;
	popValue = (*sPtr)->data;
	*sPtr = (*sPtr)->nextPtr;

	free(tempPtr);

	return popValue;
}


// get value from top of the stack.
// Value still remains at the top of the stack
int stackTop(STACKNODEPTR *sPtr)
{
	return (*sPtr)->data;
}

