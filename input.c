#include "postfix.h"

int i = 0;
const char *allowed = "0123456789+-*/%^()";
uint8_t stop = 0;

void getExpression(void)
{
	while (stop == 0) {
		printf("\nInput the math expression\n");
		printf("exp: ");

		while (i < (INPUT_LENGTH - 1) && (ch = getchar()) != '\n' && ch != EOF) {
			infix[i++] = ch;
		}

		if (infix[0] == '\0' || infix[0] == '\n') {
			 continue;
		}

		// Suggest all is ok
		stop = 1;
		
		// Check for wrong symbols
		for (i = 0; infix[i] != '\0'; i++) {
			// Skip newline
			if (infix[i] == '\n') {
				continue;
			}

			// If not allowed symbol
			if (strchr(allowed, infix[i]) == NULL) {
				stop = 0; // All is not ok!
				break;
			}
		}
	}
}

