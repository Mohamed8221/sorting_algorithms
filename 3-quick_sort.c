#include "sort.h"

/**
* partition_array_qs - partitions array
* @array: array to sort
* @l: starting index
* @h: ending index
* @size: size of the array
* Return: index for the pivot
*/
int partition_array_qs(int *array, int l, int h, size_t size)
{
int pivot = array[h];
int i = (l - 1);
int j, tmp;

for (j = l; j <= h - 1; j++)
{
if (array[j] < pivot)
{
i++;
if (i != j)
{
tmp = array[i];
array[i] = array[j];
array[j] = tmp;
print_array(array, size);
}
}
}
if (array[i + 1] != array[h])
{
tmp = array[i + 1];
array[i + 1] = array[h];
array[h] = tmp;
print_array(array, size);
}
return (i + 1);
}

/**
* quick_sort_helper - helper function for quick_sort
* @array: array to sort
* @start: starting index
* @end: ending index
* @size: size of the array
*/
void quick_sort_helper(int *array, int start, int end, size_t size)
{
if (start < end)
{
int partitioned = partition_array_qs(array, start, end, size);

quick_sort_helper(array, start, partitioned - 1, size);
quick_sort_helper(array, partitioned + 1, end, size);
}
}

/**
* quick_sort - sorts an array of integers in ascending order
* @array: array to sort
* @size: size of the array
*/
void quick_sort(int *array, size_t size)
{
if (!array || size < 2)
return;

quick_sort_helper(array, 0, size - 1, size);
}
