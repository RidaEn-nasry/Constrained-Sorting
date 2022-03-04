/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 20:55:13 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/03/03 13:14:52 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**init(char *string, t_stacks *stacks)
{
	int		size;
	char	**numbers;

	numbers = ft_split(string, ' ');
	size = count(string);
	stacks->stack_a.vector = malloc(sizeof(int) * size);
	stacks->stack_b.vector = malloc(sizeof(int) * size);
	if (!stacks->stack_a.vector || !stacks->stack_b.vector)
		exit(err(stacks, "Error\n", EXIT_FAILURE));
	stacks->stack_a.size = size;
	stacks->stack_b.size = size;
	stacks->stack_a.used_size = 0;
	stacks->stack_b.used_size = 0;
	free(string);
	return (numbers);
}

t_stacks	init_stacks(char *string)
{
	t_stacks			stacks;
	char				**numbers;
	int					number;
	int					i;

	i = 0;
	numbers = init(string, &stacks);
	while (numbers[i])
	{
		if (!is_number(numbers[i]))
			exit(err(&stacks, "Error\n", EXIT_FAILURE));
		number = convert(numbers[i], &stacks);
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
