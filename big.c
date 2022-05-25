/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:41:13 by fleduc            #+#    #+#             */
/*   Updated: 2022/05/25 00:20:14 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	b_pusher(int count, t_intlist **a, t_intlist **b)
{
	t_intlist	*iterate;
	int			sm;
	int			lst_len;

	while (--count >= 0)
	{
		iterate = (*a)->next;
		sm = (*a)->content;
		while (iterate)
		{
			if (sm > iterate->content && (find_index(a, sm) < (count / 15)
					|| find_index(a, sm) > count - (count / 15)))
				sm = iterate->content;
			iterate = iterate->next;
		}
		while ((*a)->content != sm)
		{
			lst_len = list_len(a);
			if (lst_len % 2 != 0)
				++lst_len;
			if (find_index(a, sm) <= (lst_len / 2))
				rotate_a(a);
			else
				reverse_rotate_a(a);
		}
		push_b(a, b);
	}
}

void	a_pusher(int count, t_intlist **a, t_intlist **b)
{
	t_intlist	*iterate;
	int			bg;
	int			lst_len;

	while (--count >= 0)
	{
		iterate = (*b)->next;
		bg = (*b)->content;
		while (iterate)
		{
			if (bg < iterate->content)
				bg = iterate->content;
			iterate = iterate->next;
		}
		while ((*b)->content != bg)
		{
			lst_len = list_len(b);
			if (lst_len % 2 != 0)
				++lst_len;
			if (find_index(b, bg) <= (lst_len / 2))
				rotate_a(b);
			else
				reverse_rotate_a(b);
		}
		push_a(a, b);
	}
}*/
void	count_sort(t_intlist **a, int size, int place)
{
	t_intlist	*iterate;
	int			*output;
	int			*count;
	int			max;
	int			i;

	output = ft_calloc(size + 1, sizeof(int));
	iterate = *a;
	max = iterate->content;
	i = 0;
	while (iterate)
	{
		iterate = iterate->next;
		if ((iterate->content / place) % 10 > max)
			max = iterate->content;
	}
	count = ft_calloc(max + 1, sizeof(int));
	iterate = *a;
	while (iterate)
	{
		count[(iterate->content / place) % 10]++;
		iterate = iterate->next;
	}
	i = 0;
	while (++i < max)
		count[i] += count[i - 1];
	i = size - 1;
	iterate = *a;
	while (i >= 0)
	{
		 output[] = iterate->content;
		--i;
	}
}

void	radix_sort(int size, t_intlist **a, t_intlist **b)
{
	int	max;
	int	place;

	max = get_max(a);
	place = 1;
	while (max / place > 0)
	{
		count_sort(a, size, place);
		place *= 10;
	}
}

void	ten_to_infinite(int count, t_intlist **a, t_intlist **b)
{
	radix_sort(count, a, b);
}

void	big(int count, t_intlist **stack_a, t_intlist **stack_b)
{
	ten_to_infinite(count, stack_a, stack_b);
	printf("\n");
	while ((*stack_a))
	{
		printf("%d\n", (*stack_a)->content);
		(*stack_a) = (*stack_a)->next;
	}
}
