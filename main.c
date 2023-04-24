#include "main.h"

/**
 * main - handles the mode of the shell
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 Always
 */

int main(int __attribute__((unused))argc, char *argv[])
{
	if (!isatty(STDIN_FILENO))
		non_interactive_mode(argv);
	else
		my_getline(argv);

	return (0);
}
