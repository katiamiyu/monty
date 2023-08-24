#include "monty.h"

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
 * open_error - error message when file fails to open.
 * @str: name string.
 */
void open_error(char *str)
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
	if (!strcmp(str, "stack"))
		return (0);
	return (1);
}
/**
 * error - update stderr if error.
 * @buff: program instruction.
 * @tokens: operation codes.
 * @line: number of occurence.
 * @h: list head.
 * @fd: open file pointer
 */
void error(char *buff, char **tokens, unsigned int line, stack_t *h, FILE *fd)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line, tokens[0]);
	free(buff);
	free_tokens(tokens);
	free_list(head);
	fclose(fd);
	exit(EXIT_FAILURE);
}
