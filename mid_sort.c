/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboulho <maboulho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 00:21:40 by maboulho          #+#    #+#             */
/*   Updated: 2022/06/16 19:34:03 by maboulho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_list **stack_a, t_list **stack_b, int *tab)
{
	chunks(stack_a, stack_b, tab, 2);
	b_to_a(stack_a, stack_b, tab);
}
