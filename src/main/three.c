/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 16:37:10 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/02/26 18:07:27 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*to_string(char **av)
{
	char	*string;
	char	*tmp;
	int		i;

	i = 1;
	string = malloc(1);
	while (av[i])
	{
		tmp = ft_strjoin(string, av[i]);
		free(string);
		string = ft_strjoin(tmp, " ");
		free(tmp);
		i++;
	}
	return (string);
}

void	three(t_vector *stack_a)
{
	int	*tmp;

	tmp = stack_a->vector;
	if (sorted(stack_a))
		return ;
	if (tmp[0] > tmp[1] && tmp[0] < tmp[2])
		sa(stack_a, YES, 'a');
	else if (tmp[0] > tmp[1] && tmp[1] > tmp[2])
	{
		sa(stack_a, YES, 'a');
		rra(stack_a, YES);
	}
	else if (tmp[0] > tmp[2] && tmp[2] > tmp[1])
		ra(stack_a, YES);
	else if (tmp[2] > tmp[0] && tmp[1] > tmp[2])
	{
		sa(stack_a, YES, 'a');
		ra(stack_a, YES);
	}
	else if (tmp[0] > tmp[2] && tmp[1] > tmp[0])
		rra(stack_a, YES);
}
