#include "binary_trees.h"

/**
 * full_check - determine if a tree is perfect or not.
 * @tree: root node of a tree
 * Return: 1 if a perfect tree,  0 otherwise
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
    if (node == NULL || node->parent == NULL)
        return (NULL);

    if (node->parent->left == NULL || node->parent->right == NULL)
        return (NULL);

    if (node->parent->left == node)
        return (node->parent->right);
    else
        return (node->parent->left);
}
