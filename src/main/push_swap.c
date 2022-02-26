/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 20:55:13 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/02/26 13:28:33 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	overflow(char *num)
{
	char	*int_max;
	int		i;

	i = 0;
	int_max = "2147483647";
	if (ft_strlen(num) > 10)
		return (1);
	if (ft_strlen(num) == 10)
	{
		while (i < 11)
		{
			if (num[i] > int_max[i])
				return (1);
			i++;
		}
	}
	return (0);
}

int	underflow(char *num)
{
	char	*int_min;
	int		i;

	i = 1;
	int_min = "-2147483648";
	if (ft_strlen(num) > 11)
		return (1);
	if (ft_strlen(num) == 11)
	{
		while (i < 12)
		{
			if (num[i] < int_min[i])
				return (1);
			i++;
		}
	}
	return (0);
}

char	**init(char *string, t_stacks *stacks)
{
	int		size;
	char	**numbers;

	numbers = ft_split(string, ' ');
	size = count(string);
	stacks->stack_a.vector = malloc(sizeof(int) * size);
	stacks->stack_b.vector = malloc(sizeof(int) * size);
	stacks->stack_a.size = size;
	stacks->stack_b.size = size;
	stacks->stack_a.used_size = 0;
	stacks->stack_b.used_size = 0;
	free(string);
	return (numbers);
}

void	validate(char *numbers, t_stacks *stacks)
{
	if (!is_number(numbers))
		exit(err(stacks, "Error not a number\n", 0));
	if (numbers[0] == '-')
	{
		if (underflow(numbers))
			exit(err(stacks, "Error\n", EXIT_FAILURE));
	}
	else
	{
		if (overflow(numbers))
			exit(err(stacks, "Error\n", EXIT_FAILURE));
	}
}

t_stacks	init_stacks(char *string)
{
	t_stacks			stacks;
	char				**numbers;
	long long			number;
	int					i;

	i = 0;
	numbers = init(string, &stacks);
	while (numbers[i])
	{
		validate(numbers[i], &stacks);
		number = ft_atoi(numbers[i]);
		if (!duplicate(&stacks, number))
			exit(err(&stacks, "Error\n", 1));
		stacks.stack_a.vector[i] = number;
		stacks.stack_a.used_size++;
		free(numbers[i]);
		i++;
	}
	free(numbers);
	return (stacks);
}
