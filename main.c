/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 01:39:16 by seungjki          #+#    #+#             */
/*   Updated: 2022/12/26 18:21:00 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_it_done(t_list *head)
{
	int	temp;

	while (head->next != NULL)
	{
		temp = head->content;
		head = head->next;
		if (head->content < temp)
			return (0);
	}
	return (1);
}

void	indexing(t_ht *ht, int num)
{
	t_var	v;

	while (num >= 0)
	{
		v.flag = 0;
		v.list = ht->head;
		while (v.list != NULL)
		{
			if (v.list->flag == 0 && v.flag == 0)
			{
				v.change = v.list;
				v.flag = 1;
			}
			else if (v.flag == 1 && v.list->content > v.change->content
				&& v.list->flag == 0)
				v.change = v.list;
			v.list = v.list->next;
		}
		v.change->flag = 1;
		v.change->idx = num;
		num --;
	}
}

void	free_all(t_ht **hta, t_ht **htb)
{
	t_list	*temp;
	t_list	*temp1;

	temp1 = (*hta)->head;
	free(*htb);
	while (temp1 != NULL)
	{
		temp = temp1;
		temp1 = temp1->next;
		free(temp);
	}
	free(*hta);
}

int	main(int argc, char *argv[])
{
	t_ht	*hta;
	t_ht	*htb;
	int		num;

	hta = malloc(sizeof(t_ht));
	htb = malloc(sizeof(t_ht));
	hta->head = NULL;
	hta->tail = NULL;
	if (hta == NULL || htb == NULL)
		error_message(malloc_fail);
	num = check_arg(argc, argv, hta);
	htb->head = NULL;
	htb->tail = NULL;
	if (is_it_done(hta->head) != 0)
		exit(1);
	indexing(hta, num - 1);
	sort_all(hta, htb, num);
	free_all(&hta, &htb);
}
