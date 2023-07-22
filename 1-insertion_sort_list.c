#include <stdio.h>
#include "sort.h"
/**
  * swap - to make the swap
  *
  * @list: list passed doubly linked list
  * @curr: current node
  * Return: current
  */
listint_t *swap(listint_t **list, listint_t *curr)
{
	listint_t *prev_node = curr->prev;

	prev_node = curr->prev;
	prev_node->next = curr->next;
	if (curr->next != NULL)
		curr->next->prev = prev_node;
	curr->prev = prev_node->prev;
	prev_node->prev = curr;
	curr->next = prev_node;
	if (curr->prev == NULL)
		*list = curr;
	return (curr);
}
/**
  * insertion_sort_list - insertion sort
  *
  * @list: list passed doubly linked list
  */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr = (*list)->next;
	while (curr != NULL)
	{
		while (curr->prev != NULL && (curr->n < curr->prev->n))
		{
			curr = swap(list, curr);
			print_list(*list);
		}
		curr = curr->next;
	}
}
