#include "monty.h"
/**
 * _mul - Adds the top two elements of the stack.
 * @stack: working stack.
 * @line_number: line number
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	int res;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can\'t mul, stack too short\n", line_number);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack) = (*stack)->next;
	res = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = res;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
