/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:00:11 by fleduc            #+#    #+#             */
/*   Updated: 2022/06/07 15:17:54 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean(t_intlist **stack_a)
{
	t_intlist	*tmp;

	if ((*stack_a) == NULL)
		return ;
	while (*stack_a)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		free(tmp);
	}
}

void	fill_stack(t_intlist **stack_a, t_intlist **stack_b, int c, char **num)
{
	t_intlist	*ptr;
	int			i;

	i = 0;
	if (!(num[0][0] >= '0' && num[0][0] <= '9') || num[0][0] == '-')
		i += 1;
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

void	redirect(int count, t_intlist **stack_a, t_intlist **stack_b)
{
	if (check_order(stack_a))
		return ;
	if (count < 10)
		small(count, stack_a, stack_b);
	else if (count >= 10)
		big(count, stack_a, stack_b);
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
		redirect(argc, &stack_a, &stack_b);
		clean(&stack_a);
	}
	if (splitted != NULL)
		clean_str(splitted);
	return (0);
}
