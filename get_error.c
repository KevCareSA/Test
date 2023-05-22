#include "main.h"

/**
 * get_error - calls the error according the builtin, syntax or permission
 * @globvar: data structure that contains arguments
 * @eval: error value
 * Return: error
 */
int get_error(globals_t *globvar, int eval)
{
	char *error;

	switch (eval)
	{
	case -1:
		error = error_env(globvar);
		break;
	case 126:
		error = error_path_126(globvar);
		break;
	case 127:
		error = error_not_found(globvar);
		break;
	case 2:
		if (_strcmp("exit", globvar->mytok[0]) == 0)
			error = error_exit_shell(globvar);
		else if (_strcmp("cd", globvar->mytok[0]) == 0)
			error = error_get_cd(globvar);
		break;
	}

	if (error)
	{
		display_err(error);
		free(error);
	}

	globvar->exitstat = eval;
	return (eval);
}
