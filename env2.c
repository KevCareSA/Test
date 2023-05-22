#include "main.h"

/**
 * copy_info - copies info to create
 * a new env or alias
 * @name: name (env or alias)
 * @value: value (env or alias)
 *
 * Return: new env or alias.
 */
char *copy_info(char *name, char *value)
{
	char *new;
	int len_name, len_value, len;

	len_name = _strlen(name);
	len_value = _strlen(value);
	len = len_name + len_value + 2;
	new = malloc(sizeof(char) * (len));
	_strcpy(new, name);
	_strcat(new, "=");
	_strcat(new, value);
	_strcat(new, "\0");

	return (new);
}

/**
 * set_env - sets an environment variable
 *
 * @name: name of the environment variable
 * @value: value of the environment variable
 * @globvar: data structure (environ)
 * Return: no return
 */
void set_env(char *name, char *value, globals_t *globvar)
{
	int i;
	char *var_env, *name_env;

	for (i = 0; globvar->my_env[i]; i++)
	{
		var_env = _strdup(globvar->my_env[i]);
		name_env = _strtok(var_env, "=");
		if (_strcmp(name_env, name) == 0)
		{
			free(globvar->my_env[i]);
			globvar->my_env[i] = copy_info(name_env, value);
			free(var_env);
			return;
		}
		free(var_env);
	}

	globvar->my_env = dprllc(globvar->my_env, i, sizeof(char *) * (i + 2));
	globvar->my_env[i] = copy_info(name, value);
	globvar->my_env[i + 1] = NULL;
}

/**
 * _setenv - compares env variables names
 * with the name passed.
 * @globvar: data relevant (env name and env value)
 *
 * Return: 1 on success.
 */
int _setenv(globals_t *globvar)
{

	if (globvar->mytok[1] == NULL || globvar->mytok[2] == NULL)
	{
		get_error(globvar, -1);
		return (1);
	}

	set_env(globvar->mytok[1], globvar->mytok[2], globvar);

	return (1);
}

/**
 * _unsetenv - deletes a environment variable
 *
 * @globvar: data relevant (env name)
 *
 * Return: 1 on success.
 */
int _unsetenv(globals_t *globvar)
{
	char **realloc_environ;
	char *var_env, *name_env;
	int i, j, k;

	if (globvar->mytok[1] == NULL)
	{
		get_error(globvar, -1);
		return (1);
	}
	k = -1;
	for (i = 0; globvar->my_env[i]; i++)
	{
		var_env = _strdup(globvar->my_env[i]);
		name_env = _strtok(var_env, "=");
		if (_strcmp(name_env, globvar->mytok[1]) == 0)
		{
			k = i;
		}
		free(var_env);
	}
	if (k == -1)
	{
		get_error(globvar, -1);
		return (1);
	}
	realloc_environ = malloc(sizeof(char *) * (i));
	for (i = j = 0; globvar->my_env[i]; i++)
	{
		if (i != k)
		{
			realloc_environ[j] = globvar->my_env[i];
			j++;
		}
	}
	realloc_environ[j] = NULL;
	free(globvar->my_env[k]);
	free(globvar->my_env);
	globvar->my_env = realloc_environ;
	return (1);
}
