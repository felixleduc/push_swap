/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops2_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:10:27 by fleduc            #+#    #+#             */
/*   Updated: 2022/06/06 17:43:31 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	swap_b(t_intlist **stack)
{
	t_intlist	*tmp;

	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = (*stack);
	(*stack) = tmp;
	return (0);
}

int	push_b(t_intlist **stack_a, t_intlist **stack_b)
{
	t_intlist	*tmp;

	if (!(*stack_a))
		return (0);
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = (*stack_b);
	*stack_b = tmp;
	return (0);
}

int	rotate_b(t_intlist **stack)
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
	return (0);
}

int	reverse_rotate_b(t_intlist **stack)
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
	return (0);
}
