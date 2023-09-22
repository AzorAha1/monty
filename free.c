#include "monty.h"
void freestack(stack_t **stack)
{
	stack_t *temp;
	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}
