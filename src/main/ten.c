/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ten.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:57:59 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/02/26 18:08:38 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	least_ten(t_stacks *stacks)
{
	int	s_index;

	s_index = least_index(&stacks->stack_a);
	while (s_index != 0)
	{
		if (s_index <= 5)
			ra(&stacks->stack_a, YES);
		else
			rra(&stacks->stack_a, YES);
		s_index = least_index(&stacks->stack_a);
	}
}

void	ten(t_stacks *stacks)
{
	if (!sorted(&stacks->stack_a))
	{
		while (stacks->stack_a.used_size != 5)
		{
			least_ten(stacks);
			pb(stacks, YES);
		}
		five(stacks);
		while (stacks->stack_a.used_size != stacks->stack_a.size)
			pa(stacks, YES);
	}
}
