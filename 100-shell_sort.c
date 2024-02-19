#include "sort.h"

/**
* swap - Swaps the positions of two elements in an array
* @array: The array
* @item1: Index of the first item
* @item2: Index of the second item
*/
void swap(int *array, ssize_t h, ssize_t l)
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

/* Shift elements to make room for the current element */
for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
{
swap(array, j, j - interval);
}
}

/* Reduce the interval for the next iteration of the Shell sort */
interval /= 3;

/* Print the array after each interval reduction */
print_array(array, size);
}
}
