#include "binary_trees.h"
int height(const binary_tree_t *tree);
void levels(const binary_tree_t *tree, void (*func)(int), int level);

/**
 * binary_tree_levelorder - a function that gets the level of a binary tree
 * @tree: pointer to the root node of a binary tree
 * @func: function
 * Return: void
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int h = height(tree);
	int i;

	for (i = 1; i <= h; i++)
		levels(tree, func, i);
}
/**
 * levels - a function that gets the current level of a binary tree
 * @tree: the tree to check
 * @level: integer
 * @func: function
 * Return: void
*/
void levels(const binary_tree_t *tree, void (*func)(int), int level)
{
	if (tree == NULL)
		return;
	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		levels(tree->left, func, level - 1);
		levels(tree->right, func, level - 1);
	}
}
/**
 * height - a function that gets the height of a binary tree
 * @tree: pointer to the root node of a binary tree
 * Return: longest distance to last leaf of binary tree
*/
int height(const binary_tree_t *tree)
{
	int lef = height(tree->left);
	int rite = height(tree->right);

	if (tree == NULL)
	return (0);

	if (lef > rite)
		return (lef + 1);

	return (rite + 1);
}
