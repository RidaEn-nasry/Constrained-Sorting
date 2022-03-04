/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 20:54:59 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/03/03 13:07:28 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>

# include "../utils/libft/libft.h"
# define GREEN "\e[1;32m"
# define RESET "\e[0m"
# define RED "\e[1;91m"
# define CYAN "\e[1;36m"
# define YES 1
# define NO 0

typedef struct s_vector
{
	int	*vector;
	int	size;
	int	used_size;
}				t_vector;

typedef struct s_stacks
{
	t_vector	stack_a;
	t_vector	stack_b;
}				t_stacks;

void		sort_rest_of_numbers(t_stacks *stacks, int size);
int			biggest_index(t_vector *stack_b);
void		biggest_number(t_stacks *stacks);
int			least_index(t_vector *stack_a);
void		least_number(t_stacks *stacks);
void		five(t_stacks *stacks);
int			search_index(t_stacks *stacks, int key_number);
void		move_to_top(t_stacks *stacks, int index);
void		push_index(t_stacks *stacks, int key_number);
void		one_hundred(t_stacks *stacks);
void		five_hundred(t_stacks *stacks);
void		ft_push_stack(int *vector, int used_size);
void		pop_stack(int *vector, int used_size);
void		pa(t_stacks *stacks, int print);
void		pb(t_stacks *stacks, int print);
void		rra(t_vector *stack_a, int print);
void		rrb(t_vector *stack_b, int print);
void		rrr(t_stacks *stacks, int print);
void		sa(t_vector *vector, int print, char stack);
void		ss(t_stacks *stacks, int print);
void		ra(t_vector *stack_a, int print);
void		rb(t_vector *stack_b, int print);
void		rr(t_stacks *stacks, int print);
void		swap(int *xp, int *yp);
int			*arr_init(t_stacks *stacks);
int			*sort(t_stacks *stacks);
void		sort_rest(t_stacks *stacks);
void		sort_more_than_hundred(t_stacks *stacks);
void		least_ten(t_stacks *stacks);
void		ten(t_stacks *stacks);
void		three(t_vector *stack_a);
int			is_number(char *number);
int			duplicate(t_stacks *stacks, int number);
int			sorted(t_vector *vector);
int			count(char *string);
int			err(t_stacks *stacks, char *message, int ret);
char		**init(char *string, t_stacks *stacks);
t_stacks	init_stacks(char *string);
int			length(char **av);
char		*to_string(char **av);
int			divide(int *sorted_list, int size, int divided, int chunks);
long long	convert(const char *str, t_stacks *stacks);
// int			underflow(char *num);
// int			overflow(char *num);

#endif