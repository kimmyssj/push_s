/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 06:09:13 by seungjki          #+#    #+#             */
/*   Updated: 2022/12/26 18:20:37 by seungjki         ###   ########.fr       */
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

enum e_commands
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
	rrr,
	none
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
	int				content;
	int				idx;
	int				flag;
	int				pivot;
	struct s_list	*next;
	struct s_list	*before;
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

typedef struct s_nums
{
	int	num;
	int	num1;
}	t_nums;

typedef struct s_checks
{
	int	ra;
	int	rra;
	int	rb;
	int	rrb;
	int	rr;
	int	rrr;
	int	r_max;
	int	rr_max;
	int	total;
	int	idx;
}	t_checks;

typedef struct s_fst
{
	int	first;
	int	second;
	int	third;
}	t_fst;

int		ft_atoi(char *str);
int		check_arg(int argc, char **av, t_ht *ht);
int		is_it_done(t_list *head);
int		sort_all(t_ht *hta, t_ht *htb, int num);
int		is_it_sorted(t_ht *hta, t_ht *htb);
int		check_up(t_list *head, int min, int max);
int		check_down(t_list *tail, int min, int max);
int		check_up_down0(t_list *head, t_list *tail, int min, int max);
void	hard_coded_three(t_ht *hta);
void	hard_coded_four(t_ht *hta, t_ht *htb);
void	hard_coded_five(t_ht *hta, t_ht *htb);
void	above_hund1(t_ht *hta, t_ht *htb, int num);
void	find_least_push(t_ht *hta, t_ht *htb, int num);
void	error_message(int fd);
void	comm_s(t_ht *ht, int flag);
void	comm_ss(t_ht *hta, t_ht *htb);
void	comm_pa(t_ht *ht_a, t_ht *ht_b);
void	comm_pb(t_ht *ht_a, t_ht *ht_b);
void	comm_rx(t_ht *ht, int flag);
void	comm_rr(t_ht *hta, t_ht *htb);
void	comm_rrx(t_ht *ht, int flag);
void	comm_rrr(t_ht *hta, t_ht *htb);
void	search_and_rra_pb(t_ht *hta, t_ht *htb, int min, int max);
void	search_and_ra_pb(t_ht *hta, t_ht *htb, int min, int max);

#endif
