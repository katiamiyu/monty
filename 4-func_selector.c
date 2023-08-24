#include "monty.h"
/**
 * select_function - selects a function
 * @s: is instruction
 * @line: line number.
 * Return: a pointer corresponding to string
 */
void (*select_func(char *s, unsigned int line))(stack_t **stack, unsigned int)
{
	instruction_t op[] = {{"push", _push},
		{"add", _add},
		{"pop", _pop},
		{"pall", _pall},
		{"sub", _sub},
		{"swap", _swap},
		{"pint", _pint},
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
