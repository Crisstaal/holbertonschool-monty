#include "monty.h"
#include <string.h>

void free_stacks(stack_s **stacks);
int stacks(stack_s **stacks);
int checks_stacks(stack_s *stacks);

/**
 * free_stracks - frees the stack
 * @stack: pointer
 */

void free_stacks(stack_s **stacks)
{
	stacks_s *tmp = *stacks;
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

int stacks(stacks_s **stacks)
{
	stacks_s *s;
	s = malloc(sizeof(stacks_s));
	if (s == NULL)
		return (malloc_error());
	s->n = STACKS;
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
