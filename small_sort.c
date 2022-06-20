/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboulho <maboulho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 15:22:10 by maboulho          #+#    #+#             */
/*   Updated: 2022/06/17 18:08:40 by maboulho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	sorthree(t_list **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->data;
	second = (*a)->next->data;
	third = (*a)->next->next->data;
	if (!(ft_lstsize((*a))))
		return ;
	if (first > second && (second < third && (first < third)))
		swap_a(a);
	else if (first > second && second > third)
	{
		swap_a(a);
		rev_rotate_a(a);
	}
	else if (first > second && second < third && first > third)
		rotate_a(a);
	else if (first < second && second > third && first < third)
	{
		swap_a(a);
		rotate_a(a);
	}
	else if (first < second && second > third && first > third)
		rev_rotate_a(a);
}

void	sort_two(t_list **stack_a)
{
	if ((*stack_a)->data > (*stack_a)->next->data)
		swap_a(stack_a);
}

void	push_smallest(t_list **stack_a, t_list **stack_b)
{
	int	index;
	int	mid;
	int	i;

	index = ft_index(stack_a);
	mid = (ft_lstsize(*stack_a) / 2);
	i = ft_lstsize(*stack_a) - index;
	if (mid < index)
	{
		while (i--)
		{
			rev_rotate_a(stack_a);
		}
		push_b(stack_a, stack_b);
	}
	else
	{
		i = index;
		while (i--)
		{
			rotate_a(stack_a);
		}
		push_b(stack_a, stack_b);
	}
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	push_smallest(stack_a, stack_b);
	push_smallest(stack_a, stack_b);
	sorthree(stack_a);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	push_smallest(stack_a, stack_b);
	sorthree(stack_a);
	push_a(stack_a, stack_b);
}
