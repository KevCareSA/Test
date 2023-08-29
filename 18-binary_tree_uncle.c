#include "binary_trees.h"

/**
 * binary_tree_uncle - finds address of uncle node
 * @node: node to check
 * Return: address of uncle node, null otherwise
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *grandfather;

	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);

	grandfather = node->parent->parent;

	if (grandfather->left == NULL || grandfather->right == NULL)
		return (NULL);

	if (grandfather->left == node->parent)
		return (grandfather->right);
	else
		return (grandfather->left);
}
