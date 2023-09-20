#include "monty.h"
/**
 * main - function
 * @argv: argument vector
 * @argc: argument count
 * Return: return
 */
int main(int argc, char **argv)
{
	int i = 0;
	FILE *filed;
	char *lineptr = NULL;
	size_t n = 0;
	filed = fopen(argv[1], "r");	
	checkargerror(argc);

	while(getline(&lineptr, &n, filed) != -1)
	{
		printf("%s", lineptr);
		i++;
	}
	free(lineptr);
	fclose(filed);
	return (0);
}
