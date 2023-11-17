#include "sort.h"
/**
 * bubble_sort - sorting algorithm
 * @array: array of integers
 * @size: size of the array
 */
void bubble_sort(int *array,  ize_t size)
{
	int is_swapped = 1;
	size_t j = 0;

	if (!array || size < 2)
		return;
	while (is_swapped != 0)
	{
		is_swapped = 0;
		j = 0;
		while (j < size - 1)
		{
			if (array[j] > array[j + 1])
			{
				_swap(array, j, j + 1);
				is_swapped = 1;
				print_array(array, size);
			}
			j++;
		}
	}
}
/**
 * _swap - a function that swap two element in an array list
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
