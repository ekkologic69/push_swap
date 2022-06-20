/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboulho <maboulho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 22:12:36 by maboulho          #+#    #+#             */
/*   Updated: 2022/06/17 21:11:53 by maboulho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	sortab(int *tab, int size)
{
	int	i;
	int	j;
	int	swap;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = i;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				swap = tab[i];
				tab[i] = tab[j];
				tab[j] = swap;
			}
			j++;
		}
		i++;
	}
}

int	ft_index100(t_list **stack_b)
{
	int		index;
	t_list	*tmp;
	int		big;
	int		content;
	int		i;

	tmp = *stack_b;
	big = ((*stack_b)->data);
	index = 0;
	i = 0;
	content = ((*stack_b)->data);
	while (tmp->next != NULL)
	{
		content = tmp->next->data;
		tmp = tmp->next;
		i++;
		if (big < content)
		{
			big = content;
			index = i;
		}
	}
	return (index);
}

void	set_range(t_list **stack_a, int *tab, t_range *range, int c)
{
		range->mid = ft_lstsize(*stack_a) / 2;
		range->first = tab[range->mid - c];
		range->last = tab[range->mid + c];
}

void	rest_in_range(t_list **stack_a, t_range *range, int *tab)
{
			range->first = tab[0];
			range->last = tab[ft_lstsize(*stack_a)];
}
