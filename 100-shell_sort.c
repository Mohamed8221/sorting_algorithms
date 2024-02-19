#include "sort.h"

/**
* shell_sort - sorts an array of integers in ascending order
*              using the Shell sort algorithm
* @array: array to sort
* @size: size of the array
*/
void shell_sort(int *array, size_t size)
{
size_t gap = 1;
size_t i, j;
int temp;

/* Calculate gap using Knuth sequence */
while (gap < size / 3)
{
gap = gap * 3 + 1;
}

/* Start with the largest gap and work down to a gap of 1 */
while (gap > 0)
{
/* Do a gapped insertion sort for this gap size */
for (i = gap; i < size; i++)
{
/* Save array[i] in temp and make a hole at position i */
temp = array[i];

/* Shift earlier gap-sorted elements up until the correct location for array[i] is found */
for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
{
array[j] = array[j - gap];
}

/* Put temp (the original array[i]) in its correct location */
array[j] = temp;
}

/* Decrease gap */
gap /= 3;

/* Print the array each time you decrease the interval */
print_array(array, size);
}
}
