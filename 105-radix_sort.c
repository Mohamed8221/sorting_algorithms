#include "sort.h"
/**
 * count_digits - function to count the number of digits of the
 * bugest number in the array
 * @num: the larest number in the array
 * Return: the number of the digits in the max num in array
*/
int count_digits(int num)
{
	int count = 0;

	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}
/**
 * radix_counting_sort - counting sort function to match the radix sorting
 * @array: the array to be sorted
 * @size: the size of the array to be sorted
 * @exp: the power
*/

void radix_counting_sort(int *array, size_t size, int exp)
{
	int count[10] = {0};
	size_t i;
	int *output = malloc(sizeof(int) * size);

	if (output == NULL)
		return;

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i < size; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}
/**
 * copy_array - function that would copy an array
 * @array: the array to bbe copied
 * @size: the size of the array to bbe copied
 * Return: a pointer to the copy array
*/
int *copy_array(int *array, size_t size)
{
	int *array_copy;
	size_t i;

	array_copy = malloc((sizeof(int) * size));
	if (array_copy == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		array_copy[i] = array[i];
	}

	return (array_copy);
}
/**
 * radix_sort - the function that sorts using the radix sorting method
 * @array: the array to be sorted
 * @size: the size of the array to be sorted
*/
void radix_sort(int *array, size_t size)
{
	size_t i, no_of_digits = 0, j;
	int *array_copy, *remainder_array, power = 1, max;

	if (size < 2 || array == NULL)
		return;
	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	no_of_digits = count_digits(max);
	array_copy = copy_array(array, size);
	if (array_copy == NULL)
		return;
	remainder_array = malloc(sizeof(int) * size);
	if (remainder_array == NULL)
	{
		free(array_copy);
		return;
	}
	for (j = 0; j < no_of_digits; j++)
	{
		radix_counting_sort(array, size, power);
		print_array(array, size);
		power *= 10;
	}
	free(remainder_array);
	free(array_copy);
}
