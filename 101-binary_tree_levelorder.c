#include "binary_trees.h"

/**
 * enqueue - pushes node item onto the queue
 * @tail: end of the queue
 * @node: node to be queued
 * Return: address of new node or NULL if fails
 */
queue *enqueue(queue **tail, const binary_tree_t *node)
{
	queue *new;

	if (tail == NULL || node == NULL)
		return (NULL);

	new = malloc(sizeof(queue));
	if (new == NULL)
		return (NULL);

	new->node = node;
	new->prev = *tail;
	new->next = NULL;

	if (*tail != NULL)
		(*tail)->next = new;

	*tail = new;

	return (new);
}

/**
 * dequeue - applies func on item then deletes item from queue
 * @head: start of queue
 * @func: function pointer
 */
void dequeue(queue **head, void (*func)(int))
{
	queue *temp;

	temp = *head;
	*head = (*head)->next;
	func(temp->node->n);
	free(temp);
}

/**
 * binary_tree_levelorder - treverses tree level orderly an applies func on
 *                          each node
 * @tree: root node of binary tree
 * @func: function pointer
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue *head = NULL, *tail = NULL;

	if (tree == NULL || func == NULL)
		return;

	head = enqueue(&tail, tree);

	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			tail = enqueue(&tail, head->node->left);
			if (tail == NULL)
				return;
		}
		if (head->node->right != NULL)
		{
			tail = enqueue(&tail, head->node->right);
			if (tail == NULL)
				return;
		}

		dequeue(&head, func);
	}
}
