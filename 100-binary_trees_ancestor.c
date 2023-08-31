#include "binary_trees.h"
int binary_tree_is_ancestor(const binary_tree_t *ancestor,
		const binary_tree_t *node);
/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 * Return: Pointer to the lowest common ancestor, or NULL if not found.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	if (!first || !second)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	if (binary_tree_is_ancestor(first, second))
		return ((binary_tree_t *)first);

	if (binary_tree_is_ancestor(second, first))
		return ((binary_tree_t *)second);

	return (binary_trees_ancestor(first->parent, second->parent));
}

/**
 * binary_tree_is_ancestor - Checks if a node is an ancestor of another node.
 * @ancestor: The potential ancestor node.
 * @node: The target node.
 * Return: 1 if ancestor is an ancestor of node, 0 otherwise.
 */
int binary_tree_is_ancestor(const binary_tree_t *ancestor,
		const binary_tree_t *node)
{
	if (!node)
		return (0);

	if (ancestor == node)
		return (1);

	return (binary_tree_is_ancestor(ancestor, node->parent));
}

