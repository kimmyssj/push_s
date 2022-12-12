/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 02:42:48 by seungjki          #+#    #+#             */
/*   Updated: 2022/12/13 02:44:21 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	comm_s(t_list **head)
{
	t_list	*buff;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	buff = *head;
	*head = (*head)->next;
	buff->next = (*head)->next;
	(*head)->next = buff;
	buff->before = *head;
	(*head)->before = NULL;
}

void	comm_ss(t_list **head_a, t_list **head_b)
{
	comm_s(head_a);
	comm_s(head_b);
}
