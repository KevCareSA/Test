#include "main.h"

/**
 * cd_dot - changes to the parent directory
 *
 * @globvar: data relevant (environ)
 *
 * Return: no return
 */
void cd_dot(globals_t *globvar)
{
	char pwd[PATH_MAX];
	char *dir, *cp_pwd, *cp_strtok_pwd;

	getcwd(pwd, sizeof(pwd));
	cp_pwd = _strdup(pwd);
	set_env("OLDPWD", cp_pwd, globvar);
	dir = globvar->mytok[1];
	if (_strcmp(".", dir) == 0)
	{
		set_env("PWD", cp_pwd, globvar);
		free(cp_pwd);
		return;
	}
	if (_strcmp("/", cp_pwd) == 0)
	{
		free(cp_pwd);
		return;
	}
	cp_strtok_pwd = cp_pwd;
	reverse_str(cp_strtok_pwd);
	cp_strtok_pwd = _strtok(cp_strtok_pwd, "/");
	if (cp_strtok_pwd != NULL)
	{
		cp_strtok_pwd = _strtok(NULL, "\0");

		if (cp_strtok_pwd != NULL)
			reverse_str(cp_strtok_pwd);
	}
	if (cp_strtok_pwd != NULL)
	{
		chdir(cp_strtok_pwd);
		set_env("PWD", cp_strtok_pwd, globvar);
	}
	else
	{
		chdir("/");
		set_env("PWD", "/", globvar);
	}
	globvar->exitstat = 0;
	free(cp_pwd);
}

/**
 * cd_to - changes to a directory given
 * by the user
 *
 * @globvar: data relevant (directories)
 * Return: no return
 */
void cd_to(globals_t *globvar)
{
	char pwd[PATH_MAX];
	char *dir, *cp_pwd, *cp_dir;

	getcwd(pwd, sizeof(pwd));

	dir = globvar->mytok[1];
	if (chdir(dir) == -1)
	{
		get_error(globvar, 2);
		return;
	}

	cp_pwd = _strdup(pwd);
	set_env("OLDPWD", cp_pwd, globvar);

	cp_dir = _strdup(dir);
	set_env("PWD", cp_dir, globvar);

	free(cp_pwd);
	free(cp_dir);

	globvar->exitstat = 0;

	chdir(dir);
}

/**
 * cd_previous - changes to the previous directory
 *
 * @globvar: data relevant (environ)
 * Return: no return
 */
void cd_previous(globals_t *globvar)
{
	char pwd[PATH_MAX], *newln = "\n";
	char *p_pwd, *p_oldpwd, *cp_pwd, *cp_oldpwd;

	getcwd(pwd, sizeof(pwd));
	cp_pwd = _strdup(pwd);

	p_oldpwd = _getenv("OLDPWD", globvar->my_env);

	if (p_oldpwd == NULL)
		cp_oldpwd = cp_pwd;
	else
		cp_oldpwd = _strdup(p_oldpwd);

	set_env("OLDPWD", cp_pwd, globvar);

	if (chdir(cp_oldpwd) == -1)
		set_env("PWD", cp_pwd, globvar);
	else
		set_env("PWD", cp_oldpwd, globvar);

	p_pwd = _getenv("PWD", globvar->my_env);

	display_out(p_pwd);
	display_out(newln);

	free(cp_pwd);
	if (p_oldpwd)
		free(cp_oldpwd);

	globvar->exitstat = 0;

	chdir(p_pwd);
}

/**
 * cd_to_home - changes to home directory
 *
 * @globvar: data relevant (environ)
 * Return: no return
 */
void cd_to_home(globals_t *globvar)
{
	char *p_pwd, *home;
	char pwd[PATH_MAX];

	getcwd(pwd, sizeof(pwd));
	p_pwd = _strdup(pwd);

	home = _getenv("HOME", globvar->my_env);

	if (home == NULL)
	{
		set_env("OLDPWD", p_pwd, globvar);
		free(p_pwd);
		return;
	}

	if (chdir(home) == -1)
	{
		get_error(globvar, 2);
		free(p_pwd);
		return;
	}

	set_env("OLDPWD", p_pwd, globvar);
	set_env("PWD", home, globvar);
	free(p_pwd);
	globvar->exitstat = 0;
}
