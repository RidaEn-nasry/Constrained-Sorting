/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:23:56 by ren-nasr          #+#    #+#             */
/*   Updated: 2021/11/16 10:48:43 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Allocates (with malloc()) 
and returns an array  of “fresh” strings 
(all ending with ’\0’, including the array itself) obtained
by spliting s using the character c as a delimiter.
If the allocation fails the function returns NULL. Example:
ft_split("*hello*you**ugly*bag**full*of*mostly**water*", ’*’)
returns the array ["hello", "you", "ugly", "bag", "full","of","mostly", "water"].
*/

static size_t	word_count(char const *s, char c)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	if (s[i] == '\0')
		return (cnt);
	if (s[i] != c)
		cnt = cnt + 1;
	i++;
	while (s[i] != '\0')
	{
		if ((s[i] != c) && (s[i - 1] == c))
			cnt = cnt + 1;
		i = i + 1;
	}
	return (cnt);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	wrd_len;
	size_t	wrd_index;

	if (!s)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!res)
		return (NULL);
	i = 0;
	wrd_index = 0;
	while (s[i] != '\0' && wrd_index < word_count(s, c))
	{
		wrd_len = 0;
		while (s[i] == c)
			i = i + 1;
		while ((s[i + wrd_len] != c) && (s[i + wrd_len] != '\0'))
			wrd_len = wrd_len + 1;
		if (s[i] != '\0')
			res[wrd_index++] = ft_substr(s, i, wrd_len);
		i = i + wrd_len;
	}
	res[wrd_index] = NULL;
	return (res);
}
