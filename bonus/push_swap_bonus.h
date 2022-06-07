/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:00:35 by fleduc            #+#    #+#             */
/*   Updated: 2022/06/07 11:37:04 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_intlist
{
	int					content;
	struct s_intlist	*next;
}				t_intlist;

int		main(int argc, char *argv[]);
void	fill_stack(t_intlist **stack_a, t_intlist **stack_b, int c, char **num);
void	check(int count, t_intlist **stack_a, t_intlist **stack_b);
void	clean(t_intlist **stack_a, t_intlist **stack_b);
void	clean_str(char **str);
char	**rm_first(char **arg, int argc);

int		check_errors(char **splitted, int argc);
int		check_if_dup(char **args, int count);
int		check_if_int(char *arg);
int		check_if_number(char *arg);

int		ft_len(char **double_str);
int		check_order(t_intlist **stack_a);
int		do_op(char *line, t_intlist **a, t_intlist **b);
void	print_checker(t_intlist **a, t_intlist **b);

int		swap_a(t_intlist **stack);
int		swap_b(t_intlist **stack);
int		swap_ab(t_intlist **stack_a, t_intlist **stack_b);
int		rotate_a(t_intlist **stack);
int		rotate_b(t_intlist **stack);
int		rotate_ab(t_intlist **stack_a, t_intlist **stack_b);
int		reverse_rotate_a(t_intlist **stack);
int		reverse_rotate_b(t_intlist **stack);
int		reverse_rotate_ab(t_intlist **stack_a, t_intlist **stack_b);
int		push_a(t_intlist **stack_a, t_intlist **stack_b);
int		push_b(t_intlist **stack_a, t_intlist **stack_b);

#endif
