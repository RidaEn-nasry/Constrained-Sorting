/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 18:11:59 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/02/26 11:08:10 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_vector *stack_a, int print)
{
	int	last_element;

	if (print == YES)
		ft_putstr_fd("rra\n", 1);
	last_element = stack_a->vector[stack_a->used_size - 1];
	ft_push_stack(stack_a->vector, stack_a->used_size);
	stack_a->vector[0] = last_element;
}

void	rrb(t_vector *stack_b, int print)
{
	int	last_element;

	if (print == YES)
		ft_putstr_fd("rrb\n", 1);
	last_element = stack_b->vector[stack_b->used_size - 1];
	ft_push_stack(stack_b->vector, stack_b->used_size);
	stack_b->vector[0] = last_element;
}

void	rrr(t_stacks *stacks, int print)
{
	if (print == YES)
		ft_putstr_fd("rrr\n", 1);
	rra(&stacks->stack_a, NO);
	rrb(&stacks->stack_b, NO);
}
