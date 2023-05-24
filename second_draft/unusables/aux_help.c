#include "main.h"

/**
 * aux_help_env - Help information for the builtin env
 * Return: no return
 */
void aux_help_env(void)
{
	char *help = "env: env [option] [name=value] [command [args]]\n\t";

	display_out(help);
	help = "Print the enviroment of the shell.\n";
	display_out(help);

}
/**
 * aux_help_setenv - Help information for the builtin setenv
 * Return: no return
 */
void aux_help_setenv(void)
{

	char *help = "setenv: setenv (const char *name, const char *value,";

	display_out(help);
	help = "int replace)\n\t";
	display_out(help);
	help = "Add a new definition to the environment\n";
	display_out(help);
}
/**
 * aux_help_unsetenv - Help information for the builtin unsetenv
 * Return: no return
 */
void aux_help_unsetenv(void)
{
	char *help = "unsetenv: unsetenv (const char *name)\n\t";

	display_out(help);
	help = "Remove an entry completely from the environment\n";
	display_out(help);
}


/**
 * aux_help_general - Entry point for help information for the help builtin
 * Return: no return
 */
void aux_help_general(void)
{
	char *help = "$ bash, version 1.0(1)-release\n";

	display_out(help);
	help = "These commands are defined internally.Type 'help' to see the list";
	display_out(help);
	help = "Type 'help name' to find out more about the function 'name'.\n\n ";
	display_out(help);
	help = " alias: alias [name=['string']]\n cd: cd [-L|[-P [-e]] [-@]] ";
	display_out(help);
	help = "[dir]\nexit: exit [n]\n  env: env [option] [name=value] [command ";
	display_out(help);
	help = "[args]]\n  setenv: setenv [variable] [value]\n  unsetenv: ";
	display_out(help);
	help = "unsetenv [variable]\n";
	display_out(help);
}
/**
 * aux_help_exit - Help information fot the builint exit
 * Return: no return
 */
void aux_help_exit(void)
{
	char *help = "exit: exit [n]\n Exit shell.\n";

	display_out(help);
	help = "Exits the shell with a status of N. If N is ommited, the exit";
	display_out(help);
	help = "statusis that of the last command executed\n";
	display_out(help);
}
