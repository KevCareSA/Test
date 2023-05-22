
#include "main.h"

/**
 * reverse_str - reverses a string.
 * @input: input string.
 * Return: no return.
 */
void reverse_str(char *s)
{
	int counter = 0;
	char *len;
	char place_holder = 'x';
	int i = 0;

	/*find length of string*/
	len = s;
	while (*len != '\0')
	{
		counter++;
		len += 1;
	}

	for (i = counter - 1; i >= counter / 2; i--)
	{
		place_holder = *(s + i);
		*(s + i) = *(s + counter - i - 1);
		*(s + counter - i - 1) = place_holder;
	}
}
