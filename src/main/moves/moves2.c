/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 18:10:06 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/02/26 18:06:39 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_vector *vector, int print, char stack)
{
	int	temp;

	if (print == YES && stack == 'a')
		ft_putstr_fd("sa\n", 1);
	else if (print == YES && stack == 'b')
		ft_putstr_fd("sb\n", 1);
	if (vector->used_size > 1)
	{
		temp = vector->vector[0];
		vector->vector[0] = vector->vector[1];
		vector->vector[1] = temp;
	}
}

void	ss(t_stacks *stacks, int print)
{
	if (print == YES)
		ft_putstr_fd("ss\n", 1);
	sa(&stacks->stack_a, NO, 'a');
	sa(&stacks->stack_b, NO, 'b');
}

void	ra(t_vector *stack_a, int print)
{
	int	first_element;

	if (print == YES)
		ft_putstr_fd("ra\n", 1);
	first_element = stack_a->vector[0];
	pop_stack(stack_a->vector, stack_a->used_size);
	stack_a->vector[stack_a->used_size - 1] = first_element;
}

void	rb(t_vector *stack_b, int print)
{
	int	first_element;

	if (print == YES)
		ft_putstr_fd("rb\n", 1);
	first_element = stack_b->vector[0];
	pop_stack(stack_b->vector, stack_b->used_size);
	stack_b->vector[stack_b->used_size - 1] = first_element;
}

void	rr(t_stacks *stacks, int print)
{
	if (print == YES)
		ft_putstr_fd("rr\n", 1);
	ra(&stacks->stack_a, NO);
	rb(&stacks->stack_b, NO);
}
