/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:10:27 by fleduc            #+#    #+#             */
/*   Updated: 2022/05/24 17:14:19 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(t_intlist **stack)
{
	t_intlist	*tmp;

	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = (*stack);
	(*stack) = tmp;
	write(1, "sb\n", 3);
}

void	push_b(t_intlist **stack_a, t_intlist **stack_b)
{
	t_intlist	*new;
	t_intlist	*tmp;

	if (!stack_a || !stack_b)
		return ;
	new_node(&new);
	new->content = (*stack_a)->content;
	new->next = (*stack_b);
	(*stack_b) = new;
	tmp = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	free(tmp);
	write(1, "pb\n", 3);
}

void	rotate_b(t_intlist **stack)
{
	t_intlist	*iterate;
	t_intlist	*rot;
	t_intlist	*first_node;

	iterate = *stack;
	rot = malloc(sizeof(t_intlist));
	rot->content = (*stack)->content;
	rot->next = NULL;
	while (iterate->next != NULL)
		iterate = iterate->next;
	iterate->next = rot;
	first_node = *stack;
	*stack = (*stack)->next;
	free(first_node);
	write(1, "rb\n", 3);
}

void	reverse_rotate_b(t_intlist **stack)
{
	t_intlist	*iterate;
	t_intlist	*rot;
	t_intlist	*last_node;

	iterate = *stack;
	while (iterate->next->next != NULL)
		iterate = iterate->next;
	rot = malloc(sizeof(t_intlist));
	rot->content = iterate->next->content;
	rot->next = (*stack);
	(*stack) = rot;
	last_node = iterate->next;
	iterate->next = NULL;
	free(last_node);
	write(1, "rrb\n", 4);
}
