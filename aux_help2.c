#include "main.h"

/**
 * aux_help - Help information for the builtin help.
 * Return: no return
 */
void aux_help(void)
{
	char *help = "help: help [-dms] [pattern ...]\n";

	display_out(help);
	help = "\tDisplay information about builtin commands.\n ";
	display_out(help);
	help = "Displays brief summaries of builtin commands.\n";
	display_out(help);
}
/**
 * aux_help_alias - Help information for the builtin alias.
 * Return: no return
 */
void aux_help_alias(void)
{
	char *help = "alias: alias [-p] [name[=value]...]\n";

	display_out(help);
	help = "\tDefine or display aliases.\n ";
	display_out(help);
}
/**
 * aux_help_cd - Help information for the builtin alias.
 * Return: no return
 */
void aux_help_cd(void)
{
	char *help = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

	display_out(help);
	help = "\tChange the shell working directory.\n ";
	display_out(help);
}
