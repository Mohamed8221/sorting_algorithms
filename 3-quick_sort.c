#include "sort.h"

/**
* partition - partitions array
* @array: array to sort
* @low: starting index
* @high: ending index
* @size: size of the array
* Return: index for the pivot
*/
int partition(int *array, int low, int high, size_t size)
{
int pivot = array[high];
int i = (low - 1);
int j, temp;

for (j = low; j <= high - 1; j++)
{
if (array[j] < pivot)
{
i++;
if (i != j)
{
temp = array[i];
array[i] = array[j];
array[j] = temp;
print_array(array, size);
}
}
}
if (array[i + 1] != array[high])
{
temp = array[i + 1];
array[i + 1] = array[high];
array[high] = temp;
print_array(array, size);
}
return (i + 1);
}

/**
* quick_sort_helper - helper function for quick_sort
* @array: array to sort
* @low: starting index
* @high: ending index
* @size: size of the array
*/
void quick_sort_helper(int *array, int low, int high, size_t size)
{
if (low < high)
{
int pi = partition(array, low, high, size);

quick_sort_helper(array, low, pi - 1, size);
quick_sort_helper(array, pi + 1, high, size);
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
