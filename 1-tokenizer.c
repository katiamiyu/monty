#include "monty.h"
/**
* tokenizer - break a string into tkens
* @buffer: pointer string
*
* Return: array of strings or null;
*/
char **tokenizer(char *buffer)
{
	char *token, *dup, *delim = " \n\t";
	char **tokens;
	int i = 0, num_token = 0;

	if (buffer == NULL)
		return (NULL);
	dup = _strdup(buffer);
	token = strtok(dup, delim);
	while (token)
	{
		num_token++;
		token = strtok(NULL, delim);
	}
	if (num_token == 0)
	{
		free(dup);
		return (NULL);
	}
	tokens = malloc(sizeof(char *) * (num_token + 1));
	if (tokens == NULL)
		return (NULL);

	token = strtok(buffer, delim);
	while (token != NULL)
	{
		tokens[i] = _strdup(token);
		i++;
		token = strtok(NULL, delim);
	}
	tokens[num_token] = NULL;
	free(dup);
	return (tokens);
}
