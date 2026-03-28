#include "evaluate.h"

void getExpression(void)
{
	int i = 0;
	const char *allowed = "0123456789+-*/%^()";
	char ch;
	uint8_t stop = 0;
	char inp[];

	printf(" Postfix evaluation program\n");
	printf(" NOTE: all elements should be divided by space symbol!\n");
	printf("       MAX alllowed num is 99");
	NEWLINE;
	
	while (stop == 0) {
		NEWLINE;
		printf(" Input the math expression");
		NEWLINE;
		printf(" exp: ");

		while (i < (INPUT_SIZE - 1) && (ch = getchar()) != '\n' && ch != EOF) {
			postfix[i++] = ch;
		}

		if (postfix[0] == '\0' || postfix[0] == '\n') {
			 continue;
		}

		// Suggest all is ok
		stop = 1;
		
		// Check for wrong symbols
		for (i = 0; postfix[i] != '\0'; i++) {
			// Skip newline
			if (postfix[i] == '\n' || postfix[i] == ' ') {
				continue;
			}

			// If not allowed symbol
			if (strchr(allowed, postfix[i]) == NULL) {
				stop = 0; // All is not ok!
				break;
			}
		}
	}
}

