#include "monty.h"
/**
 * freestack - function name
 * @stack: stack
 * Description - function to free stack after use
 * Return: void
 */
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
