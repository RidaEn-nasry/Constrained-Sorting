/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 17:07:09 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/02/26 18:07:54 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	least_index(t_vector *stack_a)
{
	int	i;
	int	s_index;

	i = 0;
	s_index = i;
	while (i < stack_a->used_size)
	{
		if (stack_a->vector[s_index] > stack_a->vector[i])
			s_index = i;
		i++;
	}
	return (s_index);
}

void	least_number(t_stacks *stacks)
{
	int	s_index;

	s_index = least_index(&stacks->stack_a);
	while (s_index != 0)
	{
		if (s_index <= 2)
			ra(&stacks->stack_a, YES);
		else
			rra(&stacks->stack_a, YES);
		s_index = least_index(&stacks->stack_a);
	}
}

void	five(t_stacks *stacks)
{
	int	i;

	i = 0;
	if (!sorted(&stacks->stack_a))
	{
		if (stacks->stack_a.used_size == 5)
		{
			least_number(stacks);
			pb(stacks, YES);
			i++;
		}
		if (stacks->stack_a.used_size == 4)
		{
			least_number(stacks);
			pb(stacks, YES);
			i++;
		}
		three(&stacks->stack_a);
		while (i > 0)
		{
			pa(stacks, YES);
			i--;
		}
	}
}
