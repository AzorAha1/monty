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
	int linenum = 0;
	FILE *filed;
	char *token = NULL;
	int index = 0;
	stack_t **stack = NULL;
	size_t n = 0;


	filed = fopen(argv[1], "r");
	checkargerror(argc);
	while(getline(&lineptr, &n, filed) != -1)
	{
		lineptr = strtok(lineptr, "\n");
		lines[linenum] = strdup(lineptr);
		linenum++;
	}
	while(lines[index])
	{
		token = strtok(lines[index], " ");
		instruct[0] = token;
		token = strtok(NULL, " ");
		instruct[1] = token;
		getf(stack, instruct, index + 1);
		printf("%s %s\n", instruct[0], instruct[1]);
		index++;
	}
	free(lineptr);
	fclose(filed);
	return (0);
}
