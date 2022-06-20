/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboulho <maboulho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:18:55 by maboulho          #+#    #+#             */
/*   Updated: 2022/06/17 18:24:16 by maboulho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	swap_b(t_list **stack_b)
{
	t_list	*temp;
	t_list	*temp2;

	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp2 = *stack_b;
	*stack_b = (*stack_b)->next;
	temp2->next = temp;
	temp->next = *stack_b;
	*stack_b = temp2;
	write(1, "sb\n", 3);
}

void	rotate_b(t_list **stack_b)
{
	t_list	*temp;
	t_list	*temp2;
	int		i;

	if (!(*stack_b)->next)
		return ;
	temp2 = *stack_b;
	i = ft_lstsize(*stack_b);
	temp = ft_lstlast(*stack_b);
	*stack_b = (*stack_b)->next;
	temp2->next = NULL;
	temp->next = temp2;
	write(1, "rb\n", 3);
}

void	rev_rotate_b(t_list **stack_b)
{
	t_list	*temp;
	t_list	*temp2;
	int		i;

	i = 0;
	temp2 = *stack_b;
	while (i < ft_lstsize(*stack_b) - 2)
		*stack_b = (*stack_b)->next;
	temp = ft_lstlast(*stack_b);
	temp->next = temp2;
	(*stack_b)->next = NULL;
	(*stack_b) = temp;
	write(1, "rrb\n", 4);
}

void	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	temp = *stack_b;
	*stack_b = (*stack_b)-> next;
	temp ->next = NULL;
	temp ->next = *stack_a;
	*stack_a = temp;
	write(1, "pa\n", 3);
}
