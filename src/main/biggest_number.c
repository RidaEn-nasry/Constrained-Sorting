/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 18:14:55 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/02/26 13:02:12 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_rest_of_numbers(t_stacks *stacks, int size)
{
	if (!sorted(&stacks->stack_a))
	{
		while (stacks->stack_a.used_size >= 5)
		{
			least_ten(stacks);
			pb(stacks, YES);
		}
		five(stacks);
		while (stacks->stack_a.used_size != size)
			pa(stacks, YES);
	}
}

int	divide(int *sorted_list, int size, int divided, int chunks)
{
	int	key_munber;

	key_munber = sorted_list[(size * divided) / chunks];
	return (key_munber);
}

int	biggest_index(t_vector *stack_b)
{
	int	i;
	int	b_index;

	i = 0;
	b_index = i;
	while (i < stack_b->used_size)
	{
		if (stack_b->vector[b_index] < stack_b->vector[i])
			b_index = i;
		i++;
	}
	return (b_index);
}

void	biggest_number(t_stacks *stacks)
{
	int	b_index;

	b_index = biggest_index(&stacks->stack_b);
	while (b_index != 0)
	{
		if (b_index <= (stacks->stack_b.used_size / 2))
			rb(&stacks->stack_b, YES);
		else
			rrb(&stacks->stack_b, YES);
		b_index = biggest_index(&stacks->stack_b);
	}
}
