/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:00:35 by fleduc            #+#    #+#             */
/*   Updated: 2022/06/07 15:50:13 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h> //a supprimer

typedef struct s_intlist
{
	int					content;
	struct s_intlist	*next;
}				t_intlist;

int		main(int argc, char *argv[]);
void	fill_stack(t_intlist **stack_a, t_intlist **stack_b, int c, char **num);
void	redirect(int count, t_intlist **stack_a, t_intlist **stack_b);
void	clean(t_intlist **stack_a);
void	clean_str(char **str);

int		check_errors(char **splitted, int argc);
int		check_if_dup(char **args, int count);
int		check_if_int(char *arg);
int		check_if_number(char *arg);

void	small(int count, t_intlist **stack_a, t_intlist **stack_b);
void	big(int count, t_intlist **stack_a, t_intlist **stack_b);
void	three(t_intlist **stack_a);
void	four_to_nine(int count, t_intlist **a, t_intlist **b);
void	ten_to_infinite(int count, int chunk, t_intlist **a, t_intlist **b);
void	align_b(t_intlist **b, int sm);
int		minimum(t_intlist **stack);

int		find_index(t_intlist **a, int c);
int		list_len(t_intlist **stack);
int		ft_len(char **double_str);
int		check_order(t_intlist **stack_a);
int		get_min(t_intlist **stack, int chunk);
char	**rm_first(char **arg, int argc);
int		get_max(t_intlist **stack);
int		see_smaller(t_intlist **stack, int num);
void	rotate_stack_b(t_intlist **stack, int num);
void	rotate_stack_a(t_intlist **stack, int num);

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
