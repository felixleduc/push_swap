/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:40:54 by fleduc            #+#    #+#             */
/*   Updated: 2022/06/07 11:34:41 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

int	do_op(char *line, t_intlist **a, t_intlist **b)
{
	if (!ft_strcmp(line, "sa\n"))
		return (swap_a(a));
	else if (!ft_strcmp(line, "sb\n"))
		return (swap_b(b));
	else if (!ft_strcmp(line, "ss\n"))
		return (swap_ab(a, b));
	else if (!ft_strcmp(line, "ra\n"))
		return (rotate_a(a));
	else if (!ft_strcmp(line, "rb\n"))
		return (rotate_b(b));
	else if (!ft_strcmp(line, "rr\n"))
		return (rotate_ab(a, b));
	else if (!ft_strcmp(line, "rra\n"))
		return (reverse_rotate_a(a));
	else if (!ft_strcmp(line, "rrb\n"))
		return (reverse_rotate_b(b));
	else if (!ft_strcmp(line, "rrr\n"))
		return (reverse_rotate_ab(a, b));
	else if (!ft_strcmp(line, "pa\n"))
		return (push_a(a, b));
	else if (!ft_strcmp(line, "pb\n"))
		return (push_b(a, b));
	else
		return (1);
}

void	print_checker(t_intlist **a, t_intlist **b)
{
	if (check_order(a) && *b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
