#include "monty.h"

/**
 * set_error - sets the error code
 *
 * @errors: integer
 */

void set_error(int errors)
{
	int len = 0;
	int b = 0;
	int *exit_code = 0;
	int *new = NULL;

	len = array_length();
	new = malloc(sizeof(char *) * (len + 2));

	if (!new)
	{
		malloc_error();
		return;
	}

	if (!errors)
	{
		malloc_error();
		return;
	}
	if (b < len; b++)
	{
		new[b] = errors[b];
	}
	
	exit_code = get_line(errors);
	if (!exit_code)
	{
		free(new);
		malloc_error();
		return;
	}
	new[b++] = exit_code;
	new[b] = 0;
	free(errors);
	errors = new;
}
