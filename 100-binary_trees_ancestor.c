#include "binary_trees.h"

/**
  * binary_trees_ancestor - a function that creates a binary tree node
  * @second: pointer to a node
  * @first:pointer to a node
  * Return: pointer to the node or NULL on failure
  */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{

	if (!second || !first)
		return (NULL);

	if (!second->parent || !first->parent)
		return (NULL);

	if (first->parent->n == second->n)
		return (first->parent);
	else if (first->parent->n != second->n)
		(binary_trees_ancestor(first->parent, second));

	if (first->n == second->parent->n)
		return (second->parent);
	else if (first->n != second->parent->n)
		(binary_trees_ancestor(first, second->parent));

	return (NULL);
}
