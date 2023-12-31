#include "monty.h"
#include <string.h>
#include <stdlib.h>

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
	s->n = STACK;
	s-> prev = NULL;
	s->next = NULL;

	*stacks = s;

	return (EXIT_SUCCESS);
}

/**
 * checks_stacks - checks if its in stack
 * @stacks: pointer
 * Return: if its in stack
 */

int checks_stacks(stack_t *stacks)
{
	if (stacks->n == STACK)
		return(STACK);
	if (stacks->n == QUEUE)
		return(QUEUE);
	return (2);
}
