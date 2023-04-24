#include "main.h"

/**
 * malloc_checkptr - check if return is NULL and exit if condition is met
 * @s: check null string
 */

void malloc_checkptr(char *s)
{
	if (s == NULL)
		exit(EXIT_FAILURE);
}

/**
 * malloc_checkdptr - check if return is NULL and exit if condition is met
 * @s: check null 2d string
 */

void malloc_checkdptr(char **s)
{
	if (s == NULL)
		exit(EXIT_FAILURE);
}

/**
 * getret - check for getline return value and EOF condition
 * @line: line pointer to command line string
 * @cpy: pointer to copy of line ptr
 * @tokenarr: tokenized 2d array of line ptr string
 * @es: exit status
 * @ret: return of getline function
 */

void getret(ssize_t ret, char **line, char **cpy, char ***tokenarr, int *es)
{
	if (ret < 0)
	{
		free_alloced_mem_on_exit(line, cpy, tokenarr);
		write(STDOUT_FILENO, "\n", 1);
		fflush(stdout);
		exit(*es);
	}
}

/**
 * write_cmd_err - writes error output for commands not found in path
 * @exec_name: The programs executable name
 * @err_name: name of potential error input
 * @ln: line number
 */


void write_cmd_err(char *exec_name, char *err_name, int *ln)
{
	char *str = malloc(sizeof(char) * (count_digits(*ln) + 1));

	malloc_checkptr(str);
	to_string(*ln, str);

	write(STDERR_FILENO, exec_name, _strlen(exec_name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, str, _strlen(str));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, err_name, _strlen(err_name));
	write(STDERR_FILENO, ": not found", 11);
	write(STDERR_FILENO, "\n", 1);
	fflush(stderr);
	free(str);
}

/**
 * write_exec_err - writes error when execve fails.
 * @exec_name: The programs executable name
 * @ln: line number
 */

void write_exec_err(char *exec_name, int *ln)
{
	char *str = malloc(sizeof(char) * (count_digits(*ln) + 1));

	malloc_checkptr(str);
	to_string(*ln, str);

	write(STDERR_FILENO, exec_name, _strlen(exec_name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, str, _strlen(str));
	write(STDERR_FILENO, ": ", 2);
	fflush(stderr);
	free(str);
}
