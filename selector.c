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

	if (!instruct[1] || stack == NULL)
	{
		fprintf(stderr, "Error %d", line_number);
		exit(EXIT_FAILURE);
	}
	temp = atoi(instruct[1]);

	if (temp == 0 && strcmp(instruct[1], "0") != 0)
	{
		printf("error %d", line_number);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = temp;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (*stack != NULL)
	{
		new_node->next = *stack;
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
	(void)line_number;

	if (*stack == NULL)
	{
		fprintf(stderr, "Error: can't pop an empty stack\n");
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(tmp);
}
#include <stdio.h>

/**
 * pall - Prints all the elements in the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number
 *
 * Return: nothing
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
