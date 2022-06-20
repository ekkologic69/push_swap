/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboulho <maboulho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 15:18:20 by maboulho          #+#    #+#             */
/*   Updated: 2022/06/17 18:24:03 by maboulho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **stack_a)
{
	t_list	*temp;
	t_list	*temp2;

	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp2 = *stack_a;
	*stack_a = (*stack_a)->next;
	temp2->next = temp;
	temp->next = *stack_a;
	*stack_a = temp2;
	write(1, "sa\n", 3);
}

void	rotate_a(t_list **stack_a)
{
	t_list	*temp;
	t_list	*temp2;
	int		i;

	if (!(*stack_a)->next)
		return ;
	temp2 = *stack_a;
	i = ft_lstsize(*stack_a);
	temp = ft_lstlast(*stack_a);
	*stack_a = (*stack_a)->next;
	temp2->next = NULL;
	temp->next = temp2;
	write(1, "ra\n", 3);
}

void	rev_rotate_a(t_list **stack_a)
{
	t_list	*temp;
	t_list	*temp2;
	int		i;

	i = 0;
	temp2 = *stack_a;
	while (i < ft_lstsize(*stack_a) - 2)
		*stack_a = (*stack_a)->next;
	temp = ft_lstlast(*stack_a);
	temp->next = temp2;
	(*stack_a)->next = NULL;
	(*stack_a) = temp;
	write(1, "rra\n", 4);
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	temp = *stack_a;
	*stack_a = (*stack_a)-> next;
	temp ->next = NULL;
	temp ->next = *stack_b;
	*stack_b = temp;
	write(1, "pb\n", 3);
}
