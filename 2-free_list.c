#include "monty.h"
/**
  * free_list - frees list
  * @head: list head
  * Return: (Void)
  */
void free_list(stack_t *head)
{
	stack_t *temp;

	if (head == NULL)
		return;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
