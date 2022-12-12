/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 06:09:13 by seungjki          #+#    #+#             */
/*   Updated: 2022/12/13 03:09:27 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

enum e_error_message
{
	arg_is_1,
	arg_not_valid,
	int_not_exist,
	malloc_fail,
	arg_underflow,
	arg_overflow,
	arg_dup
};

enum commands
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
};

typedef struct s_gnl
{
	char	*str;
	char	buff[BUFFER_SIZE + 1];
	int		endl;
	int		size;
	char	*ret;
}	t_gnl;

typedef struct s_list
{
	int		content;
	int		idx;
	int		flag;
	void	*next;
	void	*before;
}	t_list;

typedef struct s_idx
{
	int	idx;
	int	idx1;
	int	check;
	int	flag;
}	t_idx;

typedef struct s_ht
{
	t_list	*head;
	t_list	*tail;
}	t_ht;

typedef struct s_var
{
	t_list	*list;
	t_list	*change;
	int		flag;
}	t_var;

int		ft_atoi(char *str);
int		check_arg(int argc, char **av, t_ht *ht);
void	error_message(int fd);
void	current_check(t_list *heada, t_list *headb, int num); // 나중에 지워
void	comm_s(t_list **head);
void	comm_ss(t_list **head_a, t_list **head_b);
void	comm_pa(t_ht *ht_a, t_ht *ht_b);
void	comm_pb(t_ht *ht_a, t_ht *ht_b);

#endif
