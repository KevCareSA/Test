#include "binary_trees.h"

/**
 * binary_tree_insert_left - creates left child of binary tree
 * @parent: pointer to the parent node
 * @value: value of the node
 * Return: return address of new child
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *left_child;

	if (parent == NULL)
		return (NULL);

	left_child = malloc(sizeof(binary_tree_t));
	if (left_child == NULL)
		return (NULL);

	left_child->n = value;
	left_child->right = NULL;
	left_child->parent = parent;

	if (parent->left == NULL)
		left_child->left = NULL;
	else
	{
		left_child->left = parent->left;
		left_child->left->parent = left_child;
	}
	parent->left = left_child;

	return (left_child);
}
