/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamooja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 17:43:06 by osamooja          #+#    #+#             */
/*   Updated: 2019/10/19 15:37:09 by osamooja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static	int	ft_countwords(char const *str, char c)
{
	size_t	count;
	int		inside_a_word;

	inside_a_word = 0;
	count = 0;
	while (*str)
	{
		if (!inside_a_word && *str != c)
			count++;
		inside_a_word = (*str == c) ? 0 : 1;
		str++;
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**a;
	size_t	inside_a_word;
	size_t	word_index;
	size_t	i;
	size_t	start;

	if (!s)
		return (NULL);
	if (!(a = (char **)ft_memalloc((ft_countwords(s, c) + 1) * sizeof(char *))))
		return (NULL);
	word_index = 0;
	inside_a_word = 0;
	i = -1;
	start = 0;
	while (s[++i])
	{
		if (inside_a_word && s[i] == c)
			a[word_index++] = ft_strsub(s, start, i - start);
		if (!inside_a_word && s[i] != c)
			start = i;
		inside_a_word = (s[i] == c) ? 0 : 1;
	}
	if (inside_a_word)
		a[word_index] = ft_strsub(s, start, i - start);
	return (a);
}
