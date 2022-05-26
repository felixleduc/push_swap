/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:41:01 by fleduc            #+#    #+#             */
/*   Updated: 2022/05/26 17:16:35 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	four_to_nine(int count, t_intlist **a, t_intlist **b)
{
	t_intlist	*iterate;
	int			sm;

	iterate = (*a);
	while (--count >= 0)
	{
		sm = get_min(a, count);
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
	/*printf("\n");
	while ((*stack_a))
	{
		printf("%d\n", (*stack_a)->content);
		(*stack_a) = (*stack_a)->next;
	}*/
}
