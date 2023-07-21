#include <stdio.h>
#include <stdlib.h>
#include "../sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {88, 2, 55, 17, 37, 46, 92, 42, 76, 6, 72, 1, 48, 63, 7, 36,
                    97, 14, 12, 52, 33, 16, 73, 15, 60, 94, 79, 19, 67, 71};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    shell_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
