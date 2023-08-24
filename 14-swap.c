#include "monty.h"

/**
 * swap - swaps the head
 * @top: current head
 * @line_number: line
 */
void swap(stack_t **top, unsigned int line_number)
{
	stack_t *temp = *top;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		*top = temp->next;
		(*top)->prev = NULL;
		temp->prev = *top;
		temp->next = (*top)->next;
		(*top)->next = temp;
	}

}
