#include "main.h"

/**
 * get_help - function that retrieves help messages according builtin
 * @globvar: data structure (args and input)
 * Return: Return 0
*/
int get_help(globals_t *globvar)
{

	if (globvar->mytok[1] == 0)
		aux_help_general();
	else if (_strcmp(globvar->mytok[1], "setenv") == 0)
		aux_help_setenv();
	else if (_strcmp(globvar->mytok[1], "env") == 0)
		aux_help_env();
	else if (_strcmp(globvar->mytok[1], "unsetenv") == 0)
		aux_help_unsetenv();
	else if (_strcmp(globvar->mytok[1], "help") == 0)
		aux_help();
	else if (_strcmp(globvar->mytok[1], "exit") == 0)
		aux_help_exit();
	else if (_strcmp(globvar->mytok[1], "cd") == 0)
		aux_help_cd();
	else if (_strcmp(globvar->mytok[1], "alias") == 0)
		aux_help_alias();
	else
		display_err(globvar->mytok[0]);

	globvar->exitstat = 0;
	return (1);
}
