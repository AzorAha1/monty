#include "monty.h"
/**
 * op_sub - subtrack top twp elements in the stack.
 * @stack: pointer to the stack
 * @line_number: Line number
 * Description - adds all elements in stack
 * Return: no return
*/
void op_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	int add;

	add = 0;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	add += temp->n;
	temp = temp->next;
	add += temp->n;
	temp->n = add;
	temp = temp->next->next;
	temp->prev = NULL;
	*stack = temp;
}
