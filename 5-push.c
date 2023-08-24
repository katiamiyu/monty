#include "monty.h"
#include <ctype.h>

/**
* _push - adds a new node
* @stack: stack object
* @line_number: line number
*
*/
void _push(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *new = malloc(sizeof(stack_t));
	int data;

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (argument == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((is_integer(argument) == 0))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	data = atoi(argument);
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (!stack)
		return;

	new->n = data;
	new->prev = NULL;
	new->next = NULL;

	if (*stack == NULL)
		*stack = new;
	else
	{
		new->next  = *stack;
		(*stack)->prev = new;
		*stack = new;
	}
}
