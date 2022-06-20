/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboulho <maboulho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 18:39:32 by maboulho          #+#    #+#             */
/*   Updated: 2022/06/13 14:51:32 by maboulho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check(int counter, int sign, int result)
{
	if (counter > 19)
		print_error();
	return (result * sign);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;
	int	counter;

	i = 0;
	sign = 1;
	result = 0;
	counter = 0;
	while (str[i] == ' ' || str[i] == '\r' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\t')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1 * sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
		counter++;
	}
	return (check(counter, sign, result));
}

// char	*ft_strchr(char **av, int c)
// {
// 	int	i;
// 	int j;

// 	i = 0;
// 	j = 0;
// 	while (av[i][j])
// 	{
// 		if (av[i] == (char)c)
// 			return ((char *)&s[i]);
// 		i++;
// 	}
// 	if (s[i] == (char)c)
// 		return ((char *)&s[i]);
// 	return (NULL);
// }