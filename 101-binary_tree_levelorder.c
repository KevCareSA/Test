#include "binary_trees.h"

queue *enqueue(queue **head, binary_tree_t *node)
{
    queue *new;

    if (head == NULL || *head == NULL || node == NULL)
        return (NULL);

    new = malloc(sizeof(queue));
    if (new == NULL)
        return (NULL);

    new->node = node;
    new->prev = NULL;

    (*head)->prev = new;
    new->next = *head;
    *head = new;

    return (new);
}

void dequeue(queue **head, void (*func)(int))
{
    queue *ptr;

    if (head == NULL || *head == NULL)
        return;

    ptr = *head;
    *head = (*head)->next;
    func(ptr->node->n);
    free(ptr);
}
/*
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{

}
*/
