/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboulho <maboulho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:10:45 by maboulho          #+#    #+#             */
/*   Updated: 2022/06/16 19:24:55 by maboulho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_list **stack_a, t_list **stack_b, int ac, int *tab)
{
	if (ac > 1)
	{
		if (ac > 150)
			sort_500(stack_a, stack_b, tab);
		else if (ac >= 50)
			sort_100(stack_a, stack_b, tab);
		else if (ac >= 7)
			small_sort(stack_a, stack_b, tab);
		else if (ac == 3)
			sort_two(stack_a);
		else if (ac == 4)
			sorthree(stack_a);
		else if (ac == 5)
			sort_four(stack_a, stack_b);
		else if (ac == 6)
			sort_five(stack_a, stack_b);
	}
}
