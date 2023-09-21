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

	if (argc != 2 || argv[1] == NULL)
	{
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if (access(argv[1], F_OK | R_OK) == 0)
	{
		filed = fopen(argv[1], "r");
		if (!filed)
		{
			printf("Error: Can't open file %s\n", argv[1]);
			fclose(filed);
			exit(EXIT_FAILURE);
		}
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
	fclose(filed);
	free(lineptr);
	return (0);
}
