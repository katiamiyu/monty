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
	char *buffer NULL, **tokens;
	unsigned int line_count = 0, mode = 0;

	check_arg_count(argc);
	fd = fopen(argv[1], "r");
	if (fd == NULL)
		open_err(argv[1]);
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
			selected_function("queue", line_count)(&head, line_count);
		else
			selected_function(tokens[0], line_count)(&head, line_count);
		free_tokens(tokens);
	}
	fclose(fd);
	free(buffer);
	free_list(head);

	return (0);
}
/**
 * check_arg_count - check argument count.
 * @argc: argument counter.
 */
void check_arg_count(int argc)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}
/**
 * open_err - error message when file fails to open.
 * @str: name string.
 */
void open_err(char *str)
{
	fprintf(stderr, "Error: Can't open file %s\n", str);
	exit(EXIT_FAILURE);
}
/**
 * validate_mode - check for queue or stack.
 * @str: operation code.
 * Return: (0) stack, (1) queue.
 */
unsigned int validate_mode(char *str)
{
	if (!strcmp(str, "stack")
			return (0);
	return (1);

}
/**
 * error - update stderr if error.
 * @buff: program instruction.
 * @tokens: operation codes.
 * @line: number of occurence.
 * @head: list head.
 * @fd: open file pointer
 */
void error(char *buff, char **tokens, unsigned int line, stack_t *head, FILE *fd)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line, tokens[0]);
	free(buff);
	free_tokens(tokens);
	free_list(head);
	fclose(fd);
	exit(EXIT_FAILURE);
}
