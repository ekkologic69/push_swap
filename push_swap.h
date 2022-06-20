/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboulho <maboulho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 00:07:34 by maboulho          #+#    #+#             */
/*   Updated: 2022/06/17 19:04:44 by maboulho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"

typedef struct t_size
{
	int	down;
	int	size;
}	t_size;

typedef struct t_range
{
	int	mid;
	int	first;
	int	last;
	int	mid2;
}	t_range;
typedef struct s_list
{
	int				data;
	int				index;
	struct s_list	*next;
}	t_list;

int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int		get_tail(t_list *lst);
void	creat(t_list **stack_a, int i);
int		ft_isdigit(int c);
int		ft_check_num(char **av);
int		ft_index(t_list	**stack_a);
void	swap_a(t_list **stack_a);
void	swap_b(t_list **stack_b);
void	rotate_a(t_list **stack_a);
void	rotate_b(t_list **stack_b);
void	rev_rotate_a(t_list **stack_a);
void	rev_rotate_b(t_list **stack_b);
void	ktbi(t_list *stack);
void	push_b(t_list **stack_a, t_list **stack_b);
void	push_a(t_list **stack_a, t_list **stack_b);
void	sorthree(t_list **a);
void	sort_two(t_list **stack_a);
void	sort_four(t_list **stack_a, t_list **stack_b);
void	sort_five(t_list **stack_a, t_list **stack_b);
int		check_sorted(t_list *stack_a);
int		ft_atoi(char *str);
void	stack_to_tab(t_list *stack_a, int *tab);
void	sortab(int *tab, int size);
void	chunks(t_list **stack_a, t_list **stack_b, int *tab, int c);
void	push_biggest(t_list **stack_a, t_list **stack_b);
int		ft_index100(t_list **stack_a);
void	sort_500(t_list **stack_a, t_list **stack_b, int *tab);
void	b_to_a(t_list **stack_a, t_list **stack_b, int *tab);
int		check_if_exist(int nb, t_list *s);
int		check_duplicates(char **av);
void	print_error(void);
void	sort_100(t_list **stack_a, t_list **stack_b, int *tab);
void	sorting(t_list **stack_a, t_list **stack_b, int ac, int *tab);
void	test(int down, t_list **stack_a, t_list **stack_b);
void	set_range(t_list **stack_a, int *tab, t_range *range, int c);
void	rest_in_range(t_list **stack_a, t_range *range, int *tab);
void	small_sort(t_list **stack_a, t_list **stack_b, int *tab);
int		ft_strncmp(const char *s1, const char *s2, int n);
void	rr(t_list **stack_a, t_list **stack_b, int false);
void	ss(t_list **stack_a, t_list **stack_b, int false);
void	rrr(t_list **stack_a, t_list **stack_b, int false);
void	checker(t_list **stack_a, t_list **stack_b);
void	sb(t_list **stack_b, int false);
void	sa(t_list **stack_a, int false);
void	ra(t_list **stack_a, int false);
void	rra(t_list **stack_a, int false);
void	pa(t_list **stack_a, t_list **stack_b, int false);
void	rb(t_list **stack_b, int false);
void	rrb(t_list **stack_b, int false);
void	pb(t_list **stack_a, t_list **stack_b, int false);
int		check_if(t_list **stack_a, t_range *range);
long	ft_atoi_1(char *str);
int		check_if_sorted(t_list *stack_a);
#endif
