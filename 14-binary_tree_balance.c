#include "binary_trees.h"

/**
 * tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */
size_t tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t lh = 0, rh = 0;

		lh = tree->left ? 1 + tree_height(tree->left) : 0;
		rh = tree->right ? 1 + tree_height(tree->right) : 0;
		return ((lh > rh) ? lh : rh);
	}
	return (0);
}

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
		lsubtree = 1 + tree_height(tree->left);
	if (tree->right != NULL)
		rsubtree = 1 + tree_height(tree->right);

	return (lsubtree - rsubtree);
}
