/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 17:07:55 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/02/26 17:23:41 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stacks	stacks;
	char		*string;

	ac--;
	if (ac == 0)
		return (0);
	string = to_string(av);
	stacks = init_stacks(string);
	if (sorted(&stacks.stack_a))
		return (err(&stacks, NULL, 0));
	if (stacks.stack_a.size == 2)
		sa(&stacks.stack_a, YES, 'a');
	if (stacks.stack_a.size == 3)
		three(&stacks.stack_a);
	if (stacks.stack_a.size == 5 || stacks.stack_a.size == 4)
		five(&stacks);
	if (stacks.stack_a.size > 5 && stacks.stack_a.size <= 10)
		ten(&stacks);
	if (stacks.stack_a.size > 10 && stacks.stack_a.size <= 100)
		one_hundred(&stacks);
	if (stacks.stack_a.size > 100)
		five_hundred(&stacks);
	return (err(&stacks, NULL, 0));
}
