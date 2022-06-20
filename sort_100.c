/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboulho <maboulho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 02:20:08 by maboulho          #+#    #+#             */
/*   Updated: 2022/06/15 00:34:06 by maboulho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_100(t_list **stack_a, t_list **stack_b, int *tab)
{
	chunks(stack_a, stack_b, tab, 10);
	b_to_a(stack_a, stack_b, tab);
}
