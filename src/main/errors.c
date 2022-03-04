/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 20:17:07 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/03/03 13:14:39 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	convert(const char *str, t_stacks *stacks)
{
	int					sign;
	long long			result;
	int					i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] && (str[i] == '\f' || str[i] == '\t' || str[i] == ' ' \
		|| str[i] == '\n' || str[i] == '\r' || str[i] == '\v'))
			i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
				sign = -1;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
			result *= 10;
			result += str[i++] - '0';
	}
		result *= sign;
	if (result > INT_MAX || result < INT_MIN)
		exit(err(stacks, "Error\n", EXIT_FAILURE));
	return (result);
}

int	is_number(char *number)
{
	int	i;

	i = 0;
	if (number[i] == '-')
		i++;
	while (number[i])
	{
		if (!ft_isdigit(number[i]))
			return (0);
		i++;
	}
	return (1);
}

int	duplicate(t_stacks *stacks, int number)
{
	int	size;
	int	i;

	i = 0;
	size = stacks->stack_a.used_size;
	if (size == 0)
		return (1);
	while (i < size)
	{
		if (stacks->stack_a.vector[i] == number)
			return (0);
		i++;
	}
	return (1);
}

int	sorted(t_vector *vector)
{
	int	i;
	int	*tmp;

	i = 0;
	tmp = vector->vector;
	while (i < vector->used_size - 1)
	{
		if (tmp[i] > tmp[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	err(t_stacks *stacks, char *message, int ret)
{
	if (stacks)
	{
		if (stacks->stack_a.vector)
			free(stacks->stack_a.vector);
		if (stacks->stack_b.vector)
			free(stacks->stack_b.vector);
	}
	if (message != NULL)
		ft_putstr_fd(message, 2);
	return (ret);
}
