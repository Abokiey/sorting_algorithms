#include "sort.h"

/**
 * swap - Entry point-> It swaps two integers.
 * @first: input first integer
 * @second: input second integer
*/
void swap(int *first, int *second)
{
	int temp = *first;

	*first = *second;
	*second = temp;
}

/**
 * partition - Entry point-> It partitions a list for quick sort.
 * @array: input array to be sorted
 * @start: input first index of array of integers
 * @end: input last index of array of integers
 * @n: input length of array
 * Return: sorted list (Success)
*/
size_t partition(int *array, int start, int end, size_t n)
{
	int pivot;
	int idx, x;

	pivot = array[end];
	idx = start - 1;

	for (x = start; x < end; x++)
	{
		if (array[x] <= pivot)
		{
			idx++;
			if (idx != x)
			{
				swap(&array[idx], &array[x]);
				print_array(array, n);
			}
		}
	}
	if (pivot < array[idx + 1])
	{
		swap(&array[idx + 1], &array[end]);
		print_array(array, n);
	}
	return (idx + 1);
}

/**
 * quick_sort_rec - Entry point-> It recursively sorts partitions of array.
 * @array: input array to be sorted
 * @start: input first index of portion of array
 * @end: input last index of portion of array
 * @size: input length of array
*/
void quick_sort_rec(int *array, int start, int end, size_t size)
{
	int pivot_idx;

	if (start < end)
	{
		pivot_idx = partition(array, start, end, size);
		quick_sort_rec(array, start, pivot_idx - 1, size);
		quick_sort_rec(array, pivot_idx + 1, end, size);
	}
}

/**
 * quick_sort - Entry point-> It sorts an array of integer in
 * ascending order using Quick sort algorithm.
 * @array: input array to be sorted
 * @size: input length of array
*/
void quick_sort(int *array, size_t size)
{
	size_t start = 0, end = size - 1;

	if (!array || size < 2)
		return;
	quick_sort_rec(array, start, end, size);
}
