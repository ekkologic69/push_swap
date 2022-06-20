/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboulho <maboulho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 11:37:47 by maboulho          #+#    #+#             */
/*   Updated: 2022/06/17 21:11:43 by maboulho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if(t_list **stack_a, t_range *range)
{
	if (((*stack_a)->data >= range->first)
		&& ((*stack_a)->data <= range->last))
		return (1);
	return (0);
}

void	chunks(t_list **stack_a, t_list **stack_b, int *tab, int c)
{	
	t_range	*range;

	range = malloc(sizeof(t_range));
	if (!range)
		return ;
	tab = malloc(ft_lstsize(*stack_a) * sizeof(int));
	stack_to_tab(*stack_a, tab);
	range->mid2 = tab[ft_lstsize(*stack_a) / 2];
	while (ft_lstsize(*stack_a))
	{
		set_range(stack_a, tab, range, c);
		if (c >= ft_lstsize(*stack_a) / 2)
			rest_in_range(stack_a, range, tab);
		if (check_if(stack_a, range))
		{
			push_b(stack_a, stack_b);
			if ((*stack_b)->data < range->mid2)
				rotate_b(stack_b);
		}
		else
			rotate_a(stack_a);
		stack_to_tab(*stack_a, tab);
	}
	free(range);
	free(tab);
}

t_size	*ft_help_norm(t_list **stack_a, t_list **stack_b, int *tab, t_size *l)
{
	if ((*stack_b)->data == tab[l->size])
	{
		push_a(stack_a, stack_b);
		l->size--;
	}
	else
	{
		if (l->down == 0 || (*stack_b)->data > ft_lstlast(*stack_a)->data)
		{
			push_a(stack_a, stack_b);
			rotate_a(stack_a);
			l->down++;
		}
		else
		{
			if (ft_index100(stack_b) <= (ft_lstsize(*stack_b) / 2))
				rotate_b(stack_b);
			else
				rev_rotate_b(stack_b);
		}
	}
	return (l);
}

void	b_to_a(t_list **stack_a, t_list **stack_b, int *tab)
{
	t_size	*l;

	l = malloc(sizeof(t_size));
	if (!l)
		return ;
	l->size = ft_lstsize(*stack_b) - 1;
	l->down = 0;
	tab = malloc(ft_lstsize(*stack_b) * sizeof(int));
	stack_to_tab(*stack_b, tab);
	while (ft_lstsize(*stack_b))
	{
		if (check_if_exist(tab[l->size], *stack_b))
			l = ft_help_norm(stack_a, stack_b, tab, l);
		else
		{
			rev_rotate_a(stack_a);
			l->down--;
			l->size--;
		}
	}
	while (l->down--)
		rev_rotate_a(stack_a);
	free(l);
	free(tab);
}

void	sort_500(t_list **stack_a, t_list **stack_b, int *tab)
{
	chunks(stack_a, stack_b, tab, 20);
	b_to_a(stack_a, stack_b, tab);
}
