#include "binary_trees.h"

/**
 * binary_tree_delete - frees binary tree from heap using post-order traversal
 * @tree: pointer to the root node
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
    if (node == NULL || node->left != NULL || node->right != NULL)
        return (0);
    return (1);
}
