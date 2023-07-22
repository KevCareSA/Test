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
    int array[] = {10, 8, 5, 3, 5, 3, 2, 4, 2, 10, 10, 10, 8, 5, 2, 9, 8, 5, 6, 9, 8, 10, 4, 2, 10, 5, 1, 2, 4, 5};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    counting_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
