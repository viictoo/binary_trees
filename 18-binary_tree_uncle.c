#include "binary_trees.h"

/**
  * binary_tree_uncle - a function that creates a binary tree node
  * @node: pointer to the parent node
  * Return: pointer to the node or NULL on failure
  */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{

	if (!node || !(node->parent) || !(node->parent->parent))
		return (NULL);

	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);

	return (node->parent->parent->left);
}
