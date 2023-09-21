#include "monty.h"

/**
 * op_push -  insert a new node
 * @stack_t: pointer to pointer to a stack
 * @value: to be pushed
 * Return: nothing
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	int temp;

	temp = atoi(instruct[1]);

	if (temp == 0)
	{
		printf("error %d", line_number);
	}
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = temp;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
/**
 * op_pop - Removes the top element of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number
 *
 * Return: nothing
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		printf("error %d", line_number);
		/*fprintf(stderr, "Error: can't pop an empty stack\n");*/
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(tmp);
}
