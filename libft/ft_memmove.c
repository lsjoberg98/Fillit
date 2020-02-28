/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamooja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:56:14 by osamooja          #+#    #+#             */
/*   Updated: 2019/10/18 16:31:51 by osamooja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*x;
	char	*y;
	size_t	i;

	i = 0;
	x = (char *)dst;
	y = (char *)src;
	if (y < x)
	{
		while (len)
		{
			len--;
			*(x + len) = *(y + len);
		}
	}
	else
		ft_memcpy(x, y, len);
	return (dst);
}
