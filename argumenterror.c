#include "monty.h"
/**
 * checkargerror - function name
 * @argument_count: argument count
 * Description - check for argument error
 * Return: returns nothing
 */
void checkargerror(int argument_count)
{
	if (argument_count != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}
