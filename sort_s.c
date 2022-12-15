/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 02:42:48 by seungjki          #+#    #+#             */
/*   Updated: 2022/12/14 13:41:06 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	comm_s(t_ht *ht, int flag)
{
	t_list	*buff;

	buff = ht->head;
	if (ht->head->next == ht->tail)
		ht->tail = buff;
	ht->head = ht->head->next;
	buff->next = ht->head->next;
	ht->head->next = buff;
	buff->before = ht->head;
	ht->head->before = NULL;
	if (flag == sa)
		write(1, "sa\n", 3);
	else if (flag == sb)
		write(1, "sb\n", 3);
}

void	comm_ss(t_ht *hta, t_ht *htb)
{
	comm_s(hta, ss);
	comm_s(htb, ss);
	write(1, "ss\n", 3);
}
