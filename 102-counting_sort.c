#include "sort.h"

/**
 * save_array_val_occur - store occurences of values of one array to another
 *
 * @array1: first array
 *
 * @size1: size of first array
 *
 * @array2: second array
 *
 * @size2: size of second array
 */
void save_array_val_occur(int *array1, size_t size1, int *array2, size_t size2)
{
	unsigned int i, j, sum;

	for (i = 0; i < size2; i++)
	{
		sum = 0;
		for (j = 0; j < size1; j++)
			if (array1[j] == (int)i)
				++sum;
		array2[i] = sum;
	}

}

/**
 * counting_sort - Counting sort algorithm
 *
 * @array: array of integers
 *
 * @size: number of intergers
 */
void counting_sort(int *array, size_t size)
{
	int i, j, max;
	int *count, *sorted;

	/* don't sort empty array or one element array */
	if (!array || size == 1)
		return;

	for (i = 0, max = array[i]; (unsigned int)i < size; i++)
		if (array[i] > max)
			max = array[i];

	count = malloc(sizeof(int) * (max + 1));
	if (!count)
		return;

	for (i = 0; i < max + 1; i++)
		count[i] = 0;

	save_array_val_occur(array, size, count, max + 1);

	for (i = 1; i < max + 1; i++)
		count[i] = count[i - 1] + count[i];

	print_array(count, max + 1);

	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		return;

	for (i = size - 1; i >= 0; i--)
	{
		j = count[array[i]] - 1;
		sorted[j] = array[i];
	}
	for (i = 0, j = 0; (unsigned int)i < size; i++)
		array[i] = sorted[i];

	free(count);
	free(sorted);
}
