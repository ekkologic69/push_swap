/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboulho <maboulho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 15:23:19 by maboulho          #+#    #+#             */
/*   Updated: 2022/06/17 18:27:10 by maboulho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	creat(t_list **stack_a, int i)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	new->data = i;
	new->next = NULL;
	ft_lstadd_back(stack_a, new);
}

void	stack_to_tab(t_list *stack_a, int *tab)
{
	int		i;
	t_list	*tmp;

	tmp = stack_a;
	i = 0;
	while (ft_lstsize(tmp))
	{
		tab[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
	sortab(tab, ft_lstsize(stack_a));
}
