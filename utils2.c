/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 22:00:05 by fleduc            #+#    #+#             */
/*   Updated: 2022/05/25 00:20:16 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_intlist **stack)
{
	t_intlist	*tmp;
	int			max;

	tmp = *stack;
	max = (*stack)->content;
	while (tmp)
	{
		tmp = tmp->next;
		if (max < tmp->content)
			max = tmp->content;
	}
	return (max);
}
