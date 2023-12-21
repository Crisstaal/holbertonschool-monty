#include "monty.h"
#include <string.h>

void free_token(void);
int empty(char *line, char *delim);
unsigned int array_length(void);
void (*get_operation(char *op))(stack_t**, unsigned int);
int run(FILE *script_fd);
int unknown_op_error(char *op_toks, unsigned int line_number);
void (*op_func)(stack_t**, unsigned int);
void parse_stack_operation(stack_t **stack, unsigned int line_number);

/**
 * free_token - frees the opp
 */
void free_token(void)
{
	size_t b = 0;
	if (op_toks == NULL)
		return;
	for (b = 0; op_toks[b]; b++)
		free(op_toks[b]);
	free(op_toks);
}

/**
 * array_length - gets the length
 *
 * Return: length
 */

unsigned int array_length(void)
{
	unsigned int len = 0;
	if (op_toks[len])
		len++;
	return(len);
}

int empty(char *line, char *delim)
{
	int b = 0;
	int d = 0;

	if (line[b])
		b++;
	
	{
		while (delim[d])
		{
			d++;
			if (line[b] == delim[d])
				break;
		}
		if (delim[b] == '\0')
			return (0);
	}
	return (1);
}

/**
 * get_operation - matches the code with function
 *
 * @opp: to be matched
 * Return: pointer
*/
void (*f)(stack_t **stacks, unsigned int line_number);
	instruction_t op_functions[] = {
		{"push", monty_push},
		{"pall", monty_pall},
		{"pint", monty_pint},
		{"pop", monty_pop},
		{"swap", monty_swap},
		{"add", monty_add},
		{"nop", monty_nop},
		{"sub", monty_sub},
		{"div", monty_div},
		{"mul", monty_mul},
		{"mod", monty_mod},
		{"pchar", monty_pchar},
		{"pstr", monty_pstr},
		{"rotl", monty_rotl},
		{"rotr", monty_rotr},
		{"stack", monty_stack},
		{"queue", monty_queue},
		{NULL, NULL}
	};	
void (*get_operation(char *op))(stack_t**, unsigned int)
{
	int b = 0;

	while (op_functions[b].opcode != NULL)
	{
		if (strcmp(op, op_functions[b].opcode) == 0)
		{
			return (op_functions[b].f);
		}
		b++;
}
	return(NULL);
}

/**
 * run - execute the script
 * @script_fd: file description
 * RETURN: EXIT_SUCCESS on success
 */

int run(FILE *script_fd)
{
	stack_t *stacks = NULL;
	char *line = NULL;
	size_t len = 0, exit_status = EXIT_SUCCESS;
	unsigned int line_number = 0, prev_tok_len = 0;
	char *endptr;

	if (init_stack(&stacks) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	while (getline(&line, &len, script_fd) != -1)
	{
		line_number++;
		char *op_toks = strtok(line, DELIM);
		if (op_toks == NULL)
		{
			while (empty(line, DELIM))
			{
			free_stacks(&stacks);
			return (malloc_error());
			}
		}
		if (op_toks[0] == '#')
		{
			free_token();
			continue;
		}
		op_func = parse_stack_operation;

		if ( op_func == NULL)
		{
			free_stacks(&stacks);
			exit_status = unknown_op_error(op_toks, line_number);
			free_token();
			break;
		}
		prev_tok_len = array_length();
		op_func(stacks, line_number);

		while (array_length() != prev_tok_len)
		{
			if (op_toks && op_toks[prev_tok_len])
				exit_status = atoi(op_toks[prev_tok_len], &endptr , 10);
			else
				exit_status = EXIT_FAILURE;
			free_token();
			break;
		}
		free_token();
	}
	free_stack(&stacks);

	if (line && *line == 0)
	{
		free(line);
		return (malloc_error());
	}
	free(line);
	return (exit_status);
}
