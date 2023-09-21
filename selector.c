#include "monty.h"

/**
 * op_push -  insert a new node
 * @stack: pointer to pointer to a stack
 * @line_number: to be pushed
 * Description - push to stack
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
		fprintf(stderr, "error %d", line_number);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		free(new_node);
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
 * Description - pop
 * Return: nothing
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void)line_number;

	if (*stack == NULL || !stack)
	{
		printf("L%d: can't pop an empty stack\n", line_number);
		free(temp);
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
 * op_pall - Prints all the elements in the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number
 * Description - print all elements
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
/**
 * op_add - add all the elements in the stack.
 * @stack: pointer to the stack
 * @line_number: Line number
 * Description - adds all elements in stack
 * Return: no return
*/
void op_add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int add;

	add = 0;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	add += temp->n;
	temp = temp->next;
	add += temp->n;
	temp->n = add;
	temp->prev = NULL;
	*stack = temp;
}
/**
 * op_pint - add all the elements in the stack.
 * @stack: pointer to the stack
 * @line_number: Line number
 * Description - adds all elements in stack
 * Return: no return
*/
void op_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
