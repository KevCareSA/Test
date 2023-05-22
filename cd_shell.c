#include "main.h"

/**
 * cd_shell - changes current directory
 *
 * @globvar: data relevant
 * Return: 1 on success
 */
int cd_shell(globals_t *globvar)
{
	char *dir;
	int ishome, ishome2, isddash;

	dir = globvar->mytok[1];

	if (dir != NULL)
	{
		ishome = _strcmp("$HOME", dir);
		ishome2 = _strcmp("~", dir);
		isddash = _strcmp("--", dir);
	}

	if (dir == NULL || !ishome || !ishome2 || !isddash)
	{
		cd_to_home(globvar);
		return (1);
	}

	if (_strcmp("-", dir) == 0)
	{
		cd_previous(globvar);
		return (1);
	}

	if (_strcmp(".", dir) == 0 || _strcmp("..", dir) == 0)
	{
		cd_dot(globvar);
		return (1);
	}

	cd_to(globvar);

	return (1);
}
