#include "monty.h"

/**
 * monty_interpreter - interprets Monty byte code
 * @file_path: path to the Monty byte code file
 */
void monty_interpreter(const char *file_path)
{
stack_t *stack = NULL;
char *line = NULL;
size_t len = 0;
unsigned int line_number = 0;
FILE *file = fopen(file_path, "r");

if (!file)
{
fprintf(stderr, "Error: Can't open file %s\n", file_path);
exit(EXIT_FAILURE);
}

while (getline(&line, &len, file) != -1)
{
line_number++;
}
free(line);
fclose(file);
}

/**
 * push - pushes an element to the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number in the file
 */
void push(stack_t **stack, unsigned int line_number)
{
size_t i;
int value;
stack_t *new_node;

if (!data || !data->arg)
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
exit(EXIT_FAILURE); }
for (i = 0; data->arg[i]; i++)
{
if (!isdigit(data->arg[i]) && data->arg[i] != '-')
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
exit(EXIT_FAILURE); }}

value = atoi(data->arg);
new_node = malloc(sizeof(stack_t));

if (!new_node)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE); }

new_node->n = value;
new_node->prev = NULL;
new_node->next = *stack;

if (*stack)
(*stack)->prev = new_node;

*stack = new_node; }


/**
 * pall - prints all the values on the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number in the file
 */
void pall(stack_t **stack, unsigned int line_number)
{
(void)line_number;

stack_t *current = *stack;

while (current)
{
printf("%d\n", current->n);
current = current->next; }
}

