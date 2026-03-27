#include "evaluate.h"

void push(STACKNODEPTR *sPtr, char info)
{
	STACKNODEPTR newPtr;

	newPtr = malloc(sizeof(STACKNODE));

	if (newPtr != NULL) {
		newPtr->data = info;
		newPtr->nextPtr = *sPtr;

		*sPtr = newPtr;
	} else {
		printf("%c not inserted. No memory available.\n", info);
	}
}

