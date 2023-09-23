#include "sort.h"

/**
 * selection_sort - Entry point-> It sorts an array of integers in
 * ascending order.
 * @array: input array to sort
 * @size: input length of the array
*/
void selection_sort(int *array, size_t size)
{
	int temp;
	size_t x, y, pos;

	if (!array || size < 2)
		return;

	for (x = 0; x < (size - 1); x++)
	{
		pos = x;
		for (y = x + 1; y < size; y++)
		{
			if (array[y] < array[pos])
				pos = y;
		}
		if (pos != x)
		{
			temp = array[x];
			array[x] = array[pos];
			array[pos] = temp;
			print_array(array, size);
		}
	}
}
