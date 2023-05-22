#include "main.h"

/**
 * exit_shell - exits the shell
 *
 * @globvar: data relevant (status and args)
 * Return: 0 on success.
 */
int exit_shell(globals_t *globvar)
{
	unsigned int ustatus;
	int is_digit;
	int str_len;
	int big_number;

	if (globvar->mytok[1] != NULL)
	{
		ustatus = _atoi(globvar->mytok[1]);
		is_digit = num_detect(globvar->mytok[1]);
		str_len = _strlen(globvar->mytok[1]);
		big_number = ustatus > (unsigned int)INT_MAX;
		if (!is_digit || str_len > 10 || big_number)
		{
			get_error(globvar, 2);
			globvar->exitstat = 2;
			return (1);
		}
		globvar->exitstat = (ustatus % 256);
	}
	return (0);
}
