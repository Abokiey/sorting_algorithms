#include "sort.h"

/**
 * merge - Entry point-> It merges list of sorted arrays.
 * @array: input array to be sorted
 * @start: input first index of array
 * @end: input last index of array
 * @mid: input middle index of array
 * @size: input length of array
*/
void merge(int *array, int start, int mid, int end, size_t size)
{
	int *cp;
	int x, y, z;

	cp = malloc(size * sizeof(int));
	if (!cp)
		return;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + start, mid - start);
	printf("[right]: ");
	print_array(array + mid, end - mid);

	for (x = start, y = mid, z = start; z < end; z++)
	{
		if (x < mid && (y >= end || array[x] <= array[y]))
		{
			cp[z] = array[x];
			x++;
		}
		else
		{
			cp[z] = array[y];
			y++;
		}
	}
	for (z = start; z < end; z++)
		array[z] = cp[z];

	printf("[Done]: ");
	print_array(array + start, end - start);
	free(cp);
}

/**
 * merge_sort_rec - Entry point-> It recusively divides partitions of array.
 * @array: input array to be sorted
 * @start: input first index of portion of array
 * @end: input last index of portion of array
 * @size: input length of array
*/
void merge_sort_rec(int *array, int start, int end, size_t size)
{
	int mid;

	if (end - start < 2)
		return;
	mid = (start + end) / 2;
	merge_sort_rec(array, start, mid, size);
	merge_sort_rec(array, mid, end, size);
	merge(array, start, mid, end, size);
}

/**
 * merge_sort - Entry point-> It sorts array of integers in ascending order
 * using the merge sort algorithm.
 * @array: input array to be sorted
 * @size: input length of array
*/
void merge_sort(int *array, size_t size)
{
	size_t start = 0, end = size;

	if (!array || size < 2)
		return;
	merge_sort_rec(array, start, end, size);
}
