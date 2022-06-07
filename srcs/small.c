/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:41:01 by fleduc            #+#    #+#             */
/*   Updated: 2022/06/07 15:01:48 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	minimum(t_intlist **stack)
{
	t_intlist	*tmp;
	int			min;

	tmp = *stack;
	min = (*stack)->content;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (min > tmp->content)
			min = tmp->content;
	}
	return (min);
}

void	four_to_nine(int count, t_intlist **a, t_intlist **b)
{
	int			sm;

	while (--count >= 0)
	{
		sm = minimum(a);
		rotate_stack_a(a, sm);
		push_b(a, b);
	}
	three(a);
	while (*b)
		push_a(a, b);
}

void	three(t_intlist **a)
{
	if (check_order(a))
		return ;
	if ((*a)->content < (*a)->next->content)
		reverse_rotate_a(a);
	if ((*a)->content > (*a)->next->content
		&& (*a)->content > (*a)->next->next->content)
		rotate_a(a);
	if ((*a)->content > (*a)->next->content)
		swap_a(a);
}

void	small(int count, t_intlist **stack_a, t_intlist **stack_b)
{
	if (count == 2 && (*stack_a)->content > (*stack_a)->next->content)
		swap_a(stack_a);
	else if (count == 3)
		three(stack_a);
	else if (count >= 4 && count <= 9)
		four_to_nine(count - 3, stack_a, stack_b);
}
