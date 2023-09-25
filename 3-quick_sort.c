#include "sort.h"


int partition(int *arr, int low, int high, size_t size)
{
	int pivot, i, j, temp;

	pivot = arr[high];
	i = low;

	for (j = low; j < high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			if (arr[j] < pivot)
			{
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
				print_array(arr, size);

			}
			i++;

		}

	}
	if (arr[i] != arr[high])
	{
		temp = arr[i];
		arr[i] = arr[high];
		arr[high] = temp;
		print_array(arr, size);

	}
	return (i);
}

void q_sort(int *arr, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(arr, low, high, size);
		q_sort(arr, low, pivot - 1, size);
		q_sort(arr, pivot + 1, high, size);

	}

}

/**
 * quick_sort - quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;
	q_sort(array, 0, size - 1, size);

}
