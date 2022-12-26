/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 05:39:37 by seungjki          #+#    #+#             */
/*   Updated: 2022/12/22 16:41:05 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	comm_pb(t_ht *ht_a, t_ht *ht_b)
{
	t_list	*buff;

	buff = ht_a->head->next;
	ht_a->head->next = ht_b->head;
	if (ht_b->head != NULL)
		ht_b->head->before = ht_a->head;
	ht_b->head = ht_a->head;
	ht_b->head->before = NULL;
	if (ht_b->head->next == NULL)
		ht_b->tail = ht_b->head;
	if (buff == NULL)
	{
		ht_a->head = NULL;
		ht_a->tail = NULL;
	}
	else
		ht_a->head = buff;
	write(1, "pb\n", 3);
}

void	comm_pa(t_ht *ht_a, t_ht *ht_b)
{
	t_list	*buff;

	buff = ht_b->head->next;
	ht_b->head->next = ht_a->head;
	if (ht_a->head != NULL)
		ht_a->head->before = ht_b->head;
	ht_a->head = ht_b->head;
	ht_a->head->before = NULL;
	if (ht_a->head->next == NULL)
		ht_a->tail = ht_a->head;
	if (buff == NULL)
	{
		ht_b->head = NULL;
		ht_b->tail = NULL;
	}
	else
		ht_b->head = buff;
	write(1, "pa\n", 3);
}
