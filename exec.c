#include "main.h"

/**
 * exct - function utilises execve() to execute standard commands in path
 * @exe_name: The programs executable name
 * @line: line pointer to command line string
 * @cpy: pointer to copy of line ptr
 * @tok: tokenized 2d array of line ptr string
 * @ln: line number
 */

void exct(char *exe_name, char **line, char **cpy, char ***tok, int *ln)
{
	int exe_ret;
	char *cmd;
	int exct_exit = EXIT_FAILURE;

	cmd = find_path(**tok);
	if (cmd == NULL)
	{
		free(*line);
		free(*cpy);
		free_tokens(*tok);
		*line = NULL, *cpy = NULL, *tok = NULL;
		_exit(exct_exit);
	}

	exe_ret = execve(cmd, *tok, environ);
	if (exe_ret == -1)
	{
		write_exec_err(exe_name, ln);
		perror(**tok);
		fflush(stderr);
		free(*line);
		free(*cpy);
		free_tokens(*tok);
		*line = NULL, *cpy = NULL, *tok = NULL;

		if (errno == EACCES)
		{
			exct_exit = 126;
		}

		_exit(exct_exit);
	}
}
