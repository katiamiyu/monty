#include "monty.h"
/**
  * _div -  divides the second top by second element
  * @stack: working stack
  * @line_number: line number
  */
void _div(stack_t **stack, unsigned int line_number)
{
	int total;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack) = (*stack)->next;

	total = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = total;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
