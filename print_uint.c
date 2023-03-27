#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
/**
 * print_unsigned_integers - a function that prints unsigned intergers.
 * @arr: array of unsigned integers.
 * @size: size of intergers as input.
 * Return: return the length of a string.
 */

int print_unsigned_integers(unsigned int num)
{
	int i, count = 0;

		while (num > 0)
		{
			putchar('0' + (num % 10));
			num /= 10;
			count++;
		}

	return (count);
}

/**
 * main - Begins function.
 * @my_array[]: array of unsigned integers.
 * Return: return 0 on success.
 */


int main(void)
{
	unsigned int num = (unsigned int)INT_MAX + 1024;
	int str_len = print_unsigned_integers(num);

	printf("Length of resulting string: %d\n", str_len);
	printf("%u", num);

	return (0);
}
