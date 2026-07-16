#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "stack.h"

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
	if (sPtr != NULL) {
		return (*sPtr)->data;
	}

	return -1;
}

void printStack(STACKNODEPTR sPtr)
{
	if (sPtr == NULL) {
		printf("The stack is empty\n\n");
	} else {
		printf("The stack is:\n");

		while(sPtr != NULL) {
			printf("%c-> ", sPtr->data);
			sPtr = sPtr->nextPtr;
		}

		printf("NULL\n\n");
	}
}

char delete(STACKNODEPTR *sPtr, char value)
{
	STACKNODEPTR previousPtr, currentPtr, tempPtr;

	if (value == (*sPtr)->data) {
		tempPtr = *sPtr;
		*sPtr = (*sPtr)->nextPtr;

		free(tempPtr);

		return value;
	} else {
		previousPtr = *sPtr;
		currentPtr = (*sPtr)->nextPtr;

		while(currentPtr != NULL && currentPtr->data != value) {
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}

		if (currentPtr != NULL) {
			tempPtr = currentPtr;
			previousPtr->nextPtr = currentPtr->nextPtr;

			free(tempPtr);

			return value;
		}
	}

	return '\0';
}

