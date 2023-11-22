#include <stdio.h>
#include "sort.h"

/**
 * swap - swap two elements in an array
 * @array: array of integers
 * @ida : index of first element
 * @idb: index of second element
 */
void swap(int *array, unsigned int ida, unsigned int idb)
{
	int temp;

	temp = array[ida];
	array[ida] = array[idb];
	array[idb] = temp;
}

/**
 * lomuto_partition - partitions the array in subarrays
 * using Lomuto partition scheme
 *
 * @array: array of integers
 *
 * @size: number of integers in whole array
 *
 * @start: first index
 *
 * @end: last index
 *
 * Return: the index of the next pivot to use
 */
int lomuto_partition(int *array, size_t size, int start, int end)
{
	int i, j, pivot, temp1, temp2;

	pivot = array[end];
	i = start - 1;

	for (j = start; j <= end - 1; j++)
	{
		if (array[j] <= pivot)
		{
			++i;
			temp1 = array[j];
			temp2 = array[i];
			swap(array, i, j);
			if (temp1 != array[j] || temp2 != array[i])
				print_array(array, size);
		}
	}

	temp1 = array[i + 1];
	temp2 = array[end];
	swap(array, i + 1, end);
	if (temp1 != array[i + 1] || temp2 != array[end])
		print_array(array, size);

	return (i + 1);
}

/**
 * recursive_sort - sort subarray recursively
 *
 * @array: subarray of integers
 *
 * @size: number of integers of whole array
 *
 * @start: first index of the subarray
 *
 * @end: last index of the subarray
 */
void recursive_sort(int *array, size_t size, int start, int end)
{
	int pdx;

	if (array && start < end)
	{
		pdx = lomuto_partition(array, size, start, end);
		recursive_sort(array, size, start, pdx - 1);
		recursive_sort(array, size, pdx + 1, end);
	}
}
/**
 * quick_sort - Quicksort algorithm (Lomuto partition scheme)
 *
 * @array: array of integers
 *
 * @size: number of integers in the array
 */
void quick_sort(int *array, size_t size)
{
	recursive_sort(array, size, 0, size - 1);
}
