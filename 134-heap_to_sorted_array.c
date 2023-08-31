#include "binary_trees.h"
#include <stdbool.h>
/**
 * bit_size - Measures the height of a binary tree
 *
 * @tree: Pointer to the node to measures the size
 *
 * Return: The size of the tree starting at @node
 */
size_t bit_size(const binary_tree_t *tree)
{
	size_t left_size = 0;
	size_t right_size = 0;

	if (tree == NULL)
		return (0);


	if (tree->left)
		left_size = 1 + bit_size(tree->left);

	if (tree->right)
		right_size = 1 + bit_size(tree->right);

	return (left_size + right_size);
}

/**
 * heap_to_sorted_array - converts a Binary Max Heap
 * to a sorted array of integers
 *
 * @heap: a pointer to the root node of the heap to convert
 * @size: an address to store the size of the array
 *
 * Return: sorted array
 */

int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int i;
	int *array = NULL;

	if (!heap || !size)
		return (NULL);

	*size = bit_size(heap) + 1;
	array = malloc(sizeof(int) * (*size));
	if (!array)
		return (NULL);

	for (i = 0; i < (int)*size; i++)
	{
		if (heap)
		{
			array[i] = heap_extract(&heap);
		}
		else
		{
			break;
		}
	}

	return (array);
}
