#include "binary_trees.h"

/**
 * full_check - uses recurision to traverse tree and check for children count
 * @tree: root node of a tree
 * @full: intialized to 1 assuming every tree will be a full tree
 * Return: 1 if full tree 0 if not
 */

int full_check(const binary_tree_t *tree, int full)
{
	if (tree != NULL)
	{
		if ((!tree->left && tree->right) || (tree->left && !tree->right))
			full = 0;
		full = full_check(tree->left, full);
		full = full_check(tree->right, full);
	}
	return (full);
}

/**
 * binary_tree_is_full - determines if tree is a full tree
 * @tree: root node of a tree
 * Return: 1 if full tree 0 if not
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int full = 1;

	if (tree == NULL)
		return (0);
	return (full_check(tree, full));
}
