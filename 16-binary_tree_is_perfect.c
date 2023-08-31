#include "binary_trees.h"
/**
 * depth - a function that returns the depth of a tree node
 * @tree: pointer to the tree node to check
 * Return: integer otherwise 0
  */
int depth(const binary_tree_t *tree)
{
	int dep = 0;

	while (tree != NULL)
	{
		dep++;
		tree = tree->left;
	}
	return (dep);
}
/**
 * is_perfect - A function that checks id a binary tree is perfect
 * @tree: pointer to a binary tree
 * @d: depth of a binary tree
 * @level: levels to check
 * Return: 1 if perfect otherwise 0
 */

int is_perfect(const binary_tree_t *tree, int d, int level)
{
	if (!tree)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (d == level + 1);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (is_perfect(tree->left, d, level + 1) &&
		is_perfect(tree->right, d, level + 1));
}

/**
 * binary_tree_is_perfect - A function that checks if a binary tree is perfect
 * @tree: pointer to a binary tree
 * Return: 1 if perfect otherwise 0
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int deep;

	deep = depth(tree);

	return (is_perfect(tree, deep, 0));
}
