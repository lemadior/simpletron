#include <slc.h>

char *getToken(char *, const char *);
Statement initStatement(void);
uint8_t checkCommand(char *cmd, Commands);

Statement program[100];

int linesCount = 0; // Amount of lines with code in program

void firstPass()
{
	int len;
	int lenToken, lenExpr;
	char *token;
	char strBuffer[MAX_LINE_SIZE];
	uint8_t isLine, isCmd, isOperator, isExprLeft, isExprRght,
			isCondition, isSimple, isLet, isVar, isJump;
	Statement currStat;

	memset(program, 0, sizeof(program));

	while((len = getline(strBuffer, MAX_LINE_SIZE, FDESCR.fdSRC)) != -1) {
		// skip empty string
		if (len == 0) {
			continue;
		}
		
		isLine = 0; isCmd = 0; isOperator = 0;
		isExprLeft = 0; isExprRght = 0; isCondition = 0;
		isSimple = 0; isLet = 0; isVar = 0; isJump = 0;

		// Reinit of currStat
		memset(&currStat, 0, sizeof(Statement));

		while ((token = getToken(strBuffer, " ")) != NULL) {
			// printf("TOKEN:%s\n", token);
			

			// printf("Before LINENUM\n");
			if (isLine == 0) {
				currStat.line = atoi(token);

				isLine = 1;
				continue;
			}

			// printf("Before isCmd\n");
			if (isCmd == 0) {
				strncpy(currStat.name, token, sizeof(currStat.name) - 1);
				currStat.name[sizeof(currStat.name) - 1] = '\0';

				isCmd = 1;
				isJump = checkCommand(currStat.name, SL_GOTO);
				isCondition = checkCommand(currStat.name, SL_IF);
				isExprLeft = isCondition;

				continue;
			}

			// Skip all text after REM
			if (checkCommand(currStat.name, SL_REM)) {
				// if here do break; then rest of current buffer still avail
				continue;
			}

			// printf("Before GOTO\n");
			if (isJump) {
				currStat.jumpto = atoi(token);
				
				continue;
			}


			if (checkCommand(currStat.name, SL_IF) && strncmp(token, "GOTO", 4)) {
				// currStat.jumpto = atoi(token);
				isJump = 1;
				continue;
			}

			// printf("Before VAR\n");

			if (
					checkCommand(currStat.name, SL_PRINT) || 
					checkCommand(currStat.name, SL_INPUT) ||
				    checkCommand(currStat.name, SL_LET)
			   ) {
				currStat.var = token[0];
				isVar = 1;

				isLet = checkCommand(currStat.name, SL_LET);
				isExprLeft = 1;
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

				isOperator = 1;
				// TODO: add an operator enum
				strncpy(currStat.cond, token, sizeof(currStat.cond) - 1);
				currStat.cond[sizeof(currStat.cond) - 1] = '\0';

				continue;
			}

			// printf("Before SET LEFT EXPR\n");
			if (isCondition && isExprRght == 0) {
				lenToken = strlen(token) + 2; // Reserve 1 symbol for '\0' and SPACE
				lenExpr = strlen(currStat.exprleft);
				// printf("lenExpr %d\n", lenExpr);
				if ((lenToken + lenExpr) > EXPRESSION_LENGTH) {
					ERROR("too long expression in %d line!", currStat.line);
				}
				
				snprintf(currStat.exprleft + lenExpr, sizeof(currStat.exprleft) - lenExpr, " %s", token);
			
				continue;
			}

			// printf("Before SET RIGHT EXPR\n");
			if (isExprRght && isOperator) {
				lenToken = strlen(token) + 2; // Reserve 1 symbol for '\0' and SPACE
				lenExpr = strlen(currStat.exprright);
				// printf("lenExpr %d\n", lenExpr);
				if ((lenToken + lenExpr) > EXPRESSION_LENGTH) {
					ERROR("too long expression in %d line!", currStat.line);
				}
				
				snprintf(currStat.exprright + lenExpr, sizeof(currStat.exprright) - lenExpr, " %s", token);
			}
		}

		printf(" Line: %d Cmd: %s Var: %c\n", currStat.line, currStat.name, currStat.var);
		if (isCondition) {
			printf(" L: %s C:%s R: %s\n", currStat.exprleft, currStat.cond, currStat.exprright);
		}


		NEWLINE;
	}



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

uint8_t checkCommand(char *cmdName, Commands command)
{
	return cmdnameToCode(cmdName) == command ? 1 : 0;
}

Statement initStatement(void)
{
	return (Statement){ 0 };
}



