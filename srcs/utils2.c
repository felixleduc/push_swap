/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 22:00:05 by fleduc            #+#    #+#             */
/*   Updated: 2022/06/07 15:01:07 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_intlist **stack, int chunk)
{
	t_intlist	*tmp;
	int			min;

	tmp = *stack;
	min = (*stack)->content;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (min > tmp->content && (find_index(stack, tmp->content) <= chunk / 2
				|| find_index(stack, tmp->content)
				>= list_len(stack) - (chunk / 2)))
			min = tmp->content;
	}
	return (min);
}

int	get_max(t_intlist **stack)
{
	t_intlist	*iterate;
	int			max;

	iterate = (*stack)->next;
	max = (*stack)->content;
	while (iterate)
	{
		if (max < iterate->content)
			max = iterate->content;
		iterate = iterate->next;
	}
	return (max);
}

int	see_smaller(t_intlist **stack, int num)
{
	t_intlist	*iterate;

	iterate = *stack;
	while (iterate->next)
	{
		if (iterate->content < num)
			return (1);
		iterate = iterate->next;
	}
	return (0);
}

void	rotate_stack_b(t_intlist **stack, int num)
{
	int	lst_len;

	while ((*stack)->content != num)
	{
		lst_len = list_len(stack);
		if (lst_len % 2 != 0)
				++lst_len;
		if (find_index(stack, num) <= (lst_len / 2))
			rotate_b(stack);
		else
			reverse_rotate_b(stack);
	}
}

void	rotate_stack_a(t_intlist **stack, int num)
{
	int	lst_len;

	while ((*stack)->content != num)
	{
		lst_len = list_len(stack);
		if (lst_len % 2 != 0)
				++lst_len;
		if (find_index(stack, num) <= (lst_len / 2))
			rotate_a(stack);
		else
			reverse_rotate_a(stack);
	}
}
