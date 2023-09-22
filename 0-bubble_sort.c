#include "sort.h"

/**
 * bubble_sort - Entry point-> It sorts array of integer using bubble sort.
 * @array: input array of integers
 * @size: input length of the array
*/
void bubble_sort(int *array, size_t size)
{
	size_t x;
	int temp, swap;

	if (!array || size < 2)
		return;

	while (swap)
	{
		swap = 0;
		for (x = 0; x < (size - 1); x++)
		{
			if (array[x] > array[x + 1])
			{
				temp = array[x];
				array[x] = array[x + 1];
				array[x + 1] = temp;
				swap = 1;
				print_array(array, size);
			}
		}
	}
}
