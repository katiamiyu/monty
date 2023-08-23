#include "monty.h"
/**
 * select_function - selects a function
 * @s: is instruction
 * @line: line number.
 * Return: a pointer corresponding to string
 */
void (*select_function(char *s, unsigned int line))(stack_t **stack, unsigned int)
{
	instruction_t op[] = {{"push", push},
		{"add", add},
		{"pop", pop},
		{"pall", pall},
		{"sub", sub},
		{"swap", swap},
		{"pint", pint},
		{NULL, NULL}};
	int i = 0;

	while (op[i].opcode != NULL)
	{
		if (!strcmp(s, op[i].opcode))
			return (op[i].f);
		i++;
	}
	(void)line;
	return (NULL);
}
