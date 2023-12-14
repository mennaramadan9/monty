#include "monty.h"

/**
 * parse_line - function
 * @line: char
 * @arg: arg
 * Return: char
 */
char *parse_line(char *line, char **arg)
{
char *opcode = strtok(line, " \t\n");
if (opcode)
*arg = strtok(NULL, " \t\n");
return (opcode);
}

/**
 * monty_interpreter - interprets Monty byte code
 * @file_path: path to the Monty byte code file
 * @stack: stack
 */
void monty_interpreter(const char *file_path, stack_t **stack)
{
FILE *file = fopen(file_path, "r");
char *line = NULL;
size_t len = 0;
unsigned int line_number = 0;
char *arg = NULL;
char *opcode = parse_line(line, &arg);

if (!file)
{
fprintf(stderr, "Error: Can't open file %s\n", file_path);
exit(EXIT_FAILURE); }

while (getline(&line, &len, file) != -1)
{
line_number++;

if (opcode)
{
instruction_t *data = get_instruction(opcode);
execute_opcode(stack, line_number, data);
free(data); }}

free(line);
fclose(file); }
