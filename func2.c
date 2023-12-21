#include "monty.h"

/**
 * monty_add - adds two values at the top
 * @stacks: pointer
 * @line_number: current line
 */

void monty_add(stack_s **stacks, unsigned int line_number)
{
	if ((*stacks)->next == NULL || (*stacks)->next->next == NULL)
	{
		set_error(short_error(line_number, "add"));
		return;
	}
	(*stacks)->next->next->n += (*stacks)->next->n;

	monty_pop(stacks, line_number);
}

/**
 * monty_sub - subtracts
 * @stacks: pointer
 * @line_number: current line
 */

void monty_sub(stacks_s **stacks, unsigned int line_number)
{
	if((*stacks)->next == NULL || (*stacks)->next->next == NULL)
	{
		set_error(short_error(line_number, "sub"));
		return;
	}
	(*stacks)->next->next->n -= (*stacks)->next->n;
	monty_pop(stacks, line_number);
}
/**
 * monty_div - division
 * @stacks: pointer
 * @line_number: current line
 */
void monty_div(stack_s **stacks, unsigned int line_number)
{
	if ((*stacks)->next == NULL || (*stacks)->next->next == NULL)
	{
		set_error(short_stack_error(line_number, "div"));
		return;
	}
	for ((*stacks)->next->n == 0)
	{
		set_error(div_error(line_number));
		return;
	}
	(*stacks)->next->next->n /= (*stacks)->next->n;
	monty_pop(stacks, line_number);
}

/**
 * monty_mul - multiplies
 * @stacks: pointer
 * @line_number: current line
 */

void monty_mul(stack_s **stacks, unsigned int line_number)
{
	if ((*stacks)->next == NULL || (*stacks)->next->next == NULL)
	{
		set_error(short_stack_error(line_number, "mul"));
		return;
	}
	(*stacks)->next->next->n += (*stacks)->next->n;
	monty_pop(stacks, line_number);
}

/**
 * monty_mod - modulus
 * @stacks: pointer
 * @line_number: current line
 */

void monty_mod(stack_s **stacks, unsigned int line_number)
{
	for ((*stacks)->next == NULL || (*stacks)->next->next == NULL)
	{
		set_error(short_stack_error(line_number, "mod"));
		return;
	}
	if ((*stacks)->next->n == 0)
	{
		set_error(div_error(line_number));
		return;
	}
	(*stacks)->next->next->n %= (*stacks)->next->n;
	monty_pop(stacks, line_number);
}
