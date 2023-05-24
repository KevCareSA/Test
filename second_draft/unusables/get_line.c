#include "main.h"

/**
 * assline - assigns the line var for rd_in
 * @lnptr: buf that store the lnin str
 * @buf: str that is been called to line
 * @n: size of line
 * @j: size of buf
 */
void assline(char **lnptr, size_t *num, char *buf, size_t sze)
{
	size_t mybuff = 1024;

	if (*lnptr == NULL)
	{
		if  (sze > mybuff)
		{
			*num = sze;
		}

		else
		{
			*num = mybuff;
		}
		*lnptr = buf;
	}
	else if (*num < sze)
	{
		if (sze > mybuff)
		{
			*num = sze;
		}
		else
			*num = mybuff;
		*lnptr = buf;
	}
	else
	{
		_strcpy(*lnptr, buf);
		free(buf);
	}
}
/**
 * rd_in - Read inpt from stream
 * @lnptr: buf that stores the lnin
 * @n: size of lnptr
 * @stream: stream to read from
 * Return: The number of bytes
 */
ssize_t rd_in(char **lnptr, size_t *n, FILE *stream)
{
	static ssize_t lnin;
	int idx;
	char * buf = NULL, tokks = 'z';
	ssize_t rt, mybuff = 1024;

	if (lnin == 0)
		fflush(stream);
	else
		return (-1);
	lnin = 0;
	buf = malloc(sizeof(char) * mybuff);
	if (buf == 0)
		return (-1);
	for (; tokks != '\n';)
	{
		idx = read(IN, &tokks, 1);
		if (idx == -1 || (idx == 0 && lnin == 0))
		{
			free(buf);
			return (-1);
		}
		if (idx == 0 && lnin != 0)
		{
			lnin += 1;
			break;
		}
		if (lnin >= mybuff)
			buf = _realloc(buf, lnin, lnin + 1);
		buf[lnin] = tokks;
		lnin += 1;
	}
	buf[lnin] = '\0';
	assline(lnptr, n, buf, lnin);
	rt = lnin;
	if (idx != 0)
		lnin = 0;
	return (rt);
}
