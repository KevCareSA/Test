#include "binary_trees.h"

/**
 * full_check - determine if a tree is perfect or not.
 * @tree: root node of a tree
 * Return: 1 if a perfect tree,  0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    if (binary_tree_is_full(tree) == 1 && binary_tree_balance(tree) == 0)
        return (1);

    return (0);
}
