/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamooja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:53:41 by osamooja          #+#    #+#             */
/*   Updated: 2019/10/18 18:22:20 by osamooja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int nbr)
{
	int				len;

	len = 0;
	len = (nbr <= 0 ? 1 : 0);
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	unsigned int	nbr;
	int				neg;
	int				len;
	char			*res;

	neg = (n < 0 ? -1 : 0);
	res = 0;
	len = ft_nbrlen(n);
	nbr = (n < 0 ? -n : n);
	if (!(res = (char *)ft_memalloc(sizeof(char) * len + 1)))
		return (NULL);
	res[len--] = '\0';
	while (len >= 0)
	{
		res[len] = nbr % 10 + 48;
		nbr = nbr / 10;
		len--;
	}
	if (neg == -1)
		res[0] = '-';
	return (res);
}
