#include "binary_trees.h"
#include <stdbool.h>
/**
 * binary_tree_size - Measures the height of a binary tree
 *
 * @tree: Pointer to the node to measures the size
 *
 * Return: The size of the tree starting at @node
 */
size_t binary_tree_size(const binary_tree_t *tree)
{

	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) + 1 +
			binary_tree_size(tree->right));
}
