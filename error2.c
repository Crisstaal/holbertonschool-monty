#include "monty.h"

/**
 * pop_error - prints error
 * @line_number: line number
 * Return: EXIT_FAILURE
 */

int pop_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an emprty stack\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pint_error - prints error when empty
 * @line_number: line number
 * ReturnL EXIT_FAILURE
 */

int pint_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * short_stack_error - prints error
 *
 * @line_number: line number
 * @opp: operation
 * Return: EXIT_FAILURE
 */

int short_stack_error(unsigned int line_number, char *opp)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, opp);
	return (EXIT_FAILURE);
}
/**
 * div_error: prints division error
 * @line_number: line number
 * Return: EXIT_FAILURE
 */

int div_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}
/**
 * pchar_error - prints error
 * @line_number: line number
 * @message: corresponding error
 * Return: EXIT_FAILURE
 */

int pchar_error(unsigned int line_number, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n" line_number, message);
	return (EXIT_FAILURE);
}
