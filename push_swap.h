/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <marvin@42quebec.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:00:35 by fleduc            #+#    #+#             */
/*   Updated: 2022/05/18 11:51:22 by fleduc           ###   ########.fr       */
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
int		check_errors(char **splitted, int argc, int mp_strs);
int		check_if_dup(char **args, int count, int mp_strs);
int		check_if_int(char *arg);
int		check_if_number(char *arg);

void    new_node(t_intlist **stack);
void    fill_stack(t_intlist **stack_a, t_intlist **stack_b, int c, char **num);
void    small(int count, t_intlist **stack_a, t_intlist **stack_b);
void    redirect(int count, t_intlist **stack_a, t_intlist **stack_b);
int     check_order(t_intlist **stack_a);

void    three(t_intlist **stack_a);
void    four_five(int count, t_intlist **a, t_intlist **b);

int     find_index(t_intlist **a, int c);
int     list_len(t_intlist **stack);

void    swap_a(t_intlist **stack);
void    swap_b(t_intlist **stack);
void    swap_ab(t_intlist **stack_a, t_intlist **stack_b);
void    rotate_a(t_intlist **stack);
void    rotate_b(t_intlist **stack);
void    rotate_ab(t_intlist **stack_a, t_intlist **stack_b);
void    reverse_rotate_a(t_intlist **stack);
void    reverse_rotate_b(t_intlist **stack);
void    reverse_rotate_ab(t_intlist **stack_a, t_intlist **stack_b);
void    push_a(t_intlist **stack_a, t_intlist **stack_b);
void    push_b(t_intlist **stack_a, t_intlist **stack_b);

#endif
