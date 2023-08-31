#include "binary_trees.h"
/**
 * bst_insert_helper - a function that inserts a value in a binary search tree
 * @tree: a double pointer to the roo node of the BST to insert the value
 * @value: value to store in the node to be inserted
 * @parent: parent node
 * Return: pointer to the created node otherwise NULL
 */
bst_t *bst_insert_helper(bst_t **tree, bst_t *parent, int value)
{
	if (!tree)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(parent, value);
		return (*tree);
	}

	if (value < (*tree)->n)
		(*tree)->left = bst_insert_helper(&((*tree)->left), *tree, value);
	else if (value > (*tree)->n)
		(*tree)->right = bst_insert_helper(&((*tree)->right), *tree, value);

	return (*tree);
}
/**
 * bst_insert - a function that inserts a value in a binary search tree
 * @tree: a double pointer to the roo node of the BST to insert the value
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node otherwise NULL
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	return (bst_insert_helper(tree, NULL, value));
}

