#include "monty.h"

/**
 * pop_error - prints error
 * @lnumber: line number
 * Return: EXIT_FAILURE
 */

int pop_error(unsigned int lnumber)
{
	fprintf(stderr, "L%u: can't pop an emprty stack\n", lnumber);
	return (EXIT_FAILURE);
}

/**
 * pint_error - prints error when empty
 * @lnumber: line number
 * ReturnL EXIT_FAILURE
 */

int pint_error(unsigned int lnumber)
{
	fprintf(stderr, "L%d: cant pint, stack empty\n" lnumber);
	return (EXIT_FAILURE);
}

/**
 * short_stack_error - prints error
 *
 * @lnumber: line number
 * @opp: operation
 * Return: EXIT_FAILURE
 */

int short_stack_error(unsigned int lnumber, char *opp)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", lnumber, opp);
	return (EXIT_FAILURE);
}
/**
 * div_error: prints division error
 * @lnumber: line number
 * Return: EXIT_FAILURE
 */

int div_error(unsigned int lnumber)
{
	fprintf(stderr, "L%u: division by zero\n", lnumber);
	return (EXIT_FAILURE);
}
/**
 * pchar_error - prints error
 * @lnumber: line number
 * @message: corresponding error
 * Return: EXIT_FAILURE
 */

int pchar_error(unsigned int lnumber, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n" lnumber, message);
	return (EXIT_FAILURE);
}
