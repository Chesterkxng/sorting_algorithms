#include "sort.h"
/**
 * shell_sort - sorting Algorithm
 * @array: array list
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j;
	size_t gap;

	if (!array || size < 2)
		return;
	for (gap = size / 2 ; gap > 0; gap = gap / 2)
	{
		for (i = gap; i < size; i++)
		{
			for (j = i; j >= gap; j -= gap)
			{
				if (array[j - gap] > array[j])
					_swap(array, j - gap, j);
			}
		}
		print_array(array, size);
	}
}
/**
 * _swap - A function that swap two element in an array list
 * @array: int array to sort
 * @idx1 : index 1
 * @idx2: index 2
 */
void _swap(int *array, int idx1, int idx2)
{
	int temp;

	temp = array[idx1];
	array[idx1] = array[idx2];
	array[idx2] = temp;
}
