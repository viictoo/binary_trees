#include "binary_trees.h"

/**
 * heap_insert - Insert a value into a Max Binary Heap.
 * @root: Double pointer to the root node of the heap.
 * @value: The value to insert.
 * Return: Pointer to the created node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	if (!root)
		return NULL;

	heap_t *new_node = binary_tree_node(NULL, value);
	if (!new_node)
		return NULL;

	if (!*root)
	{
		*root = new_node;
		return new_node;
	}

	heap_t *current = *root;
	heap_t *parent = NULL;

	while (current)
	{
		parent = current;

		if (current->n < value)
		{
			current = current->left;
		}
		else
		{
			current = current->right;
		}
	}

	if (!parent->left)
	{
		parent->left = new_node;
	}
	else
	{
		parent->right = new_node;
	}

	new_node->parent = parent;

	/* Heapify upwards to maintain Max Heap property */
	while (parent && new_node->n > parent->n)
	{
		int temp = new_node->n;
		new_node->n = parent->n;
		parent->n = temp;

		new_node = parent;
		parent = parent->parent;
	}

	return new_node;
}

