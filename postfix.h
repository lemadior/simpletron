#ifndef POSTFIX_H
#define POSTFIX_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define INPUT_SIZE 80

extern char postfix[INPUT_SIZE];

void evaluatePostfixExpression(const char *);
int calculate(uint8_t, uint8_t, char);

typedef struct StackNode { 
	char data;
	struct StackNode *nextPtr;
} StackNode;

typedef StackNode STACKNODE;
typedef STACKNODE *STACKNODEPTR;

void push(STACKNODEPTR *, char);
char pop(STACKNODEPTR *);
char stackTop(STACKNODEPTR *);
uint8_t isEmpty(STACKNODEPTR);
void printStack(STACKNODEPTR);
void instructions(void);

extern STACKNODEPTR stack;

typedef enum {
	OP_ADD = 43,
	OP_SUB = 45,
	OP_MUL = 42,
	OP_DIV = 47,
	OP_MOD = 37,
	OP_POWER = 94 
} Operations;

#endif

