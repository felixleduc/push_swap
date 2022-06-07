/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   both_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:11:40 by fleduc            #+#    #+#             */
/*   Updated: 2022/05/24 17:13:17 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_ab(t_intlist **stack_a, t_intlist **stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
	write(1, "ss\n", 3);
}

void	rotate_ab(t_intlist **stack_a, t_intlist **stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
	write(1, "rr\n", 3);
}

void	reverse_rotate_ab(t_intlist **stack_a, t_intlist **stack_b)
{
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);
	write(1, "rrr\n", 4);
}
