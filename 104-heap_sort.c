#include "sort.h"

/**
 * swap - Entry point-> Swaps two integers.
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
 * heapify - Entry point-> It creates heap.
 * @array: input array to be sorted
 * @start: input first index of array
 * @end: input last index of array
 * @size: input length of array
 * Return: idx of pivot integer
*/
void heapify(int *array, int start, int end, size_t size)
{
	int _start = end;
	int left = 2 * end + 1;
	int right = 2 * end + 2;

	if (left < start && array[left] > array[_start])
		_start = left;

	if (right < start && array[right] > array[_start])
		_start = right;
	if (_start != end)
	{
		swap(&array[end], &array[_start]);
		print_array(array, size);
		heapify(array, start, _start, size);
	}
}

/**
 * heap_sort - Entry point-> It sorts array of integers in ascending order
 * using heap sort algorithm.
 * @array: input array to be sorted
 * @size: input length of array
*/
void heap_sort(int *array, size_t size)
{
	int x;

	if (!array || size < 2)
		return;

	for (x = size / 2 - 1; x >= 0; x--)
		heapify(array, size, x, size);
	for (x = size - 1; x >= 0; x--)
	{
		swap(&array[0], &array[x]);

		if (x != 0)
			print_array(array, size);
		heapify(array, x, 0, size);
	}
}
