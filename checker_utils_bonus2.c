/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboulho <maboulho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:51:11 by maboulho          #+#    #+#             */
/*   Updated: 2022/06/17 19:02:41 by maboulho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	sb(t_list **stack_b, int false)
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
	if (false == 1)
		write(1, "sb\n", 3);
}

void	rb(t_list **stack_b, int false)
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
	if (false == 1)
		write(1, "rb\n", 3);
}

void	rrb(t_list **stack_b, int false)
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
	if (false == 1)
		write(1, "rrb\n", 4);
}

void	pb(t_list **stack_a, t_list **stack_b, int false)
{
	t_list	*temp;

	temp = *stack_a;
	*stack_a = (*stack_a)-> next;
	temp ->next = NULL;
	temp ->next = *stack_b;
	*stack_b = temp;
	if (false == 1)
		write(1, "pb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b, int false)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (false == 1)
		write(1, "rr\n", 1);
}
