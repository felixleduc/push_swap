/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:10:27 by fleduc            #+#    #+#             */
/*   Updated: 2022/06/13 10:59:40 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(t_intlist **stack)
{
	t_intlist	*tmp;

	if (!(*stack && (*stack)->next))
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = (*stack);
	(*stack) = tmp;
	write(1, "sb\n", 3);
}

void	push_b(t_intlist **stack_a, t_intlist **stack_b)
{
	t_intlist	*tmp;

	if (!(*stack_a))
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = (*stack_b);
	*stack_b = tmp;
	write(1, "pb\n", 3);
}

void	rotate_b(t_intlist **stack)
{
	t_intlist	*rot;
	t_intlist	*tmp;

	if (!(*stack && (*stack)->next))
		return ;
	tmp = *stack;
	rot = *stack;
	*stack = (*stack)->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = rot;
	rot->next = NULL;
	write(1, "rb\n", 3);
}

void	reverse_rotate_b(t_intlist **stack)
{
	t_intlist	*iterate;
	t_intlist	*rot;

	if (!(*stack && (*stack)->next))
		return ;
	iterate = *stack;
	while (iterate->next->next)
		iterate = iterate->next;
	rot = iterate->next;
	rot->next = (*stack);
	(*stack) = rot;
	iterate->next = NULL;
	write(1, "rrb\n", 4);
}
