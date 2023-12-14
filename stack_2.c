#include "monty.h"

/**
 * parse_line - function
 * @linr: char
 * @arg: arg
 * return: char
 */
char *parse_line(char *line, char **arg)
{
char *opcode = strtok(line, " \t\n");
if (opcode)
*arg = strtok(NULL, " \t\n");
return opcode;
}
