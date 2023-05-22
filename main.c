#include "main.h"

/**
 * free_data - frees data structure
 *
 * @globvar: data structure
 * Return: no return
 */
void free_data(globals_t *globvar)
{
	unsigned int i;

	for (i = 0; globvar->my_env[i]; i++)
	{
		free(globvar->my_env[i]);
	}

	free(globvar->my_env);
	free(globvar->this_pid);
}

/**
 * set_data - Initialize data structure
 *
 * @globvar: data structure
 * @av: argument vector
 * Return: no return
 */
void set_data(globals_t *globvar, char **av)
{
	unsigned int i;

	globvar->argv = av;
	globvar->linecount = 1;
	globvar->exitstat = 0;
	globvar->mytok = NULL;
	globvar->line = NULL;

	for (i = 0; environ[i]; i++)
		;

	globvar->my_env = malloc(sizeof(char *) * (i + 1));

	for (i = 0; environ[i]; i++)
	{
		globvar->my_env[i] = _strdup(environ[i]);
	}

	globvar->my_env[i] = NULL;
	globvar->this_pid = aux_itoa(getpid());
}

/**
 * main - Entry point
 *
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success.
 */
int main(int __attribute__((unused))argc, char **argv)
{
	globals_t globvar;

	signal(SIGINT, handle_C_sig);
	set_data(&globvar, argv);
	loop_parser(&globvar);
	if (globvar.exitstat < 0)
		return (255);
	return (globvar.exitstat);
}
