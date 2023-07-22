#include <stdio.h>
#include "sort.h"
/**
  * swap - to make the swap
  *
  * @list: list passed doubly linked list
  * @prev_node: previous node
  * @curr: current node
  */
void swap(listint_t **list, listint_t *prev_node, listint_t *curr)
{
	prev_node->next = curr->next;
	if (curr->next != NULL)
		curr->next->prev = prev_node;
	curr->prev = prev_node->prev;
	prev_node->prev = curr;
	curr->next = prev_node;
	if (prev_node == *list)
		*list = curr;
	print_list(*list);
}
/**
  * insertion_sort_list - insertion sort
  *
  * @list: list passed doubly linked list
  */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *prev_node;

	if (list == NULL || *list == NULL)
		return;

	curr = (*list)->next;
	while (curr != NULL)
	{
		prev_node = curr->prev;
		while (prev_node != NULL && (curr->n < prev_node->n))
		{
			swap(list, prev_node, curr);
			prev_node = curr->prev;
		}
		curr = curr->next;
	}
}
