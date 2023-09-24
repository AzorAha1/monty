#include "monty.h"
/**
 * getf - function name
 * @stack: stack
 * @opcode: opcode
 * @line_number: line number
 * Description - finding functions by the str passed
 * Return: void
 *
 */
void getf(stack_t **stack, char **opcode, unsigned int line_number)
{
	int i;
	int checker;
	int line_num;

	instruction_t ops[] = {
		{"push", op_push},
		{"pop", op_pop},
		{"pall", op_pall},
		{"add", op_add},
		{"pint", op_pint},
		{"swap", op_swap},
		{"nop", op_nop},
		{"sub", op_sub},
		{NULL, NULL},
	};
	checker = 0;
	line_num = 0;
	for (i = 0; ops[i].opcode != NULL; i++)
	{
		if (strcmp(opcode[0], ops[i].opcode) == 0)
		{
			ops[i].f(stack, line_number);
			checker = 1;
			return;
		}
	line_num++;
	}
	if (checker == 0)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode[0]);
		exit(EXIT_FAILURE);
	}
	else
	{
		exit(EXIT_FAILURE);
	}
}

