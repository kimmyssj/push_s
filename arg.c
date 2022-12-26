/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 01:39:16 by seungjki          #+#    #+#             */
/*   Updated: 2022/12/26 17:19:47 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_the_argument(char *str)
{
	int	idx;
	int	flag;

	idx = -1;
	flag = 0;
	if (str[0] == '\0')
		error_message(arg_not_valid);
	while (str[++idx])
	{
		if ((str[idx] < '0' || str[idx] > '9')
			&& (str[idx] != ' ' && str[idx] != '-'))
			error_message(arg_not_valid);
		if ((str[idx] == '-' && str[idx + 1] < '0')
			|| (str[idx] == '-' && str[idx + 1] > '9'))
			error_message(arg_not_valid);
		if (flag == 0)
			if (str[idx] >= '0' && str[idx] <= '9')
				flag = 1;
	}
	if (flag == 0)
		error_message(arg_not_valid);
}

t_list	*ft_lstnew(char *argv, int idx1, t_ht *ht)
{
	t_list	*answer;

	answer = malloc(sizeof(t_list));
	if (!answer)
		error_message(malloc_fail);
	answer->content = ft_atoi(argv + idx1);
	answer->flag = 0;
	answer->pivot = 0;
	if (ht->head == NULL && ht->tail == NULL)
	{
		answer->before = NULL;
		answer->next = NULL;
		ht->head = answer;
		ht->tail = answer;
	}
	else
	{
		ht->tail->next = answer;
		answer->before = ht->tail;
		answer->next = NULL;
		ht->tail = answer;
	}
	return (answer);
}

int	list_int(char *av[], int argc, t_ht *ht)
{
	t_idx	a;

	a.idx = 0;
	a.check = 0;
	while (++ a.idx < argc)
	{
		a.idx1 = -1;
		a.flag = 1;
		while (av[a.idx][++a.idx1])
		{
			if (a.flag == 1 && ((av[a.idx][a.idx1] <= '9'
					&& av[a.idx][a.idx1] >= '0') || av[a.idx][a.idx1] == '-'))
			{
				if (ft_lstnew(av[a.idx], a.idx1, ht) == 0)
					error_message(malloc_fail);
				a.flag = 0;
				a.check ++;
			}
			else if (a.flag == 0 && (av[a.idx][a.idx1] < '0'
				|| av[a.idx][a.idx1] > '9'))
				a.flag = 1;
		}
	}
	return (a.check);
}

void	check_dup(t_list *hd)
{
	t_list	*current;

	while (hd->next != NULL)
	{
		current = hd->next;
		while (current != NULL)
		{
			if (hd->content == current->content)
				error_message(arg_dup);
			current = current->next;
		}
		hd = hd->next;
	}
}

int	check_arg(int argc, char **argv, t_ht *ht)
{
	int		idx;
	t_list	*lst;

	if (argc == 1)
		exit(0);
	idx = 0;
	while (++idx < argc)
		check_the_argument(argv[idx]);
	if (idx == 0)
		error_message(2);
	ht->head = NULL;
	ht->tail = NULL;
	if (list_int(argv, argc, ht) == 0)
		error_message(3);
	check_dup(ht->head);
	lst = ht->head;
	idx = 0;
	while (lst != NULL)
	{
		idx ++;
		lst = lst->next;
	}
	return (idx);
}
