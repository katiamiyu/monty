#include "monty.h"
/**
 * select_func - Selects a function based on the given string and line number.
 * @s: The string to be evaluated.
 * @line: The line number.
 *
 * Return: A function pointer to the selected function.
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
		{"div", _div},
		{"mul", _mul},
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
