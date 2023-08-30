#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: A pointer to the node to measure the depth
 * Return: size_t value indicating the depth of the node
 */


size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth;
	const binary_tree_t *current;

	if (tree == NULL)
		return (0);

	current = tree;
	depth = 0;

	while (current->parent != NULL)
	{
		depth++;
		current = current->parent;
	}
	return (depth);
}
