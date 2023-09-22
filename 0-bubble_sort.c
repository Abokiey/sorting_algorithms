#include "sort.h"

/**
 * bubble_sort - bubble sort algorithm
 * @array: the array to sort
 * @size: size of the array
 *
 */

void bubble_sort(int *array, size_t size)
{
	int i, temp;
	int s = size - 1;

	if (size <= 1)
		return;

	while (s > 0)
	{
		for (i = 0; i < s; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				print_array(array, size);
			}
		}
		s -= 1;
	}

}
