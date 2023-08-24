#define _POSIX_C_SOURCE 200809L
#include "monty.h"
char *argument = NULL;
/**
 * main - entry point of application.
 * @argc: no of arguments.
 * @argv: argument vectors
 * Return: Always 0 (success)
 */
int main(int argc, char *argv[])
{
	FILE *fd;
	size_t count = 0;
	stack_t *head = NULL;
	char *buffer = NULL, **tokens;
	unsigned int line_count = 0, mode = 0;

	check_arg_count(argc);
	fd = fopen(argv[1], "r");
	if (fd == NULL)
		open_error(argv[1]);
	while (getline(&buffer, &count, fd) != -1)
	{
		line_count += 1;
		tokens = tokenizer(buffer);
		if (tokens == NULL)
			continue;
		if (tokens[0][0] == '#')
		{
			free_tokens(tokens);
			continue;
		}
		if (!strcmp(tokens[0], "queue") || !strcmp(tokens[0], "stack"))
		{
			mode = validate_mode(tokens[0]);
			free_tokens(tokens);
			continue;
		}
		argument = tokens[1];
		if (!(select_function(tokens[0], line_count)))
			error(buffer, tokens, line_count, head, fd);
		if (mode && (!strcmp(tokens[0], "push")))
			select_function("queue", line_count)(&head, line_count);
		else
			select_function(tokens[0], line_count)(&head, line_count);
		free_tokens(tokens);
	}
	fclose(fd);
	free(buffer);
	free_list(head);

	return (0);
}
