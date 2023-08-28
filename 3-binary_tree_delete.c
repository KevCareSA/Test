#include "binary_trees.h"

/**
 * binary_tree_delete - frees binary tree from heap using post-order traversal
 * @tree: pointer to the root node
 */

void binary_tree_delete(binary_tree_t *tree)
{
	if (tree != NULL)
	{
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);
		free(tree);
	}
}
