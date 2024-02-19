#include "sort.h"

/**
* parti_tion - partitions array
* @array: array to sort
* @l: starting index
* @h: ending index
* @size: size of the array
* Return: index for the pivot
*/
int par(int *array, int l, int h, size_t size)
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
* @l: starting index
* @h: ending index
* @size: size of the array
*/
void quick_sort_helper(int *array, int l, int h, size_t size)
{
if (l < h)
{
int pi = par(array, l, h, size);

quick_sort_helper(array, l, pi - 1, size);
quick_sort_helper(array, pi + 1, h, size);
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
