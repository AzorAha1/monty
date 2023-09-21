#include "monty.h"
/**
 * main - function
 * @argv: argument vector
 * @argc: argument count
 * Return: return
 */
char *instruct[2] = {NULL, NULL};
int main(int argc, char **argv)
{
	char *lineptr = NULL;
	char *lines[1000] = {NULL};
	int linenum = 0, i;
	FILE *filed;
	char *token = NULL;
	int index = 0;
	stack_t *stack = NULL;
	size_t n = 0;


	filed = fopen(argv[1], "r");
	if (!filed)
	{
		fprintf(stderr, "error: %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	checkargerror(argc);
	while (getline(&lineptr, &n, filed) != -1)
	{
		lineptr = strtok(lineptr, "\n");
		lines[linenum] = strdup(lineptr);
		linenum++;
	}
	while (lines[index])
	{
		token = strtok(lines[index], " ");
		instruct[0] = token;
		token = strtok(NULL, " ");
		instruct[1] = token;
		getf(&stack, instruct, index + 1);
		index++;
	}
	for (i = 0; i < linenum; i++)
	{
		free(lines[i]);
	}
	free(lineptr);
	fclose(filed);
	return (0);
}
