#include "binary_trees.h"

/**
 * binary_tree_rotate_right - a function that rotates a binary tree right
 * @tree: pointer to the root node of the tree to rotate
 * Return: a pointer to the new root node of the tree
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *temp;

	if (tree == NULL)
		return (NULL);

	temp = tree->left;

	tree->left = tree->left->right;
	if (temp->right)
		temp->right->parent = tree;
	temp->right = tree;
	temp->parent = tree->parent;
	tree->parent = temp;
	return (temp);
}
