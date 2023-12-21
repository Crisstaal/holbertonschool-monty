#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include "monty.h"

char **op_toks = NULL;

/**
 * main - entry point
 * @argc: count
 * @argv: arguments
 * Return: EXIT_SUCCESS on success
 */
int main (int argc, char **argv)
{
	FILE *script_fd = NULL;
	int exit_code = EXIT_SUCCESS;


	if (argc != 2)
		return (usage_error());

	script_fd = fopen(argv[1], "r");
	if (script_fd == NULL)
		return (f_open_error(argv[1]));
	fclose(script_fd);
	return(exit_code);
}
