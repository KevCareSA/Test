#include "binary_trees.h"

/**
 * binary_tree_insert_right - creates right child of binary tree
 * @parent: pointer to the parent node
 * @value: value of the node
 * Return: return address of new right child
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *right_child;

	if (parent == NULL)
		return (NULL);

	right_child = malloc(sizeof(binary_tree_t));
	if (right_child == NULL)
		return (NULL);

	right_child->n = value;
	right_child->left = NULL;
	right_child->parent = parent;

	if (parent->right == NULL)
		right_child->right = NULL;
	else
	{
		right_child->right = parent->right;
		right_child->right->parent = right_child;
	}
	parent->right = right_child;

	return (right_child);
}
