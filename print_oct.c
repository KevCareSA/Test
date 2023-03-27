#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int print_oct(unsigned int input)
{
	unsigned int copy, len = 0;
	int i = 0;
	int *buffer;
	char search[] = "01234567";

	if (input == 0)
	{
		putchar ('0');
		return (1);
	}

	copy = input;
	while (copy)
	{
		copy /= 8;
		len++;
	}

	buffer = (int *)malloc(sizeof(int) * len);

	while (input)
	{
		buffer[i] = input % 8;
		input /= 8;
		i++;
	}

	for (i = len - 1; i >= 0; i--)
		putchar(search[buffer[i]]);

	free(buffer);

	return (len);
}
int main(void)
{
	unsigned int ui = (unsigned int)INT_MAX + 1024;

	/*using created function*/
	printf("\nlen: %d\n", print_oct(12));
	/*using printf*/
	printf("\nlen: %d\n", printf("%o", 12));

	putchar('\n');

	/*using created function*/
	printf("\nlen: %d\n", print_oct(ui));
	/*using printf*/
	printf("\nlen: %d\n", printf("%o", ui));
}
