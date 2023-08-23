#include "monty.h"
#include <ctype.h>
/**
  * is_integer - validate integer
  * @input: char input
  * Return: 0 (false),1 (true)
  */
int is_integer(const char *input)
{
	if (input == NULL)
		return (0);

	if (*input == '\0')
		return (0);

	if (*input == '+' || *input == '-')
		input++;

	while (*input != '\0')
	{
		if (!isdigit(*input))
			return (0);
		input++;
	}
	return (1);
}
