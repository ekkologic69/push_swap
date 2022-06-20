/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboulho <maboulho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:34:43 by maboulho          #+#    #+#             */
/*   Updated: 2022/06/17 19:08:11 by maboulho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_moves(t_list **stack_a, t_list **stack_b, char *s)
{
	if (ft_strncmp(s, "sa\n", 3) == 0)
		sa(stack_a, 0);
	else if (ft_strncmp(s, "sb\n", 3) == 0)
		sb(stack_b, 0);
	else if (ft_strncmp(s, "ra\n", 3) == 0)
		ra(stack_a, 0);
	else if (ft_strncmp(s, "rb\n", 3) == 0)
		rb(stack_b, 0);
	else if (ft_strncmp(s, "pa\n", 3) == 0)
		pa(stack_a, stack_b, 0);
	else if (ft_strncmp(s, "pb\n", 3) == 0)
		pb(stack_a, stack_b, 0);
	else if (ft_strncmp(s, "ss\n", 3) == 0)
		ss(stack_a, stack_b, 0);
	else if (ft_strncmp(s, "rr\n", 3) == 0)
		rr(stack_a, stack_b, 0);
	else if (ft_strncmp(s, "rra\n", 4) == 0)
		rra(stack_a, 0);
	else if (ft_strncmp(s, "rrb\n", 4) == 0)
		rrb(stack_b, 0);
	else if (ft_strncmp(s, "rrr\n", 4) == 0)
		rrr(stack_a, stack_b, 0);
	else
		print_error();
}

void	checker(t_list **stack_a, t_list **stack_b)
{
	char	*s;

	s = get_next_line(0);
	while (s)
	{
		check_moves(stack_a, stack_b, s);
		free(s);
		s = get_next_line(0);
	}
	free(s);
}

int	check_sorted(t_list *stack_a)
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
	t_list		*stack_a;
	t_list		*stack_b;

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
		checker(&stack_a, &stack_b);
		if (check_sorted(stack_a) && !(ft_lstsize(stack_b)))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	return (0);
}
