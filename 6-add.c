#include "monty.h"
/**
 * _add - Adds the top two elements
 * @stack: Pointer to a stack
 * @line_number: line number
 */
void _add(stack_t **stack, unsigned int line_number)
{
	int sum = 0;

	stack_t *temp = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack) = (*stack)->next;

	sum = temp->n + temp->next->n;
	(*stack)->n = sum;
	free(temp);

	(*stack)->prev = NULL;
}
