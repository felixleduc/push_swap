/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:00:35 by fleduc            #+#    #+#             */
/*   Updated: 2022/05/25 00:20:17 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h> //enlever avant remise

typedef struct s_intlist
{
	int					content;
	struct s_intlist	*next;
}				t_intlist;

int		main(int argc, char *argv[]);
void	fill_stack(t_intlist **stack_a, t_intlist **stack_b, int c, char **num);
void	redirect(int count, t_intlist **stack_a, t_intlist **stack_b);
void	clean(t_intlist **stack_a);

int		check_errors(char **splitted, int argc, int mp_strs);
int		check_if_dup(char **args, int count, int mp_strs);
int		check_if_int(char *arg);
int		check_if_number(char *arg);

void	small(int count, t_intlist **stack_a, t_intlist **stack_b);
void	big(int count, t_intlist **stack_a, t_intlist **stack_b);
void	three(t_intlist **stack_a);
void	four_to_nine(int count, t_intlist **a, t_intlist **b);
void	ten_to_infinite(int count, t_intlist **a, t_intlist **b);
void	radix_sort(int size, t_intlist **a, t_intlist **b);
void	count_sort(t_intlist **a, int size, int place);
//void	a_pusher(int count, t_intlist **a, t_intlist **b);
//void	b_pusher(int count, t_intlist **a, t_intlist **b);

int		find_index(t_intlist **a, int c);
int		list_len(t_intlist **stack);
int		ft_len(char **double_str);
int		check_order(t_intlist **stack_a);
void	new_node(t_intlist **stack);

void	swap_a(t_intlist **stack);
void	swap_b(t_intlist **stack);
void	swap_ab(t_intlist **stack_a, t_intlist **stack_b);
void	rotate_a(t_intlist **stack);
void	rotate_b(t_intlist **stack);
void	rotate_ab(t_intlist **stack_a, t_intlist **stack_b);
void	reverse_rotate_a(t_intlist **stack);
void	reverse_rotate_b(t_intlist **stack);
void	reverse_rotate_ab(t_intlist **stack_a, t_intlist **stack_b);
void	push_a(t_intlist **stack_a, t_intlist **stack_b);
void	push_b(t_intlist **stack_a, t_intlist **stack_b);

#endif
