/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboulho <maboulho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:24:34 by maboulho          #+#    #+#             */
/*   Updated: 2022/06/13 14:50:32 by maboulho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	write(1, "ERROR\n", 6);
	exit(1);
}

int	ft_isdigit(int c)
{
	if ((c < '0' || c > '9'))
		return (1);
	return (0);
}

int	ft_check_num(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (av[i])
	{
		j = 0;
		if (ft_atoi_1(av[i]) > 2147483647 || ft_atoi_1(av[i]) < -2147483648)
			print_error();
		if ((av[i][0] == '-' || av[i][0] == '+') && av[i][1] != '\0')
			j = 1;
		while (av[i][j])
		{
			if ((ft_isdigit(av[i][j])))
				print_error();
			j++;
		}
		i++;
	}
	return (0);
}

int	check_duplicates(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				print_error();
			j++;
		}
		i++;
	}
	return (0);
}

// void    check_sorted(t_list **stack_a)
// {
//     while((*stack_a)->next)
//     {
//         if((*stack_a)->data < (*stack_a)->next->data)
//             *stack_a = (*stack_a)->next;
//         else
//           { 
//            write(1,"not sorted",10);
//            exit(1);
//           }
//     }
// }
