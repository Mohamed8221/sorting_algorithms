#include "sort.h"

/**
* heapify - Transforms array into a heap
* @array: The array to be sorted
* @size: Size of the heap
* @i: Root index
* @total_size: Size of the array
*/
void heapify(int *array, size_t size, int i, size_t total_size)
{
int largest = i, tmp;
int left = 2 * i + 1;
int right = 2 * i + 2;

if (left < (int)size && array[left] > array[largest])
largest = left;

if (right < (int)size && array[right] > array[largest])
largest = right;

if (largest != i)
{
tmp = array[i];
array[i] = array[largest];
array[largest] = tmp;
print_array(array, total_size);
heapify(array, size, largest, total_size);
}
}

/**
* heap_sort - Sorts an array of integers in ascending order
*             using the Heap sort algorithm
* @array: The array to be sorted
* @size: Size of the array
*/
void heap_sort(int *array, size_t size)
{
int i, tmp;

if (!array || size < 2)
return;

for (i = size / 2 - 1; i >= 0; i--)
heapify(array, size, i, size);

for (i = size - 1; i >= 0; i--)
{
tmp = array[0];
array[0] = array[i];
array[i] = tmp;
if (i != 0)
print_array(array, size);
heapify(array, i, 0, size);
}
}
