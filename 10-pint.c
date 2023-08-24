#include "monty.h"

/**
 * _pint - prints the first element
 * @top: the head
 * @line_number: current line
 */
void _pint(stack_t **top, unsigned int line_number)
{
	if (*top == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*top)->n);
}
