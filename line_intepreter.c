#include "main.h"

/**
 * my_getline - Handles the main process for interactive mode
 * @argv: vector of arguments passed to the program.
 */

void my_getline(char *argv[])
{
	int path_ret, ln = 0, es = 0;
	ssize_t getlin_ret;
	size_t n = 0;
	char *lineptr = NULL, *copy = NULL;
	char **tokarr = NULL;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		fflush(stdout);

		getlin_ret = getline(&lineptr, &n, stdin);
		getret(getlin_ret, &lineptr, &copy, &tokarr, &es);
		ln++;

		if (lineptr[0] == '\n' && lineptr[1] == '\0')
			continue;
		if (lineptr[getlin_ret - 1] == '\n')
			lineptr[getlin_ret - 1] = '\0';
		else
			getlin_ret = getlin_ret + 1;
		copy = malloc(sizeof(char) * getlin_ret);
		malloc_checkptr(copy);
		str_cpy(copy, lineptr);
		tokarr = splitstr(lineptr, copy);
		malloc_checkdptr(tokarr);

		if (ch_builtin(&tokarr, &lineptr, &copy, argv[0], &es, &ln))
			continue;

		es = 0;

		path_ret = check_path(tokarr[0]);
		forking(path_ret, argv[0], &lineptr, &copy, &tokarr, &es, &ln);

	}
}

/**
 * non_interactive_mode - Handles the main process for non-interactive mode
 * @argv: vector of arguments passed to the program.
 */

void non_interactive_mode(char *argv[])
{
	int path_ret, es = 0, ln = 0;
	ssize_t getlin_ret;
	size_t n = 0;
	char *lineptr = NULL, *copy = NULL;
	char **tokarr = NULL;

	while (1)
	{
		getlin_ret = getline(&lineptr, &n, stdin);
		if (lineptr[0] == '\0')
		{
			free_alloced_mem_on_exit(&lineptr, &copy, &tokarr);
			break;
		}
		getret(getlin_ret, &lineptr, &copy, &tokarr, &es);
		ln++;

		if (lineptr[getlin_ret - 1] == '\n')
			lineptr[getlin_ret - 1] = '\0';
		else
			getlin_ret = getlin_ret + 1;

		copy = malloc(sizeof(char) * getlin_ret);
		malloc_checkptr(copy);
		str_cpy(copy, lineptr);
		tokarr = splitstr(lineptr, copy);
		malloc_checkdptr(tokarr);

		if (ch_builtin(&tokarr, &lineptr, &copy, argv[0], &es, &ln))
			continue;

		es = 0;

		path_ret = check_path(tokarr[0]);
		forking(path_ret, argv[0], &lineptr, &copy, &tokarr, &es, &ln);
	}
}
