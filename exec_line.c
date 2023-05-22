#include "main.h"

/**
 * exec_line - finds builtins and commands
 *
 * @globvar: data relevant (args)
 * Return: 1 on success.
 */
int exec_line(globals_t *globvar)
{
	int (*builtin)(globals_t *globvar);

	if (globvar->mytok[0] == NULL)
		return (1);

	builtin = get_builtin(globvar->mytok[0]);

	if (builtin != NULL)
		return (builtin(globvar));

	return (cmd_exec(globvar));
}
