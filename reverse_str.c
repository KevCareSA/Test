#include <stdio.h>
#include <string.h>

/**
 * reverse - function that reverses a string.
 * @str: string argument.
 * Return: The number of characters in string.
 */

int reverse(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		i++;
	}
	for (int j = i - 1; j >= 0; j--)
	{
		putchar(str[j]);
	}
}

/**
 * main - function main.
 * Return: 0 on success.
 */

int main(void)
{
	char str[] = "hey";

	reverse(str);
    /*expected output: yeh*/
}
