#include "monty.h"

/**
 * set_error - sets the error code
 *
 * @errors: integer
 */

void set_error(int *errors)
{
	int len = 0;
	int b;
	int exit_code = 0;
	int *new_errors = NULL;

	len = array_length();
	new_errors = malloc(sizeof(int) * (len + 2));

	if (!new_errors)
	{
		malloc_error();
		return;
	}

	if (!errors)
	{
		malloc_error();
		return;
	}
	for (b = 0; b < len; b++)
	{
		new_errors[b] = errors[b];
	}
	
	exit_code = getline(errors);
	if (!exit_code)
	{
		free(new_errors);
		malloc_error();
		return;
	}

	new_errors[b++] = exit_code;
	new_errors[b] = 0;

	free(errors);
	errors = new_errors;
}
