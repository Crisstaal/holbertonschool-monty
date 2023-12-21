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
	char *exit = NULL;
	char *new = NULL;

	len = array_length();
	new = malloc(sizeof(char *) * (len + 2));

	if (!errors)
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
