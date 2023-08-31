#include "binary_trees.h"
/**
 * binary_tree_leaves - Measures the height of a binary tree
 *
 * @tree: Pointer to the node to measures the size
 *
 * Return: The size of the tree starting at @node
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{

	if (tree == NULL)
		return (0);

	if (!tree->right && !tree->left)
		return (1);
	return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}
