/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_hundred.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:14:10 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/03/03 13:07:05 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//The non-reduciblity nature of computations 

void	move_to_top(t_stacks *stacks, int index)
{
	int	divid;

	divid = stacks->stack_a.used_size / 2;
	while (index != 0)
	{
		if (index <= divid)
		{
			ra(&stacks->stack_a, YES);
			index--;
		}
		else
		{
			rra(&stacks->stack_a, YES);
			index++;
			if (index == stacks->stack_a.used_size)
				break ;
		}
	}
}

int	search_index(t_stacks *stacks, int key_number)
{
	int	i;

	i = 0;
	while (i < stacks->stack_a.used_size)
	{
		if (stacks->stack_a.vector[i] <= key_number)
			return (i);
		i++;
	}
	return (-1);
}

void	push_index(t_stacks *stacks, int key_number)
{
	int	index;

	index = search_index(stacks, key_number);
	while (index != -1)
	{
		move_to_top(stacks, index);
		pb(stacks, YES);
		index = search_index(stacks, key_number);
	}
}

void	one_hundred(t_stacks *stacks)
{
	int	i;
	int	key_number;
	int	*sorted_list;

	i = 1;
	sorted_list = sort(stacks);
	while (i != 4)
	{
		key_number = divide(sorted_list, stacks->stack_a.size, i, 4);
		push_index(stacks, key_number);
		i++;
	}
	free(sorted_list);
	sort_rest(stacks);
	while (stacks->stack_b.used_size != 0)
	{
		biggest_number(stacks);
		pa(stacks, YES);
	}
}

void	five_hundred(t_stacks *stacks)
{
	int	i;
	int	key_number;
	int	*sorted_list;

	i = 1;
	sorted_list = sort(stacks);
	while (i != 12)
	{
		key_number = divide(sorted_list, \
			stacks->stack_a.size, i, 12);
		push_index(stacks, key_number);
		i++;
	}
	free(sorted_list);
	sort_more_than_hundred(stacks);
	while (stacks->stack_b.used_size != 0)
	{
		biggest_number(stacks);
		pa(stacks, YES);
	}
}
