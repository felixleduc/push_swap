/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <marvin@42quebec.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:35:14 by fleduc            #+#    #+#             */
/*   Updated: 2022/05/12 12:09:38 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	check_if_number(char *arg)
{
	int	i;

	i = -1;
	if (arg[0] == '-')
		++i;
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

int	check_if_dup(char **args, int count, int mp_strs)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (ft_strcmp((char *)args[i + mp_strs], (char *)args[j + mp_strs]) == 0)
				return (1);
			++j;
		}
		++i;
	}
	return (0);
}

int	check_errors(char **splitted, int argc, int mp_strs)
{
	int		i;

	i = -1;
	if (mp_strs == 1)
		++i;
	while (splitted[++i])
		if (!(check_if_number(splitted[i])))
			return (1);
	i = -1;
	if (mp_strs == 1)
		++i;
	while (splitted[++i])
		if (!(check_if_int(splitted[i])))
			return (1);
	if (check_if_dup(splitted, argc - mp_strs, mp_strs))
		return (1);
	return (0);
}
