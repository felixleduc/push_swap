/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:11:10 by fleduc            #+#    #+#             */
/*   Updated: 2022/05/24 17:14:14 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_intlist **stack)
{
	t_intlist	*tmp;

	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = (*stack);
	(*stack) = tmp;
	write(1, "sa\n", 3);
}

void	push_a(t_intlist **stack_a, t_intlist **stack_b)
{
	t_intlist	*tmp;

	if (!(*stack_b))
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = (*stack_a);
	*stack_a = tmp;
	write(1, "pa\n", 3);
}

void	rotate_a(t_intlist **stack)
{
	t_intlist	*rot;
	t_intlist	*tmp;

	tmp = *stack;
	rot = *stack;
	*stack = (*stack)->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = rot;
	rot->next = NULL;
	write(1, "ra\n", 3);
}

void	reverse_rotate_a(t_intlist **stack)
{
	t_intlist	*iterate;
	t_intlist	*rot;

	iterate = *stack;
	while (iterate->next->next)
		iterate = iterate->next;
	rot = iterate->next;
	rot->next = (*stack);
	(*stack) = rot;
	iterate->next = NULL;
	write(1, "rra\n", 4);
}
