#include "monty.h"

/**
 * set_error - sets the error code
 *
 * @errors: integer
 */

void set_error(int errors)
{
	int b;
	int exit_code = 0;
	int *new_errors = NULL;
	char *line = NULL;
	size_t len = 0;
	size_t read = getline(&line, &len, stdin);

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
		new_errors[b] = errors;
	}
	
	
	if (read == -1)
	{
		free(new_errors);
		free(line);
		malloc_error();
		return;
	}

	new_errors[b++] = read;
	new_errors[b] = 0;

	free(errors);
	free(line);
	errors = new_errors;
}
