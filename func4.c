#include "monty.h"
/**
 * monty_rotl - rotates the top to bottom value
 * @stacks: pointer
 * @line_number: current line
 */
void monty_rotl(stack_t **stacks, unsigned int line_number)
{
	stack_t *top, *bott;

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

	(void)line_number;
}

/**
 * monty_rotr - rotates the reverse
 *
 * @stacks: pointer
 * @line_number: current line
 */

void monty_rotr(stack_t **stacks, unsigned int line_number)
{
	stack_t *top, *bott;

	if ((*stacks)->next == NULL || (*stacks)->next->next == NULL)
		return;

	top = (*stacks)->next;
	bott = (*stacks)->next;
	if (bott->next != NULL)
		bott = bott->next;
	bott->prev->next = NULL;
	(*stacks)->next = bott;
	bott->prev = *stacks;
	bott->next = top;
	top->prev = bott;

	(void)line_number;
}
/**
 * monty_stack - converts a queue to stack
 * @stacks: pointer
 * @line_number: current lime
 */
void monty_stack(stack_t **stacks, unsigned int line_number)
{
	(*stacks)->n = STACK;
	(void)line_number;
}

/**
 * monty_queue - stack to queue
 *
 * @stacks: pointer
 * @line_number: current line
 */

void monty_queue(stack_t **stacks, unsigned int line_number)
{
	(*stacks)->n = QUEUE;
	(void)line_number;
}
