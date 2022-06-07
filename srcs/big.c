/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:41:13 by fleduc            #+#    #+#             */
/*   Updated: 2022/06/07 15:36:43 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	align_b(t_intlist **b, int sm)
{
	t_intlist	*iterate;
	int			sm_2;

	if ((*b) == NULL || (*b)->next == NULL)
		return ;
	sm_2 = minimum(b);
	if (sm < sm_2)
	{
		rotate_stack_b(b, get_max(b));
		return ;
	}
	iterate = *b;
	while (iterate)
	{
		if (iterate->content <= sm && sm_2 < iterate->content)
			sm_2 = iterate->content;
		iterate = iterate->next;
	}
	if (!see_smaller(b, sm))
		rotate_stack_b(b, minimum(b));
	else
		rotate_stack_b(b, sm_2);
}

void	ten_to_infinite(int count, int chunk, t_intlist **a, t_intlist **b)
{
	int	sm;

	while (--count >= 0)
	{
		sm = get_min(a, chunk);
		rotate_stack_a(a, sm);
		align_b(b, sm);
		push_b(a, b);
	}
	rotate_stack_b(b, get_max(b));
	while (*b)
		push_a(a, b);
}

void	big(int count, t_intlist **stack_a, t_intlist **stack_b)
{
	int	chunk;

	chunk = (count / 20) + 5;
	if (chunk % 2 != 0)
		++chunk;
	ten_to_infinite(count, chunk, stack_a, stack_b);
}
