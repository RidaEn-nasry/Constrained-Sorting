/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 09:33:30 by ren-nasr          #+#    #+#             */
/*   Updated: 2021/11/15 20:22:06 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Convert int into a string */

static char	*ft_int_to_str(char *res, size_t number, size_t len)
{
	while (number > 0)
	{
		res[len--] = 48 + (number % 10);
		number = number / 10;
	}
	return (res);
}

static size_t	ft_int_len(int n)
{
	size_t					len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char				*res;
	size_t				len;
	unsigned long long	number;
	int					sign;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	sign = 1;
	len = ft_int_len(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!(res))
		return (NULL);
	res[len--] = '\0';
	if (n == 0)
		res[0] = '0';
	if (n < 0)
	{
		sign *= -1;
		number = n * -1;
		res[0] = '-';
	}
	else
		number = n;
	res = ft_int_to_str(res, number, len);
	return (res);
}
