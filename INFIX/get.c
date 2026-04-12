#include "convert.h"

// get value from top of the stack.
// Value still remains at the top of the stack
char stackTop(STACKNODEPTR *sPtr)
{
	return (*sPtr)->data;
}

