#include "sort.h"
/**
* selection_sort - s
* @array: array to be sorted
* @size: size of array to be sorted
*/


void selection_sort(int *array, size_t size)
{
int smallest, tmp, swaped;
size_t i, j, index_of_smallest;

for (i = 0; i < size; i++)
{
smallest = array[i];
swaped = 0;
for (j = i + 1 ; j < size; j++)
{
if (smallest > array[j])
{
smallest = array[j];
index_of_smallest = j;
swaped = 1;
}

}

if (swaped == 1)
{
tmp = array[i];
array[i] = array[index_of_smallest];
array[index_of_smallest] = tmp;
print_array(array, size);
}
if (swaped == 0 && i == size - 2)
break;
}
}
