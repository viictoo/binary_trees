#include "binary_trees.h"

/**
 * bst_insert - a function that inserts a value in a binary search tree
 * @tree: a double pointer to the roo node of the BST to insert the value
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node otherwise NULL
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *nunode, *curr, *nu_parent;

	if (!tree)
		return (NULL);

	nunode = binary_tree_node(NULL, value);
	if (!nunode)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = nunode;
		return (nunode);
	}

	curr = *tree;
	nu_parent = NULL;
	while (curr)
	{
		nu_parent = curr;
		if (value < curr->n)
			curr = curr->left;
		else if (value > curr->n)
			curr = curr->right;

		else
		{
			free(nunode);
			return (NULL);
		}
	}

	if (value < nu_parent->n)
		nu_parent->left = nunode;
	else
		nu_parent->right = nunode;
	nunode->parent = nu_parent;
	return (nunode);
}
