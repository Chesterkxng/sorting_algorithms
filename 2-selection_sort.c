#include "sort.h"

/**
 * selection_sort - Sort using selection sort algorithm
 *
 * @array: array of integers
 *
 * @size: number of integers in the array
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j, idx;
	int temp;

	if (array && size >= 2)
	{
		for (i = 0; i < size; i++)
		{
			idx = i; /* index of the min value */

			for (j = i + 1; j < size; j++)
				if (array[j] < array[idx])
					idx = j; /* index of new min value */

			if (idx != i)
			{
				temp = array[i];
				array[i] = array[idx];
				array[idx] = temp;

				print_array(array, size);
			}
		}
	}
}
