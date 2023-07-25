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

/************************* Display functions ***********************/
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/*********************** Array sorting algorithms ******************/
void bubble_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
/*...................Counting sort methods.........................*/
void counting_sort(int *array, size_t size);
int *count_arr(int *array, size_t size, size_t *max, int **copy);
/*.................................................................*/
void radix_sort(int *array, size_t size);

/**************** Recursive Array sorting algorithms ***************/
/*...................Quick Sort(lomuto) methods....................*/
void quick_sort(int *array, size_t size);
int lomuto_partition(int *array, int start, int end, size_t size);
void quick_sort_init(int *array, int start, int end, size_t size);
/*..................Merge Sort(Top Down) methods...................*/
void merge_sort(int *array, size_t size);
void topdown_merge_sort(int *array, int *copy, int start, int end);
void merge(int *aux, int *arr, int start, int middle, int end);
/*..................Heap Sort(Sift Down) methods...................*/
void heap_sort(int *array, size_t size);
void sift_down(int *heap, size_t h_size, size_t size);
void build_max_heap(int *arr, size_t h_size, size_t size);
void max_heapify(int *arr, int index, size_t h_size, size_t size);
void iswap(int *x, int *y, int *arr, size_t size);
/*..................Quick Sort(Hoare) methods......................*/
void quick_sort_hoare(int *array, size_t size);


/********************** List sorting algorithms ********************/
void insertion_sort_list(listint_t **list);
/*......................Cocktail Shaker Sort methods...............*/
void cocktail_sort_list(listint_t **list);
void cocktail_swap_forward(listint_t **list, listint_t *j);
void cocktail_swap_backward(listint_t **list, listint_t *j);

#endif /*SORT_H*/
