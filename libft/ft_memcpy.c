/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamooja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 12:13:37 by osamooja          #+#    #+#             */
/*   Updated: 2019/10/18 16:27:46 by osamooja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*x;
	const char	*y;

	x = dest;
	y = src;
	if (!n || dest == src)
		return (dest);
	while (n)
	{
		*x = *y;
		x++;
		y++;
		n--;
	}
	return (dest);
}
