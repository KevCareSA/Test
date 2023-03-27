#include <stdio.h>
#include <stdlib.h>

/**
 * print_unsigned_integers - a function that prints unsigned intergers.
 * @arr: array of unsigned integers.
 * @size: size of intergers as input.
 * Return: return the length of a string.
 */

int print_unsigned_integers(unsigned int arr[], int size)
{
	int i, count = 0;

	for (i = 0; i < size; i++)
	{
		unsigned int num = arr[i];

		while (num > 0)
		{
			putchar('0' + (num % 10));
			num /= 10;
			count++;
		}
		putchar(' ');
		count++;
	}

	putchar('\n');

	return (count);
}

/**
 * main - Begins function.
 * @my_array[]: array of unsigned integers.
 * Return: return 0 on success.
 */


int main(void)
{
	unsigned int my_array[] = { 10, 20, 30, 40, 50 };
	int size = sizeof(my_array) / sizeof(my_array[0]);
	int str_len = print_unsigned_integers(my_array, size);

	printf("Length of resulting string: %d\n", str_len);

	return (0);
}
