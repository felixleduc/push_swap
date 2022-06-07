/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:12:47 by fleduc            #+#    #+#             */
/*   Updated: 2022/06/07 15:03:40 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_if_number(char *arg)
{
	int	i;

	i = -1;
	if (arg[0] == '-')
	{
		if (!(arg[1] >= '0' && arg[1] <= '9'))
			return (0);
		++i;
	}
	while (arg[++i])
		if (!(arg[i] >= '0' && arg[i] <= '9'))
			return (0);
	return (1);
}

int	check_if_int(char *arg)
{
	if (ft_strlen(arg) > 11)
		return (0);
	else if (ft_atol(arg) > INT_MAX || ft_atol(arg) < INT_MIN)
		return (0);
	return (1);
}

int	check_if_dup(char **args, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (ft_strcmp((char *)args[i], (char *)args[j]) == 0)
				return (1);
			++j;
		}
		++i;
	}
	return (0);
}

int	check_errors(char **splitted, int argc)
{
	int		i;

	i = -1;
	while (splitted[++i])
		if (!(check_if_number(splitted[i])))
			return (1);
	i = -1;
	while (splitted[++i])
		if (!(check_if_int(splitted[i])))
			return (1);
	if (check_if_dup(splitted, argc))
		return (1);
	return (0);
}
