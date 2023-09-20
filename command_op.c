#include "monty.h"
/**
 *
 *
 */
void getf(stack_t **stack, const char *opcode, unsigned int line_number)
{
	int i;
	instruction_t ops[] = {
		{"push", op_push},
		{"pop", op_pop},
		{NULL, NULL},
	};

	for (i = 0; ops[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, ops[i].opcode) == 0)
		{
			ops[i].f(stack, line_number);
			return;
		}
	}
	fprintf(stderr, "Error: Unknown opcode \"%s\" on line %u\n", opcode, line_number);
}
