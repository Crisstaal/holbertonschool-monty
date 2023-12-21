#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char **op_toks = NULL;
int run_monty(FILE *script_file);

/**
 * main - entry point
 * @argc: count
 * @argv: arguments
 * Return: EXIT_SUCCESS on success
 */
int usage_error(void)
{
	fprintf(stderr, "Usage: %s <script_file>\n", op_toks[0]);
	return EXIT_FAILURE;
}

int f_open_error(char *filename)
{
	perror(filename);
	return EXIT_FAILURE;
}

int main (int argc, char **argv)
{
	FILE *script_fd = NULL;
	int exit_code = EXIT_SUCCESS;


	if (argc != 2)
		return (usage_error());

	script_fd = fopen(argv[1], "r");
	if (script_fd == NULL)
		return (f_open_error(argv[1]));
	exit_code = run_monty(script_fd);
	fclose(script_fd);
	return(exit_code);
}
