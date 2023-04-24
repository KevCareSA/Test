#include "main.h"

/**
 * ch_builtin - function selects which built-in functions to implement
 * @nm: The programs executable name
 * @li: line pointer to command line string
 * @cp: pointer to copy of line ptr
 * @bcmd: tokenized 2d array of line ptr string
 * @ln: line number
 * @es: error status
 *
 * Return: 1 if using execve in main shell loop is not necessary
 *         0 otherwise
 */

int ch_builtin(char ***bcmd, char **cp, char **li, char *nm, int *es, int *ln)
{
	if (_strcmp(**bcmd, "exit") == 0)
	{
		exit_args(bcmd, cp, li, nm, es, ln);
		return (1);
	}
	else if (_strcmp(**bcmd, "env") == 0)
	{
		_printenv();
		free_alloced_mem_on_exit(li, cp, bcmd);
		return (1);
	}
	else if (_strcmp(**bcmd, "echo") == 0 && tokencount(*bcmd) > 1)
		echo_args(*bcmd, es);
	return (0);
}

/**
 * _printenv - prints the environment list using global environ variable
 */

void _printenv(void)
{
	unsigned int i = 0;

	while (environ[i] != NULL)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	fflush(stdout);
}

/**
 * exit_args - function handles exit built-in and it's arguments
 * @nm: The programs executable name
 * @li: line pointer to command line string
 * @cp: pointer to copy of line ptr
 * @bcmd: tokenized 2d array of line ptr string
 * @ln: line number
 * @es: error status
 */

void exit_args(char ***bcmd, char **cp, char **li, char *nm, int *es, int *ln)
{
	int stat;
	char **token = *bcmd;

	if (tokencount(*bcmd) == 1)
	{
		free_alloced_mem_on_exit(li, cp, bcmd);
		exit(*es);
	}
	else if (tokencount(*bcmd) > 1 && _isdigit(token[1]) == 0)
	{
		write_exec_err2(nm, **bcmd, token[1], ln);
		free_alloced_mem_on_exit(li, cp, bcmd);
		*es = 2;
	}
	else
	{
		stat = _atoi(token[1]);
		free_alloced_mem_on_exit(li, cp, bcmd);
		exit(stat);
	}
}

/**
 * echo_args - handles $$, $? and $VAR arguments for echo command.
 * @tok: tokenized 2d array of line ptr string.
 * @es: error status
 */

void echo_args(char **tok, int *es)
{
	int i = 1, old_size;
	int pid = (int)getpid();
	char *str, *retvar;

	while (tok[i] != NULL)
	{
		if (tok[i][0]  == '$' && _strlen(tok[i]) >= 2)
		{
			retvar = _getenv(&tok[i][1]);
			old_size = _strlen(tok[i]) + 1;
			if (tok[i][1] == '$' && tok[i][2] == '\0')
			{
				str = malloc(sizeof(char) * (count_digits(pid) + 1));
				malloc_checkptr(str);
				to_string(pid, str);
				tok[i] = _realloc(tok[i], old_size, _strlen(str) + 1);
				malloc_checkptr(tok[i]);
				str_cpy(tok[i], str);
				free(str);
			}
			else if (tok[i][1] == '?' && tok[i][2] == '\0')
			{
				str = malloc(sizeof(char) * (count_digits(*es) + 1));
				malloc_checkptr(str);
				to_string(*es, str);
				tok[i] = _realloc(tok[i], old_size, _strlen(str) + 1);
				malloc_checkptr(tok[i]);
				str_cpy(tok[i], str);
				free(str);
			}
			else if (retvar != NULL)
			{
				tok[i] = _realloc(tok[i], old_size, _strlen(retvar) + 1);
				malloc_checkptr(tok[i]);
				str_cpy(tok[i], retvar);
			}
		}
		i++;
	}
}
