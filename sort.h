#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/*Display functions*/
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/*Array sorting algorithms*/
void bubble_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);

/*Recursive Array sorting algorithms*/
void quick_sort(int *array, size_t size);
int lomuto_partition(int *array, int start, int end, size_t size);
void quick_sort_init(int *array, int start, int end, size_t size);

/*List sorting algorithms*/
void insertion_sort_list(listint_t **list);

void cocktail_sort_list(listint_t **list);
void cocktail_swap_forward(listint_t **list, listint_t *j);
void cocktail_swap_backward(listint_t **list, listint_t *j);

#endif /*SORT_H*/
