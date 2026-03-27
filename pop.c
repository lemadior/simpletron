#include "evaluate.h"

char pop(STACKNODEPTR *sPtr)
{
	STACKNODEPTR tempPtr;
	char popValue;

	tempPtr = *sPtr;
	popValue = (*sPtr)->data;
	*sPtr = (*sPtr)->nextPtr;

	free(tempPtr);

	return popValue;
}


