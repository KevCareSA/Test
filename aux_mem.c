#include "main.h"

/**
 * _memcpy - copies information between void pointers.
 * @newptr: destination pointer.
 * @ptr: source pointer.
 * @size: size of the new pointer.
 *
 * Return: no return.
 */
void _memcpy(void *newptr, const void *ptr, unsigned int size)
{
	char *char_ptr = (char *)ptr;
	char *char_newptr = (char *)newptr;
	unsigned int i;

	for (i = 0; i < size; i++)
		char_newptr[i] = char_ptr[i];
}

/**
 * _realloc - reallocates memory
 * @ptr: ptr to memory to be allocated
 * @o_size: size of memory before allocation
 * @n_size: desired size of memory after allocation
 *
 * Return: address of reallocated memory
 */

void *_realloc(void *ptr, unsigned int o_size, unsigned int n_size)
{
	void *mem;
	char *copy, *temp;
	unsigned int i;

	if (n_size == o_size)
		return (ptr);

	if (ptr == NULL)
	{
		mem = malloc(n_size);
		if (mem == NULL)
			return (NULL);
		return (mem);
	}

	if (n_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	copy = ptr;
	mem = malloc(sizeof(*copy) * n_size);

	if (mem == NULL)
	{
		free(ptr);
		return (NULL);
	}

	temp = mem;

	for (i = 0; i < o_size && i < n_size; i++)
		temp[i] = *copy++;

	free(ptr);
	return (mem);
}

/**
 * dprllc - reallocates a memory block of a double pointer.
 * @ptr: double pointer to the memory previously allocated.
 * @old_size: size, in bytes, of the allocated space of ptr.
 * @new_size: new size, in bytes, of the new memory block.
 *
 * Return: ptr.
 * if new_size == old_size, returns ptr without changes.
 * if malloc fails, returns NULL.
 */
char **dprllc(char **ptr, unsigned int old_size, unsigned int new_size)
{
	char **newptr;
	unsigned int i;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * new_size));

	if (new_size == old_size)
		return (ptr);

	newptr = malloc(sizeof(char *) * new_size);
	if (newptr == NULL)
		return (NULL);

	for (i = 0; i < old_size; i++)
		newptr[i] = ptr[i];

	free(ptr);

	return (newptr);
}
