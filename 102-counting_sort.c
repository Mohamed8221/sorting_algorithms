#include "sort.h"

/**
* counting_sort - Sorts an array
* @array: The array of integers to be sorted.
* @size: The size of the array.
*/

void counting_sort(int *array, size_t size)
{
int i, *output, max = 0, *count;

if (array == NULL || size == 0)
return;

/* Find the maximum value in the array */
for (i = 0; i < (int)size; i++)
if (array[i] > max)
max = array[i];

/* Initialize count array with zeros */
count = malloc(sizeof(int) * (max + 1));
for (i = 0; i <= max; i++)
count[i] = 0;

/* Count occurrence of each number in the array */
for (i = 0; i < (int)size; i++)
count[array[i]]++;

/* Transform count array into prefix sum array */
for (i = 1; i <= max; i++)
count[i] += count[i - 1];

print_array(count, max + 1);

/* Replace elements in original array according to the count array */
output = malloc(sizeof(int) * size);
for (i = 0; i < (int)size; i++)
{
output[count[array[i]] - 1] = array[i];
count[array[i]]--;
}
/* Copy the output array to sorted array */
for (i = 0; i < (int)size; i++)
array[i] = output[i];

free(count);
free(output);

}
