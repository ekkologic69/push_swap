/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboulho <maboulho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 15:07:38 by maboulho          #+#    #+#             */
/*   Updated: 2022/06/17 21:07:36 by maboulho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	check_if_sorted(t_list *stack_a)
{
	int	i;

	if (stack_a)
	{
		while (stack_a->next)
		{
			i = stack_a->data;
			stack_a = stack_a->next;
			if (i > stack_a->data)
				return (0);
		}
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	int			i;
	int			*tab;
	t_list		*stack_a;
	t_list		*stack_b;

	tab = NULL;
	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	if (ac > 1)
	{
		if (ft_check_num(av) || check_duplicates(av))
			return (0);
		while (i < ac)
		{		
			creat(&stack_a, ft_atoi(av[i]));
				i++;
		}
		if (!check_if_sorted(stack_a))
			sorting(&stack_a, &stack_b, ac, tab);
	}
	return (0);
}
