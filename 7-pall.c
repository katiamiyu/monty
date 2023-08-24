#include "monty.h"
/**
 * _pall - prints the values stack,
 * @stack: added stack
 * @line_number: line number
 *
 */
void _pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
		return;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
