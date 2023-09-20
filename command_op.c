#include "monty.h"
void (*getf)(stack_t **stack, unsigned int line_number)
{
	int i;
	instruction_t ops[] = {
		{"push", op_push},
		{"pop", op_pop},
		{NULL, NULL},
	};
	for (i = 0; ops[i]->op; i++)
	{
		if (stack == ops[i]->op)
		{
			ops[i]->f;
		}
	}
}
