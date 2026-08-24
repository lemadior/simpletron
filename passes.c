#include "func.h"
#include "slc.h"

char *getToken(char *, const char *);
Statement initStatement(void);
uint8_t getTempCell(void);
Statement program[100];
int parseProgram(Statement[]);

void firstPass()
{
	int linesCount = 0; // Amount of lines with code in source program
	uint8_t line, value;
	int entryPos = 0;
	int lValue, rValue;

	char postfix[EXPRESSION_LENGTH];

	memset(program, 0, sizeof(program));

	linesCount = parseProgram(program);

	printf(" Total lines = %d\n", linesCount);
	NEWLINE;

	for (int i = 0; i < linesCount; i++) {
		line = findEntry(program[i].line, 'L');
		entryPos = findFreeEntry(); // Only if findEntry uses for 'L' 

		if (line == NOT_FOUND) {
			TABLEENTRY[entryPos].symbol = program[i].line;
			TABLEENTRY[entryPos].type = 'L';
			TABLEENTRY[entryPos].location = CPU.ic;
		}

		if (checkCommand(program[i].cmd, SL_REM)) {
			continue;
		}

		if (checkCommand(program[i].cmd, SL_PRINT)) {
			generatePrint(program[i]);
			
			continue;
		}

		if (checkCommand(program[i].cmd, SL_INPUT)) {
			generateInput(program[i]);

			continue;
		}

		if (checkCommand(program[i].cmd, SL_GOTO)) {
			generateJump(program[i].jumpto, JUMP);

			continue;
		}

		if (checkCommand(program[i].cmd, SL_LET)) {
			NEWLINE;
			printf(" In 'generateLet Start'\n");
			NEWLINE;

			printf("EXPRRIGHT: %s\n", program[i].exprright);
			memset(postfix, 0, sizeof(postfix)); 
			convertToPostfix(program[i].exprright, postfix);
			
			// showEntryTable();
			printf("postfix=%s\n", postfix);

			value = evaluatePostfixExpression(postfix);

			if (checkOperationsAmount(postfix) == 1) {
				value = SINGLE_MATH;	
			}
			// showEntryTable();
			printf("Value=%d Type='%c'\n", value, program[i].var);
			generateLet(program[i], value);
			// printf();
			continue;
		}

		// IMPORTANT: the left expression can be ONLY a var or const
		// not an expression like `y + 1'
		if (checkCommand(program[i].cmd, SL_IF)) {

			NEWLINE;
			printf(" In 'generateIF Start'\n");
			NEWLINE;

			showEntryTable();

			memset(postfix, 0, sizeof(postfix));
			convertToPostfix(program[i].exprleft, postfix);

			// if (checkOperationsAmount(postfix) > 0) {
				// ERROR("Left part of the IF statement cannot be an expression!");
			// }

			showEntryTable();

			printf("LEFT postfix=%s ", postfix);
			lValue = evaluatePostfixExpression(postfix);
			printf("lValue bef=%d\n", lValue);

			showEntryTable();

			if (checkOperationsAmount(postfix) == 1) {
				memory[TABLEENTRY[findEntry(program[i].var, 'V')].location] = lValue;
			} else if (checkOperationsAmount(postfix) > 1) {	
				// Copy data for lValue to different cell
				memory[TMPL] = memory[lValue];
				// lValue = CPU.dc--;
			}

			printf("lValue aft=%d\n", lValue);

			memset(postfix, 0, sizeof(postfix));
			convertToPostfix(program[i].exprright, postfix);

			printf("RIGHT postfix=%s ", postfix);
			rValue = evaluatePostfixExpression(postfix);
			printf("rValue=%d\n", rValue);

			generateIf(lValue, rValue, program[i].cond, program[i].jumpto);

			continue;
		}

		// printf(" Line: %d", program[i].line);
		// printf(" Cmd: %s", program[i].cmd);
		
		if (checkCommand(program[i].cmd, SL_END)) {
			generateEnd(program[i]);

			// continue;
		} 
		
		// printf(" V: %c", program[i].var);
		// printf(" L: %s", program[i].exprleft);
		// printf(" C: %s", program[i].cond);
		// printf(" R: %s", program[i].exprright);
		// printf(" J: %d", program[i].jumpto);
		// NEWLINE;
	}

	// printf("Entry POS = %d", findEntry(5, 'C'));

	NEWLINE;
}


char *getToken(char *str, const char *delim)
{
	static char *tokenPtr = NULL;

	if (tokenPtr == NULL) {
		tokenPtr = strtok(str, delim);
	} else {
		tokenPtr = strtok(NULL, delim);
	}

	return tokenPtr;
}

bool checkCommand(char *cmdName, Commands command)
{
	return cmdnameToCode(cmdName) == command ? 1 : 0;
}

Statement initStatement(void)
{
	return (Statement){ 0 };
}

// Return the position in TABLEENTRY array (if find)
uint8_t findEntry(int symbol, char type)
{
	int i, cell, newEntryPos;
	TableEntry entry;

	for (i = 0; i < SYMBOL_TABLE_SIZE; i++) {
		entry = TABLEENTRY[i];
		
		if (entry.symbol == symbol && entry.type == type) {
			return i;
		}

	}
	printf("FINDENTRY TYPE=%c\n", type);
	// Only for line number or  jump
	if (type == 'L') {
		return 255;
	}

	cell = CPU.dc--;

	if (type == 'C') {
		memory[cell] = symbol;
	}

	newEntryPos = findFreeEntry();
	
	TABLEENTRY[newEntryPos].symbol = symbol;
	TABLEENTRY[newEntryPos].type = type;
	TABLEENTRY[newEntryPos].location = cell;

	// printf("FIND DUMP");
		// showDump();

	return newEntryPos;
}

