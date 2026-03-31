#include "evaluate.h"

void push(STACKNODEPTR *sPtr, int info)
{
	STACKNODEPTR newPtr;

	newPtr = malloc(sizeof(STACKNODE));

	if (newPtr != NULL) {
		newPtr->data = info;
		newPtr->nextPtr = *sPtr;

		*sPtr = newPtr;
	} else {
		printf("%d not inserted. No memory available.\n", info);
	}
}

