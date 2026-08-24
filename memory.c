#include "slc.h"

/*
 * Init memory array by UNOP (1000) value
 * If max valid value is 9999 the UNOP is means that the stored it memory
 * cell is untouched (not yet being modified)
 */
void memoryInit(void)
{
	int i;

	//printf("In memory Init\n");
	
	for (i = 0; i < MEMORY_SIZE; i++) {
		memory[i] = UNOP_CMD;
	}
}

