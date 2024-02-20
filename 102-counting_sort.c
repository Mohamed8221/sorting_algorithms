#include "sort.h"

/**
* counting_sort - Sorts an array
* @array: The array of integers to be sorted.
* @size: The size of the array.
*/

void counting_sort(int *array, size_t size)
{
	int i, *res, max = 0, *count;

	if (array == NULL || size < 2)
	return;

	for (i = 0; i < (int)size; i++)
	if (array[i] > max)
		max = array[i];

	count = malloc(sizeof(int) * (max + 1));
	for (i = 0; i <= max; i++)
		count[i] = 0;

	for (i = 0; i < (int)size; i++)
		count[array[i]]++;

	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];

	print_array(count, max + 1);

	res = malloc(sizeof(int) * size);
	for (i = 0; i < (int)size; i++)
	{
		res[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = res[i];

	free(count);
	free(res);

}
