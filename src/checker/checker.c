/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:55:47 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/02/26 18:14:57 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/push_swap.h"
#include "../utils/get_next_line/get_next_line.h"

int	apply_instruc_3(t_stacks *stack, char *instruc)
{
	if (!ft_strncmp(instruc, "sa\n", ft_strlen(instruc)))
	{
		sa(&stack->stack_a, NO, 'a');
		return (0);
	}
	else if (!ft_strncmp(instruc, "sb\n", ft_strlen(instruc)))
	{
		sa(&stack->stack_b, NO, 'b');
		return (0);
	}
	else if (!ft_strncmp(instruc, "ss\n", ft_strlen(instruc)))
	{
		ss(stack, NO);
		return (0);
	}
	return (1);
}

int	apply_instruc_2(t_stacks *stack, char *instruc)
{
	if (!ft_strncmp(instruc, "rb\n", ft_strlen(instruc)))
	{
		rb(&stack->stack_b, NO);
		return (0);
	}
	else if (!ft_strncmp(instruc, "rr\n", ft_strlen(instruc)))
	{
		rr(stack, NO);
		return (0);
	}
	else if (!ft_strncmp(instruc, "pa\n", ft_strlen(instruc)))
	{
		pa(stack, NO);
		return (0);
	}
	else if (!ft_strncmp(instruc, "pb\n", ft_strlen(instruc)))
	{
		pb(stack, NO);
		return (0);
	}
	return (1);
}

int	apply_instruc(t_stacks *stack, char *instruc)
{
	if (!ft_strncmp(instruc, "rra\n", ft_strlen(instruc)))
	{
		rra(&stack->stack_a, NO);
		return (0);
	}
	else if (!ft_strncmp(instruc, "rrb\n", ft_strlen(instruc)))
	{
		rrb(&stack->stack_b, NO);
		return (0);
	}
	else if (!ft_strncmp(instruc, "rrr\n", ft_strlen(instruc)))
	{
		rrr(stack, NO);
		return (0);
	}
	else if (!ft_strncmp(instruc, "ra\n", ft_strlen(instruc)))
	{
		ra(&stack->stack_a, NO);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stacks	stack;
	char		*string;
	char		*read;

	string = to_string(argv);
	stack = init_stacks(string);
	if (argc <= 2)
		return (0);
	read = get_next_line(0);
	while (read)
	{
		if (apply_instruc(&stack, read) && apply_instruc_2(&stack, read) \
			&& apply_instruc_3(&stack, read))
			exit(err(&stack, "Error\n", EXIT_FAILURE));
		read = get_next_line(0);
	}
	if (sorted(&stack.stack_a))
		ft_putstr_fd("Ok\n", 1);
	else
		ft_putstr_fd("Ko\n", 2);
	return (0);
}
