/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboulho <maboulho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:52:52 by maboulho          #+#    #+#             */
/*   Updated: 2022/06/15 07:45:20 by maboulho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_index(t_list **stack_a)
{
	int		index;
	t_list	*tmp;
	int		min;
	int		content;
	int		i;

	tmp = *stack_a;
	min = ((*stack_a)->data);
	index = 0;
	i = 0;
	content = ((*stack_a)->data);
	while (tmp->next != NULL)
	{
		content = tmp->next->data;
		tmp = tmp->next;
		i++;
		if (min > content)
		{
			min = content;
			index = i;
		}
	}
	return (index);
}
