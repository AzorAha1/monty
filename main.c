#include "monty.h"
/**
 * main - function
 * @argv: argument vector
 * @argc: argument count
 * Return: return
 */
int main(int argc, char **argv)
{
	FILE *filed;
	char *lineptr = NULL;
	size_t n = 0;
	filed = fopen(argv[1], "r");	
	checkargerror(argc);

	while(getline(&lineptr, &n, filed) != -1)
	{
		printf("%s", lineptr);
	}
	free(lineptr);
	fclose(filed);
	return (0);
}
