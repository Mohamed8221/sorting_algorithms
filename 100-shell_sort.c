#include "sort.h"
/**
* shell_sort - function that sorts usuing the shell sort
* @array: the array to be sorted
* @size: size of the array to be sorted
*/

void shell_sort(int *array, size_t size)
{
size_t i, sorted_flag = 0, swaped = 0, tmp = 0;

while (sorted_flag != 1)
{
swaped = 0;
for (i = 0; i < size - 1; i++)
{
if (array[i] > array[i + 1])
{
tmp = array[i];
array[i] = array [i + 1];
array[i + 1] = tmp;
swaped = 1;
print_array(array, size);
}
}

for (i = size - 1 ; i > 0 ; i--)
{
if (array[i] < array[i - 1])
{
tmp = array[i];
array[i] = array [i - 1];
array[i - 1] = tmp;
swaped = 1;
print_array(array, size);
}
}

if (swaped == 0)
sorted_flag = 1;
}


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
