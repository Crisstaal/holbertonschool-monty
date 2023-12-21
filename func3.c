#include "monty.h"

/**
 * monty_nop - nothing
 * @stacks: pointer
 * @line_number: current line
 */

void monty_nop(stack_t **stacks, unsigned int line_number)
{
	(void)stacks;
	(void)line_number;
}
/**
 * monty_pchar - prints character
 * @stacks: pointer
 * @line_number: current line
 */

void monty_pchar(stack_t **stacks, unsigned int line_number)
{
	if ((*stacks)->next == NULL)
		{
			set_error(pchar_error(line_number, "stack empty"));
			return;
		}
	if ((*stacks)->next->n < 0 || (*stacks)->next->n > 127)
	{
		set_error(pchar_error(line_number, "range"));
		return;
	}
	printf("%c\n", (*stacks)->next->n);
}

/**
 * monty_pstr - prints string
 * @stacks: pointer
 * @line_number: current line
 */

void monty_pstr(stack_t **stacks, unsigned int line_number)
{
	stack_t *tmp = (*stacks)->next;

	if (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");

	(void)line_number;
}
