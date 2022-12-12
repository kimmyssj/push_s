/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 01:24:32 by seungjki          #+#    #+#             */
/*   Updated: 2022/12/10 03:55:00 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_message(int flag)
{
	if (flag == arg_not_valid)
		write(2, "Error\nArgument which is not valid", 33);
	else if (flag == int_not_exist)
		write(2, "There's no valid int", 20);
	else if (flag == malloc_fail)
		write(2, "Error\nFailed to make list", 26);
	else if (flag == arg_underflow)
		write(2, "Error\nArgument underflow", 24);
	else if (flag == arg_overflow)
		write(2, "Error\nArgument overflow", 23);
	else if (flag == arg_dup)
		write(2, "Error\nArguments are duplicated", 30);
	else if (flag == malloc_fail)
		write(2, "Error\nmemory allocation failed", 30);
	exit(1);
}
