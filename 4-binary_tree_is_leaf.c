#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks if node is the leaf node
 * @node: pointer to a potential leaf node
 * Return: 1 if leaf 0 otherwise
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL || node->left != NULL || node->right != NULL)
		return (0);
	return (1);
}
