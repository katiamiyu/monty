#include "monty.h"

/**
 * pint - prints the first element
 * @top: the head
 * @line_number: current line
 */
void pint(stack_t **top, unsigned int line_number)
{
	if (*top == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*top)->n);
}
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
