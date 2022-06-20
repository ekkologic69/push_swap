/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboulho <maboulho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:08:33 by maboulho          #+#    #+#             */
/*   Updated: 2022/06/17 19:01:20 by maboulho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **stack_a, int false)
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
	if (false == 1)
		write(1, "sa\n", 3);
}

void	ra(t_list **stack_a, int false)
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
	if (false == 1)
		write(1, "ra\n", 3);
}

void	rra(t_list **stack_a, int false)
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
	if (false == 1)
		write(1, "rra\n", 4);
}

void	pa(t_list **stack_a, t_list **stack_b, int false)
{
	t_list	*temp;

	temp = *stack_b;
	*stack_b = (*stack_b)-> next;
	temp ->next = NULL;
	temp ->next = *stack_a;
	*stack_a = temp;
	if (false == 1)
		write(1, "pa\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b, int false)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	if (false == 1)
		write(1, "ss\n", 3);
}
