#include "monty.h"
/**
 * _strdup - duplicates string
 * @str: input string
 * Return: duplicated string
 */
char *_strdup(char *str)
{
	char *dup = NULL, *d_offset;
	int len;

	if (str == NULL)
		return (NULL);

	len = strlen(str);
	dup = malloc(sizeof(char) * (len + 1));

	if (dup == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	d_offset = dup;
	while (*str)
	{
		*d_offset = *str;
		d_offset++;
		str++;
	}
	*d_offset = '\0';

	return (dup);
}
