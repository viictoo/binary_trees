#include "binary_trees.h"

/**
 * binary_tree_rotate_left - a function that rotates a binary tree left
 * @tree: pointer to the root node of the tree to rotate
 * Return: a pointer to the new root node of the tree
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *roots;

	if (tree == NULL || tree->right == NULL)
		return (tree);
	roots = tree->right;
	tree->right = roots->left;

	if (roots->left)
		roots->left->parent = tree;

	roots->left = tree;
	roots->parent = tree->parent;
	tree->parent = roots;
	return (roots);
}
