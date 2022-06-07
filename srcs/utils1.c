/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:40:54 by fleduc            #+#    #+#             */
/*   Updated: 2022/06/07 15:36:25 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index(t_intlist **stack, int c)
{
	t_intlist	*iterate;
	int			i;

	iterate = *stack;
	i = 1;
	if (iterate == NULL)
		return (0);
	while (iterate->next != NULL && iterate->content != c)
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

	if (*stack == NULL)
		return (0);
	iterate = *stack;
	i = 0;
	while (iterate)
	{
		iterate = iterate->next;
		++i;
	}
	return (i);
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

char	**rm_first(char **arg, int argc)
{
	char	**splitted;
	int		i;
	int		j;

	splitted = (char **)ft_calloc(argc, sizeof(char *));
	i = 0;
	while (i < argc - 1)
	{
		j = -1;
		splitted[i] = ft_calloc(ft_strlen(arg[i + 1]) + 1, sizeof(char));
		while (arg[i + 1][++j])
			splitted[i][j] = arg[i + 1][j];
		++i;
	}
	return (splitted);
}
