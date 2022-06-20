/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboulho <maboulho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 15:24:44 by maboulho          #+#    #+#             */
/*   Updated: 2022/06/13 22:40:17 by maboulho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	if (ft_lstsize(*lst) != 0)
	{
		ft_lstlast(*lst)->next = new;
		new->next = NULL;
	}
	return ;
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list		*ek;
	int			i;

	i = ft_lstsize(lst);
	ek = lst;
	while (i > 1)
	{
		ek = ek -> next;
		i--;
	}
	return (ek);
}

int	get_tail(t_list *lst)
{
	int	i;
	int	len;

	len = ft_lstsize(lst);
	i = 0;
	while (i < len - 1)
	{
		lst = lst->next;
		i++;
	}
	return (lst->data);
}

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

int	check_if_exist(int nb, t_list *s)
{
	while (s)
	{
		if (s->data == nb)
			return (1);
		s = s->next;
	}
	return (0);
}