int parseProgram(Statement program[])
{
	int len;
	int count = 0; // Lines count
	int lenToken, lenExpr;
	char *token;
	char strBuffer[MAX_LINE_SIZE];
	bool isLine, isCmd, isExprLeft, isExprRght,
			isCondition, isLet, isVar, isJump;
	Statement currStat;

	while((len = readline(strBuffer, MAX_LINE_SIZE, FDESCR.fdSRC)) != -1) {
		// skip empty string
		if (!len) {
			continue;
		}
		
		isLine = isCmd = false;
		isExprLeft = isExprRght = isCondition = false;
		isLet = isVar = isJump = false;

		// Reinit of currStat
		memset(&currStat, 0, sizeof(Statement));

		while ((token = getToken(strBuffer, " ")) != NULL) {
			// printf("TOKEN:%s\n", token);

			// printf("Before LINENUM\n");
			if (!isLine) {
				currStat.line = atoi(token);

				isLine = 1;
				continue;
			}

			// printf("Before isCmd\n");
			if (!isCmd) {
				strncpy(currStat.cmd, token, sizeof(currStat.cmd) - 1);
				currStat.cmd[sizeof(currStat.cmd) - 1] = '\0';

				isCmd = true;
				
				isLet = checkCommand(currStat.cmd, SL_LET);

				isJump = checkCommand(currStat.cmd, SL_GOTO);
				
				isCondition = checkCommand(currStat.cmd, SL_IF);
				isExprLeft = isCondition;

				continue;
			}

			// Skip all text after REM
			if (checkCommand(currStat.cmd, SL_REM)) {
				// if here do break; then rest of current buffer still avail
				continue;
			}


			// printf("Before GOTO\n");
			if (isJump && !currStat.jumpto) {
				currStat.jumpto = atoi(token);
				
				continue;
			}

			if (
					isCondition &&
					!isJump &&
					strncasecmp(token, "GOTO", 4) == 0
			) {
				isJump = true;

				continue;
			}

		
			// printf("Before VAR\n");

			if (
					!isExprLeft && (
						checkCommand(currStat.cmd, SL_PRINT) || 
						checkCommand(currStat.cmd, SL_INPUT) ||
						checkCommand(currStat.cmd, SL_LET)
					)
			   ) {
				currStat.var = token[0];
				isVar = true;

				isExprLeft = true;
				continue;
			}

			// printf("Before R-EXPRESSION: %d\n", isCondition);
			if (
					strncmp(token, "==", 2) == 0 ||
					strncmp(token, "<=", 2) == 0 ||
					strncmp(token, "=>", 2) == 0 ||
					token[0] == '=' ||
					token[0] == '>' ||
					token[0] == '<'
				) {
				// printf("Token %s\n", token);
				isExprRght = (isLet && isVar) || (isCondition && isExprLeft);

				// TODO: add an operator enum
				strncpy(currStat.cond, token, sizeof(currStat.cond) - 1);
				currStat.cond[sizeof(currStat.cond) - 1] = '\0';

				continue;
			}

			// printf("Before SET LEFT EXPR\n");
			if (isCondition && !isExprRght) {
				lenToken = strlen(token) + 2; // Reserve 1 symbol for '\0' and SPACE
				lenExpr = strlen(currStat.exprleft);
				// printf("lenExpr %d\n", lenExpr);
				if ((lenToken + lenExpr) > EXPRESSION_LENGTH) {
					ERROR("too long expression in %d line!", currStat.line);
				}
				
				snprintf(currStat.exprleft + lenExpr, sizeof(currStat.exprleft) - lenExpr, " %s", token);
			
				continue;
			}

			// printf("Before SET RIGHT EXPR %d\n", isExprRght);
			if (isExprRght) {
				// printf("in expr right\n");
				lenToken = strlen(token) + 2; // Reserve 1 symbol for '\0' and SPACE
				lenExpr = strlen(currStat.exprright);
				// printf("lenExpr %d\n", lenExpr);
				if ((lenToken + lenExpr) > EXPRESSION_LENGTH) {
					ERROR("too long expression in %d line!", currStat.line);
				}
				
				snprintf(currStat.exprright + lenExpr, sizeof(currStat.exprright) - lenExpr, " %s", token);
			}
		}

		program[count++] = currStat;
	}

	return count;
}

uint8_t findFreeEntry()
{
	int i;

	for(i = 0; i < SYMBOL_TABLE_SIZE; i++) {
		if (TABLEENTRY[i].symbol == 0) {
			return i;
		}
	}

	return 255;
}

uint8_t getTempCell()
{
	if (tempCell == OUT_OF_MEMORY) {
		tempCell = CPU.dc--;
	}

	return tempCell;
}

/*
 * Get amount of math operators in expression
 * If it return 0 (zero) it means that no math operation (just var or const)
 * If it return 1 (one) it means that opnly one math operation here
 */
uint8_t checkOperationsAmount(const char *expression)
{
	int operatorCount = 0;
	char operator;

	while(*expression != '\0') {
		operator = *expression++;

		if (operator == '+' || operator == '-' || operator == '*' || operator == '\\') {
			operatorCount++;
		}
	}

	return operatorCount;
}

