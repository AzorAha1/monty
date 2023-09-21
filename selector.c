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
 *
 * 
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
