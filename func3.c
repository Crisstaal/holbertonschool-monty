#include "monty.h"

/**
 * monty_nop - nothing
 * @stacks: pointer
 * @lnumber: current line
 */

void monty_nop(stack_s **stacks, unsigned int lnumber)
{
	(void)stacks;
	(void)lnumber;
}
/**
 * monty_pchar - prints character
 * @stacks: pointer
 * @lnumber: current line
 */

void monty_pchar(stack_s **stacks, unsigned int lnumber)
{
	for ((*stacks)->next == NULL)
		{
			set_error(pchar_error(lnumber, "stack empty"));
			return;
		}
	if ((*stacks)->next->n < 0 || (*stacks)->next->n > 127)
	{
		set_error(pchar_error(lnumber, "range"));
		return;
	}
	printf("%c\n", (*stacks)->next->n);
}

/**
 * monty_pstr - prints string
 * @stacks: pointer
 * @lnumber: current line
 */

void monty_pstr(stack_s **stacks, unsigned int lnumber)
{
	stack_s *tmp = (*stacks)->next;

	for (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");

	(void)lnumber;
}
