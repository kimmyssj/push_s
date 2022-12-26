/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 21:02:28 by seungjki          #+#    #+#             */
/*   Updated: 2022/12/26 18:22:15 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	above_five_hund(t_ht *hta, t_ht *htb, int num)
{
	int	idx;
	int	idx1;
	int	flag;

	idx = 0;
	idx1 = 1;
	while (idx1 != 17)
	{
		while (1)
		{
			flag = check_up_down0(hta->head, hta->tail,
					num * idx / 16, num * idx1 / 16);
			if (flag == rra)
				search_and_rra_pb(hta, htb, num * idx / 16, num * idx1 / 16);
			else if (flag == ra)
				search_and_ra_pb(hta, htb, num * idx / 16, num * idx1 / 16);
			else
				break ;
		}
		idx ++;
		idx1 ++;
	}
}

void	above_hund(t_ht *hta, t_ht *htb, int num)
{
	int	idx;
	int	idx1;
	int	flag;

	idx = 0;
	idx1 = 1;
	while (idx1 != 9)
	{
		while (1)
		{
			flag = check_up_down0(hta->head,
					hta->tail, num * idx / 8, num * idx1 / 8);
			if (flag == rra)
				search_and_rra_pb(hta, htb, num * idx / 8, num * idx1 / 8);
			else if (flag == ra)
				search_and_ra_pb(hta, htb, num * idx / 8, num * idx1 / 8);
			else
				break ;
		}
		idx ++;
		idx1 ++;
	}
}

int	sort_all(t_ht *hta, t_ht *htb, int num)
{
	if (num >= 500)
	{
		above_five_hund(hta, htb, num);
		find_least_push(hta, htb, num);
	}
	else if (num > 5 && num < 500)
	{
		above_hund(hta, htb, num);
		find_least_push(hta, htb, num);
	}
	else if (num == 5)
		hard_coded_five(hta, htb);
	else if (num == 4)
		hard_coded_four(hta, htb);
	else if (num == 3)
		hard_coded_three(hta);
	else if (num == 2)
		comm_s(hta, sa);
	return (0);
}
