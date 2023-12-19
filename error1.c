#include "monty.h"

int usage_error(void);
int f_open_error(char *filename);
int malloc_error(void);
int unknown_op_error(char *opcode, unsigned int lnumber);
int no_int_error(unsigned int lnumber);

/**
 * usage_error - prints usage error
 *
 * Return: EXIT_FAILURE
 */

int usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return(EXIT_FAILURE);
}

/**
 * malloc_error - prints error
 *
 * Return: EXIT_FAILURE
 */

int malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * f_open_error - prints file opening errpr
 *
 * @filename: name of file
 * Return: (EXIT_FAILURE)
 */
int f_open_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return(EXIT_FAILURE);
}

/**
 * unknown_op_error - prints error
 * @opcode: opcode error
 * @lnumber: line numer
 * Return: EXIT_FAILURE
 */

int unknown_op_error(char *opcode, unsigned int lnumber)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", lnumber, opcode);
	return (EXIT_FAILURE);
}

/**
 * no_int_error - prints error associated
 * @lnumber: line number
 * Return: EXIT_FAILURE
 */

int no_int_error(unsigned int lnumber)
{
	fprintf(stderr, "L%u: usage: push integer\n", line number);
	return(EXIT_FAILURE);
}
