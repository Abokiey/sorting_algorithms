#include "sort.h"

/**
 * swap - Swap two integers in an array.
 * @a: 1st integer to swap.
 * @b: 2nd integer to swap.
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * heapify - Turns a binary tree into a binary heap.
 * @array: array of integers
 * @size: size of the array.
 * @base: index of the base row of the tree.
 * @root: root node of the binary tree.
 */
void heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		swap(array + root, array + large);
		print_array(array, size);
		heapify(array, size, base, large);
	}
}

/**
 * heap_sort - Sort an array using the heap sort algorithm.
 *
 * @array: array to be sorted.
 * @size: size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		heapify(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap(array, array + i);
		print_array(array, size);
		heapify(array, size, i, 0);
	}
}
