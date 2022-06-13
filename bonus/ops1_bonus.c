/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops1_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:11:10 by fleduc            #+#    #+#             */
/*   Updated: 2022/06/13 10:56:27 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	swap_a(t_intlist **stack)
{
	t_intlist	*tmp;

	if (!(*stack && (*stack)->next))
		return (0);
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
	return (0);
}

int	push_a(t_intlist **stack_a, t_intlist **stack_b)
{
	t_intlist	*tmp;

	if (!(*stack_b))
		return (0);
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = (*stack_a);
	*stack_a = tmp;
	return (0);
}

int	rotate_a(t_intlist **stack)
{
	t_intlist	*rot;
	t_intlist	*tmp;

	if (!(*stack && (*stack)->next))
		return (0);
	tmp = *stack;
	rot = *stack;
	*stack = (*stack)->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = rot;
	rot->next = NULL;
	return (0);
}

int	reverse_rotate_a(t_intlist **stack)
{
	t_intlist	*iterate;
	t_intlist	*rot;

	if (!(*stack && (*stack)->next))
		return (0);
	iterate = *stack;
	while (iterate->next->next)
		iterate = iterate->next;
	rot = iterate->next;
	rot->next = (*stack);
	(*stack) = rot;
	iterate->next = NULL;
	return (0);
}
