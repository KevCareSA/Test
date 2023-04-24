#include "main.h"

/**
 * write_exec_err2 - writes error output for exit argument error
 * @exec_name: The programs executable name
 * @err_name: name of potential error input
 * @ln: line number
 * @num: incorrect num value entered
 */

void write_exec_err2(char *exec_name, char *err_name, char *num, int *ln)
{
	char *str = malloc(sizeof(char) * (count_digits(*ln) + 1));

	malloc_checkptr(str);
	to_string(*ln, str);

	write(STDERR_FILENO, exec_name, _strlen(exec_name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, str, _strlen(str));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, err_name, _strlen(err_name));
	write(STDERR_FILENO, ": Illegal number: ", 18);
	write(STDERR_FILENO, num, _strlen(num));
	write(STDERR_FILENO, "\n", 1);
	fflush(stderr);
	free(str);
}
