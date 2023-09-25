#include "sort.h"

/**
 * counting_sort - Entry point-> It sorts array of integers in ascending order
 * using counting sort algorithm.
 * @array: input array to be sorted
 * @size: input length of array
*/
void counting_sort(int *array, size_t size)
{
	int *count, *cp, max, x;
	size_t y;

	if (!array || size < 2)
		return;
	cp = malloc((size) * sizeof(int));
	for (y = 0; y < size; y++)
		cp[y] = array[y];

	max = array[0];
	for (y = 1; y < size; y++)
	{
		if (array[y] > max)
			max = array[y];
	}
	max++;

	count = malloc(max * sizeof(int));
	if (!count)
		return;

	for (x = 0; x < max; x++)
		count[x] = 0;
	for (y = 0; y < size; y++)
		count[array[y]]++;
	for (x = 1; x < max; x++)
		count[x] += count[x - 1];
	print_array(count, max);

	for (x = size - 1; x >= 0; x--)
	{
		cp[count[array[x]] - 1] = array[x];
		count[array[x]]--;
	}
	for (y = 0; y < size; y++)
		array[y] = cp[y];
	free(count);
	free(cp);
}
