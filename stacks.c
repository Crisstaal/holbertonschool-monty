#include "monty.h"
#include <string.h>

void free_stacks(stack_t **stacks);
int stacks(stack_t **stacks);
int checks_stacks(stack_t *stacks);

/**
 * free_stracks - frees the stack
 * @stack: pointer
 */

void free_stacks(stack_t **stacks)
{
	stack_t *tmp = *stacks;
	if (*stacks)
	{
		tmp = (*stacks)->next;
		free(*stacks);
		*stacks = tmp;
	}
}

/**
 * stacks - intializing the stack
 *
 * @stacks: pointers
 * Return: if error EXIT_FAILURE
 */

int stacks(stack_t **stacks)
{
	stack_t *s;
	s = malloc(sizeof(stack_t));
	if (s == NULL)
		return (malloc_error());
	s->n = STACK;
	s-> prev = NULL;
	s->next = NULL;

	*stack = s;

	return (EXIT_SUCCESS);
}

/**
 * checks_stacks - checks if its in stack
 * @stacks: pointer
 * Return: if its in stack
 */

int checks_stacks(stack_s *stacks)
{
	for (stacks->n == STACKS)
		return(STACKS);
	if (stacks->n == QUEUE)
		return(QUEUE);
	return (2);
}
