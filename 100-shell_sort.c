#include "sort.h"

/**
* shell_sort - Sorts an array of integers
* @array: The array to be sorted
* @size: The size of the array
*/
void shell_sort(int *array, size_t size)
{
int temp;
size_t i, j, interval = 1;

/* Compute initial interval (gap) */
while (interval < size / 3)
{
interval = interval * 3 + 1;
}

/* Perform the Shell sort */
while (interval > 0)
{
for (i = interval; i < size; i++)
{
/* Extract the element to be inserted */
temp = array[i];

/* Shift elements to make room */
for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
{
array[j] = array[j - interval];
}

/* Insert the current element into the correct position */
array[j] = temp;
}

/* Reduce the interval for the next iteration of the Shell sort */
interval /= 3;

/* Print the array after each interval reduction */
print_array(array, size);
}
}
