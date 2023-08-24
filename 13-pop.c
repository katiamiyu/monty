#include "monty.h"

/**
 * pop - prints the first element
 * @top: current head
 * @line_number: current line
 */
void pop(stack_t **top, unsigned int line_number)
{
	stack_t *temp = *top;

	if (*top == NULL || top == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	*top = (*top)->next;

	if (*top != NULL)
		(*top)->prev = NULL;

	free(temp);
}
