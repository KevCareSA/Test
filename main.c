#include <stdio.h>
#include "main.h"
#include <limits.h>

/**
 * main - check the code for displaying outputs.
 * Return: 0 on success.
 */

int main(void)
{
	int len;
	int len2;
	unsigned int ui = (unsigned int)INT_MAX + 1024;
	void *addr = (void *)0x7ffe637541f0;

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);
	_printf("Negative:[%d]\n", -762534);
	printf("Negative:[%d]\n", -762534);
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	len = _printf("Percent:[%%]\n");
	len2 = printf("Percent:[%%]\n");
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("binary:[%b]\n", 15);
    printf("binary:[1111]\n");
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	_printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
	len = _printf("Address:[%p]\n", addr);
    len2 = printf("Address:[%p]\n", addr);
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
    _printf("Reverse:[%r]\n", "Hello World");
    printf("Reverse:[Hello World]\n");
	printf("rot13 encoded: P vf sha\n");
	_printf("rot13 decoded: %R\n", "P vf sha");
	printf("String with hidden characters: Date: 22/02/2002\\n\n");
	_printf("String with hidden characters: Date: %S\n", "22/02/2002\n");

	return (0);
}
