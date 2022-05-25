/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:40:54 by fleduc            #+#    #+#             */
/*   Updated: 2022/05/24 17:49:18 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index(t_intlist **stack, int c)
{
	t_intlist	*iterate;
	int			i;

	iterate = *stack;
	i = 1;
	while (iterate->content != c)
	{
		++i;
		iterate = iterate->next;
	}
	return (i);
}

int	list_len(t_intlist **stack)
{
	t_intlist	*iterate;
	int			i;

	iterate = *stack;
	i = 0;
	while (iterate)
	{
		iterate = iterate->next;
		++i;
	}
	return (i);
}

void	new_node(t_intlist **stack)
{
	*stack = (t_intlist *)malloc(sizeof(t_intlist));
	(*stack)->next = NULL;
}

int	check_order(t_intlist **stack_a)
{
	t_intlist	*iterate;

	iterate = *stack_a;
	while (iterate->next)
	{
		if (iterate->content > iterate->next->content)
			return (0);
		iterate = iterate->next;
	}
	return (1);
}

int	ft_len(char **double_str)
{
	int	i;

	i = 0;
	while (double_str[i])
		++i;
	return (i);
}