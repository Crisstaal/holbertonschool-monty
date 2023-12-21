#include "monty.h"

/**
 * monty_push - pushes value
 * @stack: pointer
 * @line_number: line number
 */

void monty_push(stack_t **stacks, unsigned int line_number)
{
	stack_t *tmp = NULL;
	stack_t *new;
	int b = 0;
	int malloc_err = malloc_error();
	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		set_error(malloc_err);
		return;
	}
	int pint_err = pint_error(line_number);

	if (op_toks[1] == NULL)
	{
		set_error(pint_err);
		return;
	}
	if (op_toks[1][b])
	{
	       	b++;
	}
	{
		while (op_toks[1][b] == '-' && b == 0)
			continue;
		if (op_toks[1][b] < '0' || op_toks[1][b] > '9')
		{
			set_error(pint_error(line_number));
			return;
		}
	}
	new->n = atoi(op_toks[1]);

	if (check(*stacks) == STACK)
	{
		tmp = (*stacks)->next;
		new->prev = *stacks;
		new->next = tmp;
		if (tmp)
			tmp->prev = new;
		(*stacks)->next = new;
	}
	else
	{
		tmp = *stacks;
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
		new->next = NULL;
		tmp->next = new;
	}
}

/**
 * monty_pall - prints value
 * @stacks: pointer
 * @line_number: current line
 */

void monty_pall(stack_t **stacks, unsigned int line_number)
{
	stack_t *tmp = (*stacks)->next;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	(void)line_number;
}
/**
 * monty_pint - prints top value
 * @stacks: pointer
 * @line_number: current line
 */

void monty_pint(stack_t **stacks, unsigned int line_number)
{
	if ((*stacks)->next == NULL)
	{
		set_error(pint_error(line_number));
		return;
	}
	printf("%d\n", (*stacks)->next->n);
}

/**
 * monty_pop - removes top value
 *
 * @stacks: pointer
 * @line_number: current line
 */
void monty_pop(stack_t **stacks, unsigned int line_number)
{
	stack_t *next = NULL;

	if ((*stacks)->next == NULL)
	{
		set_error(pop_error(line_number));
		return;
	}

	next = (*stacks)->next->next;
	free(*stacks);
	if (next)
		next->prev = *stacks;
	(*stacks)->next = next;
}

/**
 * monty_swap - swaps the top two values
 *
 * @stacks: pointer
 * @line_number: current line
 */

void monty_swap(stack_t **stacks, unsigned int line_number)
{
	stack_t *tmp;

	if ((*stacks)->next == NULL || (*stacks)->next->next == NULL)
	{
		set_error(short_error(line_number, "swap"));
		return;
	}

	tmp = (*stacks)->next->next;
	(*stacks)->next->next = tmp->next;
	(*stacks)->next->prev = tmp;
	if (tmp->next)
	{
		tmp->next->prev = (*stacks)->next;
	tmp->next = (*stacks)->next;
	tmp->prev = *stacks;
	(*stacks)->next = tmp;
	}
}
