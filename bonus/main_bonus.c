/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 16:02:23 by fleduc            #+#    #+#             */
/*   Updated: 2022/06/07 11:34:36 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	clean_str(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void	clean(t_intlist **stack_a, t_intlist **stack_b)
{
	t_intlist	*tmp;

	if (*stack_a == NULL && *stack_b)
		return ;
	while (*stack_a)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		free(tmp);
	}
	while (*stack_b)
	{
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		free(tmp);
	}
}

void	fill_stack(t_intlist **stack_a, t_intlist **stack_b, int c, char **num)
{
	t_intlist	*ptr;
	int			i;

	i = 0;
	*stack_a = (t_intlist *)malloc(sizeof(t_intlist));
	*stack_b = NULL;
	ptr = *stack_a;
	while (i <= c)
	{
		ptr->content = ft_atoi(num[i]);
		if (i != c)
		{
			ptr->next = (t_intlist *)malloc(sizeof(t_intlist));
			ptr = ptr->next;
		}
		++i;
	}
	ptr->next = NULL;
}

void	check(int count, t_intlist **stack_a, t_intlist **stack_b)
{
	char	*line;

	if (count == 1)
		return ;
	line = get_next_line(0);
	while (line)
	{
		if (do_op(line, stack_a, stack_b))
		{
			write(2, "Error\n", 6);
			return ;
		}
		free(line);
		line = get_next_line(0);
	}
	print_checker(stack_a, stack_b);
}

int	main(int argc, char *argv[])
{
	char		**splitted;
	t_intlist	*stack_a;
	t_intlist	*stack_b;

	splitted = NULL;
	if (argc >= 2)
	{
		if (argc == 2)
			splitted = ft_split(argv[1], 32);
		else if (argc > 2)
			splitted = rm_first(argv, argc);
		argc = ft_len(splitted);
	}
	if (splitted != NULL && check_errors(splitted, argc))
		write(2, "Error\n", 6);
	else if (splitted != NULL)
	{
		fill_stack(&stack_a, &stack_b, argc - 1, splitted);
		check(argc, &stack_a, &stack_b);
		clean(&stack_a, &stack_b);
	}
	if (splitted != NULL)
		clean_str(splitted);
	return (0);
}
