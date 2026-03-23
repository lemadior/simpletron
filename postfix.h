#ifndef STRUCT_H
#define STRUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define INPUT_SIZE 80

extern infix[INPUT_SIZE]
extern postfix[INPUT_SIZE]

void convertToPostfix(char *, char *);
uint8_t isOperator(char);
int8_t precendence(char, char);

void getExpression(void)

void push(STACKNODEPTR *, char);
char pop(STACKNODEPTR *);
uint8_t isEmpty(STACKNODEPTR);
void printStack(STACKNODEPTR);
void instructions(void);

typedef struct StackNode { 
	char data;
	struct StackNode *nextPtr;
} StackNode;

typedef StackNode STACKNODE;
typedef STACKNODE *STACKNODEPTR;

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

