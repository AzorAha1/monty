#include "monty.h"

/**
 * op_swap - function to swap
 * @stack: stack
 * @line_number: line
 *
 * Return : nothing
 */
void op_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first_node = *stack;
	stack_t *second_node = (*stack)->next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (first_node->prev != NULL)
		first_node->prev->next = second_node;
	if (second_node->next != NULL)
		second_node->next->prev = first_node;
	first_node->next = second_node->next;
	first_node->prev = second_node;
	second_node->next = first_node;
	second_node->prev = NULL;
	*stack = second_node;
}
