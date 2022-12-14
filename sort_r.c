/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:06:23 by seungjki          #+#    #+#             */
/*   Updated: 2022/12/15 14:48:34 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	comm_rx(t_ht *ht, int flag)
{
	ht->head->before = ht->tail;
	ht->tail->next = ht->head;
	ht->head = ht->head->next;
	ht->tail = ht->tail->next;
	ht->head->before = NULL;
	ht->tail->next = NULL;
	if (flag == ra)
		write(1, "ra\n", 3);
	else if (flag == rb)
		write(1, "rb\n", 3);
}

void	comm_rr(t_ht *hta, t_ht *htb)
{
	comm_rx(hta, rr);
	comm_rx(htb, rr);
	write (1, "rr\n", 3);
}
