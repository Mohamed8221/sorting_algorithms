#include "sort.h"
/**
 * bubble_sort - bubble sort function
 * @array: the array to be sorted
 * @size: the size of the array to be sorted
*/


void bubble_sort(int *array, size_t size)
{
	int *num = array, *next_num = array + 1, swaped, sorted_flag = 0;
	size_t checks_num = size - 1, i;
	int tmp;

	if (array == NULL || size == 0)
		return;

	while (sorted_flag != 1)
	{
		swaped = 0;
		for (i = 0; i < checks_num; i++)
		{
			if (*(num + i) > *(next_num + i))
			{
				/* swap */
				tmp = *(num + i);
				*(num + i) = *(next_num + i);
				*(next_num + i) = tmp;

				swaped = 1;
				print_array(array, size);
			}
		}
		if (swaped == 0)
			sorted_flag = 1;
	}
=======
* bubble_sort - sorts an array of integers in ascending order
* using the Bubble sort algorithm
* @array: array to sort
* @size: size of the array
*/
void bubble_sort(int *array, size_t size)
{
size_t i, j;
int temp;

if (array == NULL || size < 2)
return;

for (i = 0; i < size - 1; i++)
{
for (j = 0; j < size - i - 1; j++)
{
if (array[j] > array[j + 1])
{
temp = array[j];
array[j] = array[j + 1];
array[j + 1] = temp;
print_array(array, size);
}
}
}
>>>>>>> 506b766 (update)
}
