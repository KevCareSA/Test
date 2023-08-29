#include "binary_trees.h"

/**
 * binary_tree_balance - returns balance ratio of a tree
 * @tree: root node of a tree
 * Return: balance ratio
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int lsubtree = 0, rsubtree = 0;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL)
		lsubtree = 1 + binary_tree_height(tree->left);
	if (tree->right != NULL)
		rsubtree = 1 + binary_tree_height(tree->right);

	return (lsubtree - rsubtree);
}
