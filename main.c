#include "monty.h"
/**
 * main - function
 * @argv: argument vector
 * @argc: argument count
 * Return: return
 */
int main(int argc, char **argv)
{
	char *lineptr = NULL;
	char *lineptrcpy = NULL;
	instruction_t commandarr;
	int linenum = 0;
	FILE *filed;
	char *token;
	size_t n = 0;
	filed = fopen(argv[1], "r");
	checkargerror(argc);
	while(getline(&lineptr, &n, filed) != -1)
	{
		lineptrcpy = strdup(lineptr);
		token = strtok(lineptrcpy, "\n");
		while(token)
		{
			printf("%s\n", token);
			token = strtok(NULL, "\n");
		}
		free(lineptrcpy);
		linenum++;
	}
	free(lineptr);
	fclose(filed);
	return (0);
}
