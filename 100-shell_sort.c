#include "sort.h"

/**
 * shell_sort - shell sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */

void shell_sort(int *array, size_t size)
{

	size_t gap = 1, j, k;
	int temp;

	if (array == NULL || size < 2)
		return;

	while (gap < size / 3)
		gap = (gap * 3) + 1;

	while (gap)
	{
		for (j = gap; j < size; j++)
		{
			temp = array[j];
			for (k = j; k >= gap && array[k - gap] > temp; k -= gap)
			{
				array[k] = array[k - gap];
			}
			array[k] = temp;
		}
		print_array(array, size);
		gap /= 3;
	}
	

}
