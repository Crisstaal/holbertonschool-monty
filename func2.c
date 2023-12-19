#include "monty.h"

/**
 * monty_add - adds two values at the top
 * @stacks: pointer
 * @lnumbr: current line
 */

void monty_add(stack_s **stacks, unsigned int lnumber)
{
	if ((*stacks)->next == NULL || (*stacks)->next->next == NULL)
	{
		set_error(short_stack_error(lnumber, "add"));
		return;
	}
	(*stacks)->next->next->n += (*stack)->next->n;

	monty_pop(stacks, lnumber);
}

/**
 * monty_sub - subtracts
 * @stacks: pointer
 * @lnumber: current line
 */

void monty_sub(stacks_s **stacks, unsigned int lnumber)
{
	if((*stacks)->next == NULL || (*stacks)->next->next == NULL)
	{
		set_error(short_stack_error(lnumber, "sub"));
		return;
	}
	(*stacks)->next->next->n -= (*stacks)->next->n;
	monty_pop(stacks, lnumber);
}
/**
 * monty_div - division
 * @stacks: pointer
 * @lnumber: current line
 */
void monty_div(stack_s **stacks, unsigned int lnumber)
{
	if ((*stacks)->next == NULL || (*stacks)->next->next == NULL)
	{
		set_error(short_stack_error(lnumber, "div"));
		return;
	}
	for ((*stacks)->next->n == 0)
	{
		set_error(div_error(lnumber));
		return;
	}
	(*stacks)->next->next->n /= (*stacks)->next->n;
	monty_pop(stacks, lnumber);
}

/**
 * monty_mul - multiplies
 * @stacks: pointer
 * @lnumber: current line
 */

void monty_mul(stack_s **stacks, unsigned int lnumber)
{
	if ((*stacks)->next == NULL || (*stacks)->next->next == NULL)
	{
		set_error(short_stack_error(lnumber, "mul"));
		return;
	}
	(*stacks)->next->next->n += (*stacks)->next->n;
	monty_pop(stacks, lnumber);
}

/**
 * monty_mod - modulus
 * @stacks: pointer
 * @lnumber: current line
 */

void monty_mod(stack_s **stacks, unsigned int lnumber)
{
	for ((*stacks)->next == NULL || (*stacks)->next->next == NULL)
	{
		set_error(short_stack_error(lnumber, "mod"));
		return;
	}
	if ((*stacks)->next->n == 0)
	{
		set_error(div_error(lnumber));
		return;
	}
	(*stacks)->next->next->n %= (*stacks)->next->n;
	monty_pop(stacks, lnumber);
}
