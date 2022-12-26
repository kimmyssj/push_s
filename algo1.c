/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:18:24 by seungjki          #+#    #+#             */
/*   Updated: 2022/12/26 17:23:13 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_up(t_list *head, int min, int max)
{
	int	answer;

	answer = 0;
	while (head != NULL)
	{
		if (head->idx >= min && head->idx <= max)
			return (answer);
		head = head->next;
		answer ++;
	}
	return (-1);
}

int	check_down(t_list *tail, int min, int max)
{
	int	answer;

	answer = 0;
	while (tail != NULL)
	{
		if (tail->idx >= min && tail->idx <= max)
			return (answer);
		tail = tail->before;
		answer ++;
	}
	return (-1);
}

int	check_up_down0(t_list *head, t_list *tail, int min, int max)
{
	int	top;
	int	bottom;

	top = check_up(head, min, max);
	bottom = check_down(tail, min, max);
	if (top == -1 || bottom == -1)
		return (none);
	if (top < bottom)
		return (ra);
	else if (top >= bottom)
		return (rra);
	return (0);
}

void	search_and_rra_pb(t_ht *hta, t_ht *htb, int min, int max)
{
	while (1)
	{
		if (hta->head->idx >= min && hta->head->idx <= max)
		{
			comm_pb(hta, htb);
			return ;
		}
		comm_rrx(hta, rra);
	}
}

void	search_and_ra_pb(t_ht *hta, t_ht *htb, int min, int max)
{
	while (1)
	{
		if (hta->head->idx >= min && hta->head->idx <= max)
		{
			comm_pb(hta, htb);
			return ;
		}
		comm_rx(hta, ra);
	}
}
