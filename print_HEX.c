#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int print_HEX(unsigned int input)
{
	unsigned int copy, len = 0;
	int i = 0;
	int *buffer;
	char search[] = "0123456789ABCDEF";

	if (input == 0)
	{
		putchar ('0');
		return (1);
	}

	copy = input;
	while (copy)
	{
		copy /= 16;
		len++;
	}

	buffer = (int *)malloc(sizeof(int) * len);

	while (input)
	{
		buffer[i] = input % 16;
		input /= 16;
		i++;
	}

	for (i = len - 1; i >= 0; i--)
		putchar(search[buffer[i]]);

	return (len);
}
int main(void)
{
	unsigned int ui = (unsigned int)INT_MAX + 1024;

	/*using created function*/
	printf("\nlen: %d\n", print_HEX(12));
	/*using printf*/
	printf("\nlen: %d\n", printf("%X", 12));

	putchar('\n');

	/*using created function*/
	printf("\nlen: %d\n", print_HEX(ui));
	/*using printf*/
	printf("\nlen: %d\n", printf("%X", ui));
}
