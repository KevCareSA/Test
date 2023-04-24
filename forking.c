#include "main.h"

/**
 * forking - function initializes forking the main process in order to...
 *             execute the standard commands in the child process.
 * @nm: The programs executable name
 * @l: line pointer to command line string
 * @cp: pointer to copy of line ptr
 * @t: tokenized 2d array of line ptr string
 * @r: return of check_path() which determines if command exists
 * @es: error status
 * @ln: line number
 */

void forking(int r, char *nm, char **l, char **cp, char ***t, int *es, int *ln)
{
	pid_t fret;
	int status;

	if (r == 0)
	{
		fret = fork();
		if (fret < 0)
		{
			perror("fork");
			fflush(stderr);
			exit(EXIT_FAILURE);
		}
		else if (fret == 0)
			exct(nm, l, cp, t, ln);
		else
		{
			wait(&status);
			*es = wexitstat(status);
			free_alloced_mem_on_exit(l, cp, t);
		}
	}
	else
	{
		write_cmd_err(nm, **t, ln);
		*es = 127;
		free_alloced_mem_on_exit(l, cp, t);
	}
}
