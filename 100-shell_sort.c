#include "sort.h"

/**
* swap_shell - Swaps the positions of two elements in an array
* @array: The array
* @h: Index of the first item
* @l: Index of the second item
*/
void swap_shell(int *array, int h, int l)
{
int temp;

temp = array[h];
array[h] = array[l];
array[l] = temp;
}

/**
* shell_sort - Sorts an array of integers in ascending order
*              using the Shell sort algorithm
* @array: The array to be sorted
* @size: The size of the array
*/
void shell_sort(int *array, size_t size)
{
int temp;
size_t i, j, interval = 1;

if (array == NULL || size < 2)
return;

while (interval < size / 3)
{
interval = interval * 3 + 1;
}

while (interval > 0)
{
for (i = interval; i < size; i++)
{
temp = array[i];

for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
{
swap_shell(array, j, j - interval);
}
}
interval /= 3;
print_array(array, size);
}
}
