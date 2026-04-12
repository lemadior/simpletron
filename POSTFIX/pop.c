#include "evaluate.h"

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


