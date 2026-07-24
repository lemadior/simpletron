#ifndef STACK_H
#define STACK_H

#include <stdint.h>
#define INPUT_SIZE 80
#define E_VALUE 100 // 100 is means here empty cell or wrong value

typedef struct stackNode {
	int data;
	struct stackNode *nextPtr;
} StackNode;

typedef StackNode STACKNODE;
typedef STACKNODE *STACKNODEPTR;

extern STACKNODEPTR stack;

void instructions(void);

uint8_t isEmpty(STACKNODEPTR);

void push(STACKNODEPTR *, int);

int pop(STACKNODEPTR *);

int stackTop(STACKNODEPTR *);

void printStack(STACKNODEPTR);

typedef enum {
	OP_ADD = 43,
	OP_SUB = 45,
	OP_MUL = 42,
	OP_DIV = 47,
	OP_MOD = 37,
	OP_POWER = 94 
} Operations;

#endif
