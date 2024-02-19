#include "sort.h"
/*
* insertion_sort_list - function that does the insertion sort method
* @list: the list to be sorted
*/


void insertion_sort_list(listint_t **list)
{
	int sorted_flag = 0, swaped;
	listint_t *copy = *list, /*prev_node_copy , *next_node_copy*/ *node1, *node2;

	if (*list == NULL || list == NULL)
	return;

	if ((*list) != NULL && (*list)->next == NULL)
	{
		/*print_list(*list);*/
		return;
	}
		
	while (sorted_flag != 1)
	{
		swaped = 0;
		copy = *list;
		while (copy != NULL && copy->next != NULL)
		{
			if (copy->n > copy->next->n)
			{
			if (copy->prev != NULL)
			{
				node1 = copy;
				node2 = copy->next;
				node1->next = node2->next;
				node2->next = node1;
				if (node1->next != NULL)
					node1->next->prev = node1;
				node2->prev = node1->prev;
				node1->prev = node2;
				if (node2->prev != NULL)
					node2->prev->next = node2;
			}
			else
			{
				node1 = copy;
				node2 = copy->next;
				node1->next = node2->next;
				node2->next = node1;
				if (node1->next != NULL)
					node1->next->prev = node1;
				node2->prev = node1->prev;
				node1->prev = node2;
				if (node2->prev != NULL)
					node2->prev->next = node2;
				*list = node2;
				copy = node2;
			}
			swaped = 1;
			print_list(*list);
			break;
			}
			copy = copy->next;
		}
		if (swaped == 0)
		sorted_flag = 1;
	}
}
