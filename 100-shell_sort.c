#include "sort.h"

/**
 * shell_sort - Entry point-> It sorts array of integers in ascending order
 * using shell sort alogorithm, Knuth sequence.
 * @array: input array to be sorted
 * @size: input length of array
*/
void shell_sort(int *array, size_t size)
{
	size_t increment = 1, x, y;
	int temp;

	if (!array || size < 2)
		return;
	while (increment < 2)
		increment = 3 * increment + 1;
	increment = (increment - 1) / 3;

	while (increment > 0)
	{
		for (x = increment; x < size; x++)
		{
			temp = array[x];
			for (y = x; y >= increment && array[y - increment] > temp; y -= increment)
				array[y] = array[y - increment];
			array[y] = temp;
		}
		increment = (increment - 1) / 3;
		print_array(array, size);
	}
}
