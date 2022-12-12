/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 02:03:24 by seungjki          #+#    #+#             */
/*   Updated: 2022/12/10 04:39:14 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	result_maker(const char *str)
{
	long long	result;
	long long	flag;
	int			idx1;

	result = 0;
	flag = 0;
	idx1 = 0;
	if (str[idx1] == '-')
	{
		idx1 ++;
		flag = 1;
	}
	while (str[idx1] && str[idx1] >= '0' && str[idx1] <= '9')
	{
		result = result * 10;
		result = result + str[idx1] - '0';
		idx1++;
	}
	if (flag == 1)
		result = result * -1;
	return (result);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	idx;

	idx = 0;
	if (n == 0)
		return (0);
	while (s1[idx] && s1[idx] == s2[idx] && idx < n)
		idx ++;
	if (idx == n)
		return (0);
	return ((unsigned char)s1[idx] - (unsigned char)s2[idx]);
}

void	check_under_over(char *str)
{
	int	idx;

	idx = 0;
	if (str[idx] == '-')
	{
		idx ++;
		while (str[idx] >= '0' && str[idx] <= '9')
			idx ++;
		if (idx == 11)
			if (ft_strncmp("-2147483648", str, 11) > 0)
				error_message(arg_underflow);
		if (idx > 11)
			error_message(arg_underflow);
	}
	else
	{
		while (str[idx] >= '0' && str[idx] <= '9')
			idx ++;
		if (idx == 10)
			if (ft_strncmp("2147483647", str, 10) > 0)
				error_message(arg_overflow);
		if (idx > 10)
			error_message(arg_overflow);
	}
}

int	ft_atoi(char *str)
{
	int	result;

	check_under_over(str);
	result = result_maker(str);
	return (result);
}
