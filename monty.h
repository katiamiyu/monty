#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s {
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s {
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern char *argument;

char **tokenizer(char *buffer);
void (*select_func(char *s, unsigned int))(stack_t **, unsigned int);
char *_strdup(char *str);
unsigned int validate_mode(char *str);
void error(char *buf, char **tokens, unsigned int line, stack_t *h, FILE *fd);

void _pall(stack_t **stack, unsigned int line_number);
void _push(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);

void free_list(stack_t *head);
void free_tokens(char **tokens);
int is_integer(const char *input);
void check_arg_count(int argc);
void open_error(char *s);
#endif
