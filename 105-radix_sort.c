#include "sort.h"

/**
 * radix_sort - sorts an array
 * @array: array to  be sorted
 * @size: size of the array
 */

void radix_sort(int *array, size_t size)
{
	int swapped = 1, n = 10;
	size_t j, f;

	if (!array || size == 1)
		return;
	while (swapped)
	{
		swapped = 0;
		for (j = 1, f = 1; j <  size; j++, f++)
		{
			if ((array[j - 1] % (n * 10)) / ((n * 10) / 10) > 0)
				swapped = 1;
			if (((array[j - 1] % n) / (n / 10)) > ((array[j] % n) / (n / 10)))
			{
				array[j - 1] = array[j - 1] + array[j];
				array[j] = array[j - 1] - array[j];
				array[j - 1] = array[j - 1] - array[j];
				if ((j - 1) > 0)
					j = j - 2;
			}
		}
		print_array(array, size);
		n = n * 10;
	}
}
