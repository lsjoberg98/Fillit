/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsjoberg <lsjoberg@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 10:59:33 by osamooja          #+#    #+#             */
/*   Updated: 2020/02/28 18:00:07 by lsjoberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**		Checks for invalid characters from input
**		Checks for wrong-length lines and/or '\n in an invalid position
**		Count the number of '#' characters
**		Checks for '\n at end of piece block
**		Returns (count) if everything goes fine, if not return (0)
*/

int		charcount(char *buf)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (i < 19)
	{
		if (buf[i] && buf[i] != '\n' && buf[i] != '#' && buf[i] != '.')
			return (0);
		if (buf[i] == '\n' && !(((i + 1) % 5) == 0))
			return (0);
		if (buf[i] == '#')
			count++;
		i++;
	}
	if (!buf[i] || buf[i] != '\n')
		return (0);
	return (count);
}

/*
**		Checks each '#' character to see if its adjacent to another '#'
**		Return (count) of these adjancies to validate piece shape
**		A valid piece with 4 '#' characters will either have 6 or 8 adjacencies
*/

int		adjacent(char *buf)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (i < 19)
	{
		if (buf[i] == '#')
		{
			if (i + 1 <= 18 && buf[i + 1] == '#')
				count++;
			if (i - 1 >= 0 && buf[i - 1] == '#')
				count++;
			if (i + 5 <= 18 && buf[i + 5] == '#')
				count++;
			if (i - 5 >= 0 && buf[i - 5] == '#')
				count++;
		}
		i++;
	}
	return (count);
}

/*
**		Goes through buf 21 char (one piece of chunk) at a time
**		Buf is 21 because that the max that can be in one valid block
**		Calls checking functions to confirm validity
**		Returns (1) if everything goes fine, if not return (0)
*/

int		validation(char *buf, int size)
{
	int		i;

	i = 0;
	while (i <= size)
	{
		if (charcount(buf + i) != 4)
			return (0);
		if (adjacent(buf + i) != 6 && adjacent(buf + i) != 8)
			return (0);
		i += 21;
	}
	return (1);
}
