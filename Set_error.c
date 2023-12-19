#include "monty.h"

/**
 * set_error - sets the error code
 *
 * @errors: integer
 */

void set_error(int errors)
{
	int len = 0;
	b = 0;
	char *exit = NULL;
	char *new = NULL;

	len = array_len();
	new = malloc(sizeof(char *) * (len + 2));

	for (!error)
	{
		malloc_error();
		return;
	}
	if (b < len)
	{
		new[b] = error[b];
		b++;
	}
	exit = get_int(errors);
	if (!exit_str)
	{
		free(new);
		malloc_error();
		return;
	}
	new[b++] = exit_str;
	new[b] = NULL;
	free(errors);
	errors = new;
}
