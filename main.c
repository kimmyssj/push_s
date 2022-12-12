/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 01:39:16 by seungjki          #+#    #+#             */
/*   Updated: 2022/12/13 03:32:35 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> // 나중에 지워

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

int	main(int argc, char *argv[])
{
	t_ht	*hta;
	t_ht	*htb;
	int		num;

	hta = malloc(sizeof(t_ht)); // malloc을 안하고 ->로 list *에 접근시 박살남. 이유가..?
	htb = malloc(sizeof(t_ht));
	hta->head = NULL;
	hta->tail = NULL;
	if (hta == NULL || htb == NULL)
		error_message(malloc_fail);
	num = check_arg(argc, argv, hta);
	htb->head = NULL;
	htb->head = NULL;
	indexing(hta, num - 1);
	current_check(hta->head, htb->head, num);
	// 인덱싱(전처리)
	// 정렬 코드 한 줄 (내부에 명령어 모듈이 들어있어야 함)
	// 스택 현재 진행상황 체크 한 줄
}
