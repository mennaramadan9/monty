#include "monty.h"


/**
 * get_instruction - function
 * @opcode: char
 * return: instruction_t
 */
instruction_t *get_instruction(char *opcode)
{
instruction_t *instr = malloc(sizeof(instruction_t));
if (!instr)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

instr->opcode = opcode;

return instr;
}


/**
 * execute_opcode - executes the corresponding opcode
 * @stack: pointer to the head of the stack
 * @line_number: line number in the file
 * @data: pointer to the parsed instruction_t structure
 */
void execute_opcode(stack_t **stack, unsigned int line_number, instruction_t *data)
{
if (strcmp(data->opcode, "push") == 0)
push(stack, line_number);
else if (strcmp(data->opcode, "pall") == 0)
pall(stack, line_number);
else
{
fprintf(stderr, "L%u: unknown instruction %s\n", line_number, data->opcode);
free(data);
exit(EXIT_FAILURE); }

free(data);
}


/**
 * monty_interpreter - interprets Monty byte code
 * @file_path: path to the Monty byte code file
 */
void monty_interpreter(const char *file_path)
{
FILE *file = fopen(file_path, "r");
stack_t *stack = NULL;
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
data->f(&stack, line_number);
free(data); }}

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
char *arg = NULL;
char *line = NULL;
stack_t *new_node = malloc(sizeof(stack_t));
int value = atoi(arg);

parse_line(line, &arg);

if (!new_node)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE); }

if (!arg || !is_number(arg))
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
free(line);
free(arg);
free(new_node);
exit(EXIT_FAILURE);
}

new_node->n = value;
new_node->prev = NULL;
new_node->next = *stack;

if (*stack)
(*stack)->prev = new_node;

*stack = new_node;
free(line);
free(arg);
}

/**
 * is_number - function
 * @str: char
 * return: int
 */
int is_number(const char *str)
{
int i;
if (!str || *str == '\0')
return (0);

for (i = 0; str[i] != '\0'; i++)
{
if (!isdigit(str[i]) && str[i] != '-')
return (0);
}

return (1);
}

/**
 * pall - prints all the values on the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number in the file
 */
void pall(stack_t **stack, unsigned int line_number)
{
stack_t *current = *stack;
(void)line_number;

while (current)
{
printf("%d\n", current->n);
current = current->next; }
}

