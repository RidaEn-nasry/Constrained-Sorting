/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 18:13:01 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/03/03 13:12:27 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *xp, int *yp)
{
	int	temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}

int	*arr_init(t_stacks *stacks)
{
	int	i;
	int	*sorted_list;

	i = 0;
	sorted_list = malloc(sizeof(int) * stacks->stack_a.size);
	if (!sorted_list)
		exit(err(stacks, "Error\n", EXIT_FAILURE));
	while (i < stacks->stack_a.size)
	{
		sorted_list[i] = stacks->stack_a.vector[i];
		i++;
	}
	return (sorted_list);
}

int	*sort(t_stacks *stacks)
{
	int	i;
	int	j;
	int	min_index;
	int	*sorted_list;

	i = 0;
	sorted_list = arr_init(stacks);
	while (i < stacks->stack_a.size - 1)
	{
		min_index = i;
		j = i + 1;
		while (j < stacks->stack_a.size)
		{
			if (sorted_list[j] < sorted_list[min_index])
				min_index = j;
			j++;
		}
		swap(&sorted_list[min_index], &sorted_list[i]);
		i++;
	}
	return (sorted_list);
}

void	sort_rest(t_stacks *stacks)
{
	if (stacks->stack_a.used_size == 2)
	{
		if (!sorted(&stacks->stack_a))
			sa(&stacks->stack_a, YES, 'a');
	}
	if (stacks->stack_a.used_size == 3)
		three(&stacks->stack_a);
	if (stacks->stack_a.used_size == 5 || stacks->stack_a.used_size == 4)
		five(stacks);
	if (stacks->stack_a.used_size > 5)
		sort_rest_of_numbers(stacks, stacks->stack_a.used_size);
}

void	sort_more_than_hundred(t_stacks *stacks)
{
	if (stacks->stack_a.used_size == 2)
	{
		if (!sorted(&stacks->stack_a))
			sa(&stacks->stack_a, YES, 'a');
	}
	else if (stacks->stack_a.used_size == 3)
		three(&stacks->stack_a);
	else if (stacks->stack_a.used_size == 5 || stacks->stack_a.used_size == 4)
		five(stacks);
	else if (stacks->stack_a.used_size > 5 && stacks->stack_a.used_size <= 10)
		sort_rest_of_numbers(stacks, stacks->stack_a.used_size);
	else if (stacks->stack_a.used_size > 10)
		one_hundred(stacks);
}
