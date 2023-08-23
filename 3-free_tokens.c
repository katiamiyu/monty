#include "monty.h"
/**
 * free_tokens - release memory
 * @tokens: double pointer
 */
void free_tokens(char **tokens)
{
	int i = 0;

	if (tokens == NULL)
		return;
	while (tokens[i] != NULL)
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}
