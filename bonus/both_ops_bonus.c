/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   both_ops_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:11:40 by fleduc            #+#    #+#             */
/*   Updated: 2022/06/06 17:33:49 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	swap_ab(t_intlist **stack_a, t_intlist **stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
	return (0);
}

int	rotate_ab(t_intlist **stack_a, t_intlist **stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
	return (0);
}

int	reverse_rotate_ab(t_intlist **stack_a, t_intlist **stack_b)
{
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);
	return (0);
}
