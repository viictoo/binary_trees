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

	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) + 1 +
			binary_tree_size(tree->right));
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

	for (i = 0; heap; i++)
		array[i] = heap_extract(&heap);

	return (array);
}
