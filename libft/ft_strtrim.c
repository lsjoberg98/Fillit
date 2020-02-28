/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamooja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:54:49 by osamooja          #+#    #+#             */
/*   Updated: 2019/10/19 13:35:03 by osamooja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	min;
	size_t	max;

	min = 0;
	if (!s)
		return (NULL);
	while (ft_is_tsn(s[min]))
		min++;
	max = ft_strlen(s);
	while (ft_is_tsn(s[max - 1]))
		max--;
	if (max < min)
		max = min;
	return (ft_strsub(s, min, max - min));
}
