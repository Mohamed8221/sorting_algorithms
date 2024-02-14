#include "sort.h"
/**
 * 
*/


void insertion_sort_list(listint_t **list)
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
}
