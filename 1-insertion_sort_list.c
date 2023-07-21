#include <stdio.h>
#include "sort.h"
/**
  * insertion_sort_list - insertion sort
  *
  * @list: list passed doubly linked list
  */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *temp_node, *prev_node;

	if (list == NULL || *list == NULL)
		return;
	curr = (*list)->next;
	while (curr != NULL)
	{
		prev_node = curr->prev;
		while (prev_node != NULL && (curr->n < prev_node->n))
		{
			prev_node->next = curr->next;
			if (curr->next != NULL)
				curr->next->prev = prev_node;
			temp_node = prev_node->prev;
			prev_node->prev = curr;
			curr->next = prev_node;
			curr->prev = temp_node;
			if (*list == prev_node)
				*list = curr;
			print_list(*list);
			prev_node = curr->prev;
		}
		curr = curr->next;
	}
}
