#include "sort.h"
/**
 * swap_nodes - function to swap 2 nodes in a doubly linked list
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
 * cocktail_sort_list- function that sort a set of numbers by shaker sort alg
 * @list: the list to be sorted
*/
void cocktail_sort_list(listint_t **list)
{
	size_t sorted_flag = 0, swaped = 0;
	listint_t *node1, *node2, *list_copy_start = *list, *list_copy_end;

	if (*list == NULL || list == NULL || (*list)->next == NULL)
		return;
	
	while (sorted_flag != 1)
	{
		swaped = 0;

		while (list_copy_start->next != NULL) /* forward iteratoin */
		{
			if (list_copy_start->n > list_copy_start->next->n)
			{
				node1 = list_copy_start;
				node2 = list_copy_start->next;
				swap_nodes(&node1, &node2);
				list_copy_start = node2; /* it will be moved to next at end of the while loop , that's why it is not node1*/
				if (list_copy_start->prev == NULL)
					*list = node2;
				print_list(*list);
				swaped = 1;
			}
			list_copy_start = list_copy_start->next;
		}
		list_copy_end = *list; /*move to the last node of the list */
		while (list_copy_end->next != NULL)
			list_copy_end = list_copy_end->next; /* until it reaches last node */
		while (list_copy_end->prev != NULL) /* backward iteration */
		{
			if (list_copy_end->n < list_copy_end->prev->n)
			{
				node1 = list_copy_end->prev;
				node2 = list_copy_end;
				swap_nodes(&node1, &node2);
					list_copy_end = node1;
				if (list_copy_end->prev->prev == NULL)
					*list = node2;
				print_list(*list);
				swaped = 1;
			}
			list_copy_end = list_copy_end->prev;
		}
			if (swaped == 0)
				sorted_flag = 1;
	}
}
