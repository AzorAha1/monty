#include "monty.h"
/**
 *
 *
 */
void getf(stack_t **stack, const char *opcode, unsigned int line_number)
{
	int i;
	int checker;
	int line_num;

	instruction_t ops[] = {
		{"push", op_push},
		{"pop", op_pop},
		{NULL, NULL},
	};
	checker = 0;
	line_num = 0;
	for (i = 0; ops[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, ops[i].opcode) == 0)
		{
			ops[i].f(stack, line_number);
			checker = 1;
			return;
		}
		line_num++;
	}
	if (checker == 0)
	{
		printf("L%d: unknown instruction %s", line_num, opcode);
	}
	fprintf(stderr, "Error: Unknown opcode \"%s\" on line %u\n", opcode, line_number);
}
