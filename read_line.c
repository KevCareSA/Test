#include "main.h"

/**
 * line_buff - reads the input string.
 *
 * @ret_eof: return value of getline function
 * Return: input string
 */
char *line_buff(int *ret_eof)
{
	char *ln = NULL;
	size_t place_holder = 0;

	*ret_eof = getline(&ln, &place_holder, stdin);

	return (ln);
}
