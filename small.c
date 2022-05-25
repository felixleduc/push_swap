/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:41:01 by fleduc            #+#    #+#             */
/*   Updated: 2022/05/25 00:20:17 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	four_to_nine(int count, t_intlist **a, t_intlist **b)
{
	t_intlist	*iterate;
	t_intlist	*smallest;
	int			lst_len;

	while (--count >= 0)
	{
		iterate = (*a)->next;
		smallest = *a;
		while (iterate)
		{
			if (smallest->content > iterate->content)
				smallest = iterate;
			iterate = iterate->next;
		}
		while ((*a)->content != smallest->content)
		{
			lst_len = list_len(a);
			if (lst_len % 2 != 0)
				++lst_len;
			if (find_index(a, smallest->content) <= (lst_len / 2))
				rotate_a(a);
			else
				reverse_rotate_a(a);
		}
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
