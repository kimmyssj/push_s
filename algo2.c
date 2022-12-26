/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:18:37 by seungjki          #+#    #+#             */
/*   Updated: 2022/12/26 17:18:38 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_biggest_idx_loca(t_ht *htb, int num)
{
	t_list	*temp;
	int		idx;

	temp = htb->head;
	idx = 0;
	while (temp->idx != num)
	{
		temp = temp->next;
		idx ++;
	}
	return (idx);
}

int	choose_which_one(int idx, int num)
{
	num = num / 2;
	if (idx < num)
		return (rb);
	else
		return (rrb);
}

void	rb_or_rrb(t_ht *htb, int flag, int num)
{
	if (flag == rb)
		while (htb->head->idx != num)
			comm_rx(htb, rb);
	else
		while (htb->head->idx != num)
			comm_rrx(htb, rrb);
}

void	find_least_push(t_ht *hta, t_ht *htb, int num)
{
	int	idx;

	while (num > 0)
	{
		num --;
		idx = find_biggest_idx_loca(htb, num);
		rb_or_rrb(htb, choose_which_one(idx, num), num);
		comm_pa(hta, htb);
	}
}
