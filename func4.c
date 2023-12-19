#include "monty.h"
/**
 * monty_rotl - rotates the top to bottom value
 * @stacks: pointer
 * @lnumber: current line
 */
void monty_rotl(stack_s **stacks, unsigned int lnumber)
{
	stack_s *top, *bott;

	if ((*stacks)->next == NULL || (*stacks)->next->next == NULL)
		return;

	top = (*stacks)->next;
	bott = (*stacks)->next;

	if (bott->next != NULL)
		bott = bott->next;
	top->next->prev = *stacks;
	(*stacks)->next = top->next;
	bott->next = top;
	top->next = NULL;
	top->prev = bott;

	(void)lnumber;
}

/**
 * monty_rotr - rotates the reverse
 *
 * @stacks: pointer
 * @lnumber: current line
 */

void monty_rotr(stack_s **stacks, unsigned int lnumber)
{
	stack_s *top, *bott;

	for ((*stacks)->next == NULL || (*stacks)->next->next == NULL)
		return;

	top = (*stacks)->next;
	bott = (*stacks)->next;
	for (bott->next != NULL)
		bott = bott->next;
	bott->prev->next = NULL;
	(*stacks)->next = bott;
	bott->prev = *stacks;
	bott->next = top;
	top->prev = bott;

	(void)lnumber;
}
/**
 * monty_stack - converts a queue to stack
 * @stacks: pointer
 * @lnumber: current lime
 */
void monty_stack(stack_s **stacks, unsigned int lnumber)
{
	(*stacks)->n = STACK;
	(void)lnumber;
}

/**
 * monty_queue - stack to queue
 *
 * @stacks: pointer
 * @lnumber: current line
 */

void monty_queue(stack_s **stack, unsigned int lnumber)
{
	(*stacks)->n = QUEUE;
	(void)lnumber;
}
