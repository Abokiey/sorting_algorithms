#include "sort.h"

/**
 * bubble_sort - bubble sort algorithm
 * @array: the array to sort
 * @size: size of the array
 *
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, swap;

	for (j = size, swap = 1; j > 0 && swap; j--)
	{
		swap = 0;
		for (i = 0; (i + 1) < j; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = temp;
				print_array(array, size);
				swap = 1;
			}
		}
	}
}
