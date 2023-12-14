#include "monty.h"

/**
 * main - main
 * @argc : argc
 * @argv: argv
 * Return: success
 */
int main(int argc, char *argv[])
{
FILE *file = fopen(argv[1], "r");
stack_t *stack = NULL;

if (argc != 2)
{
fprintf(stderr, "USAGE: %s file\n", argv[0]);
return (EXIT_FAILURE);
}

if (!file)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
return (EXIT_FAILURE);
}

monty_interpreter(argv[1], &stack);

fclose(file);
return (EXIT_SUCCESS);
}

