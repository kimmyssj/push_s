/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_coding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:11:37 by seungjki          #+#    #+#             */
/*   Updated: 2022/12/26 22:38:59 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	hard_coded_three(t_ht *hta)
{
	int	first;
	int	second;
	int	third;

	first = hta->head->idx;
	second = hta->head->next->idx;
	third = hta->head->next->next->idx;
	if (first == 0 && second == 2 && third == 1)
	{
		comm_rrx(hta, rra);
		comm_s(hta, sa);
	}
	else if (first == 1 && second == 2 && third == 0)
		comm_rrx(hta, rra);
	else if (first == 1 && second == 0 && third == 2)
		comm_s(hta, sa);
	else if (first == 2 && second == 0 && third == 1)
		comm_rx(hta, ra);
	else if (first == 2 && second == 1 && third == 0)
	{
		comm_s(hta, sa);
		comm_rrx(hta, rra);
	}
}

void	hard_coded_four(t_ht *hta, t_ht *htb)
{
	t_list	*find_four;
	int		idx;

	idx = 0;
	find_four = hta->head;
	while (find_four->idx != 3)
	{
		find_four = find_four->next;
		idx ++;
	}
	if (idx <= 1)
		while (hta->head->idx != 3)
			comm_rx(hta, ra);
	else
		while (hta->head->idx != 3)
			comm_rrx(hta, rra);
	comm_pb(hta, htb);
	hard_coded_three(hta);
	comm_pa(hta, htb);
	comm_rx(hta, ra);
}

void	hard_coded_five(t_ht *hta, t_ht *htb)
{
	int		idx;
	t_list	*temp;

	temp = hta->head;
	idx = 0;
	while (temp != NULL)
	{
		if (temp->idx == 4)
			break ;
		temp = temp->next;
		idx ++;
	}
	if (idx <= 2)
		while (hta->head->idx != 4)
			comm_rx(hta, ra);
	else
		while (hta->head->idx != 4)
			comm_rrx(hta, rra);
	comm_pb(hta, htb);
	hard_coded_four(hta, htb);
	comm_pa(hta, htb);
	comm_rx(hta, ra);
}
