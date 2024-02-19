#include "sort.h"
/**
 * swap_nodes - function that swaps 2 nodes
 * @node1: node 1
 * @node2: node 2
*/
void swap_nodes(listint_t **node1, listint_t **node2)
{
	(*node1)->next = (*node2)->next;
	(*node2)->next = *node1;
	if ((*node1)->next != NULL)
		(*node1)->next->prev = *node1;
	(*node2)->prev = (*node1)->prev;
	(*node1)->prev = *node2;
	if ((*node2)->prev != NULL)
		(*node2)->prev->next = *node2;
}
/**
 * insertion_sort_list - function that sorts usuing the insertion sort method
 * @list: the doubly linked list to be sorted
*/
void insertion_sort_list(listint_t **list)
{
	int sorted_flag = 0, swaped;
	listint_t *copy = *list, /*prev_node_copy , *next_node_copy*/ *node1, *node2;

	if (*list == NULL || list == NULL)
		return;
	if ((*list) != NULL && (*list)->next == NULL)
		return;
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
				swap_nodes(&node1, &node2);
			}
			else
			{
				node1 = copy;
				node2 = copy->next;
				swap_nodes(&node1, &node2);
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
