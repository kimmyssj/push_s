#include "push_swap.h"

void	comm_pa(t_ht *ht_a, t_ht *ht_b)
{
	t_list	*buff;

	buff = ht_a->head;
	if (ht_a->head != NULL)
	{
		ht_a->head->before = NULL;
		ht_a->head = ht_a->head->next;
	}
	buff->next = ht_b->head;
	ht_b->head = buff;
	buff->before = NULL;
	if (ht_b->tail == NULL)
		ht_b->tail = buff;
}

void	comm_pb(t_ht *ht_a, t_ht *ht_b)
{
	t_list	*buff;

	buff = ht_b->head;
	if (ht_b->head != NULL)
	{
		ht_b->head->before = NULL;
		ht_b->head = ht_b->head->next;
	}
	buff->next = ht_a->head;
	ht_a->head = buff;
	buff->before = NULL;
	if (ht_a->tail == NULL)
		ht_a->tail = buff;
}
