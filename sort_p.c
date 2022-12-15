#include "push_swap.h"

void	incase_tail_null(t_ht *ht_b, t_list *buff)
{
	ht_b->tail = buff;
	buff->next = NULL;
}

void	comm_pa(t_ht *ht_a, t_ht *ht_b)
{
	t_list	*buff;

	buff = ht_a->head;
	ht_a->head = ht_a->head->next;
	ht_a->head->before = NULL; // 이거 넣어줘야 하는데 줄 초과네. 알아서 잘 해봐ㅎ .
	if (ht_b->tail == NULL)
		incase_tail_null(ht_b, buff);
	else if (ht_b->head == ht_b->tail && ht_b->tail != NULL)
	{
		ht_b->tail->before = buff;
		buff->next = ht_b->tail;
		ht_b->head = buff;
		buff->before = NULL;
		write(1, "pa\n", 3);
		return ;
	}
	if (ht_a->head == NULL)
		ht_a->tail = NULL;
	if (ht_b->head != NULL)
		buff->next = ht_b->head;
	ht_b->head = buff;
	ht_b->head->before = buff;
	write(1, "pa\n", 3);
}

void	comm_pb(t_ht *ht_a, t_ht *ht_b)
{
	t_list	*buff;

	buff = ht_b->head;
	ht_b->head = ht_b->head->next;
	ht_a->head->before = NULL;
	if (ht_a->tail == NULL)
		incase_tail_null(ht_b, buff);
	else if (ht_a->head == ht_a->tail && ht_a->tail != NULL)
	{
		ht_a->tail->before = buff;
		buff->next = ht_a->tail;
		ht_a->head = buff;
		buff->before = NULL;
		write(1, "pb\n", 3);
		return ;
	}
	if (ht_b->head == NULL)
		ht_b->tail = NULL;
	buff->next = ht_a->head;
	ht_a->head = buff;
	ht_a->head->before = buff;
	write(1, "pb\n", 3);
}
