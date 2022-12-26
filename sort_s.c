/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 02:42:48 by seungjki          #+#    #+#             */
/*   Updated: 2022/12/20 01:45:11 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	comm_s(t_ht *ht, int flag)
{
	int		content;
	int		idx;
	t_list	*temp;
	t_list	*new;

	content = ht->head->content;
	idx = ht->head->idx;
	temp = ht->head->next;
	free(ht->head);
	ht->head = temp;
	new = malloc(sizeof(t_list));
	if (new == NULL)
		error_message(malloc_fail);
	new->content = content;
	new->idx = idx;
	new->next = temp->next;
	if (temp->next != NULL)
		temp->next->before = new;
	temp->next = new;
	new->before = temp;
	temp->before = NULL;
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
