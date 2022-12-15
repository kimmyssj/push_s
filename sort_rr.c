/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:23:18 by seungjki          #+#    #+#             */
/*   Updated: 2022/12/15 14:50:42 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	comm_rrx(t_ht *ht, int flag)
{
	ht->tail->next = ht->head;
	ht->head->before = ht->tail;
	ht->tail = ht->tail->before;
	ht->head = ht->head->before;
	ht->tail->next = NULL;
	ht->head->before = NULL;
	if (flag == rra)
		write(1, "rra\n", 4);
	else if (flag == rrb)
		write(1, "rrb\n", 4);
}

void	comm_rrr(t_ht *hta, t_ht *htb)
{
	comm_rrx(hta, rrr);
	comm_rrx(htb, rrr);
	write(1, "rrr\n", 4);
}
