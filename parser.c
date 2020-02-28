/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsjoberg <lsjoberg@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:12:30 by osamooja          #+#    #+#             */
/*   Updated: 2020/02/28 17:59:58 by lsjoberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**		Free list one piece at a time.
*/

void		free_piecelist(t_piece *list)
{
	t_piece *tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

/*
**		Align pieces to upper-left corner.
*/

t_piece		*align(t_piece *piece)
{
	while (piece->tetrimino[0] != 0 && \
			piece->tetrimino[2] != 0 && \
			piece->tetrimino[4] != 0 && \
			piece->tetrimino[6] != 0)
		shift_x(piece);
	while (piece->tetrimino[1] != 0 && \
			piece->tetrimino[3] != 0 && \
			piece->tetrimino[5] != 0 && \
			piece->tetrimino[7] != 0)
		shift_y(piece);
	return (piece);
}

/*
**		Find & store coordinates of '#' characters.
*/

t_piece		*makepiece(char *buf, char pieceletter)
{
	t_piece	*piece_ptr;
	int		x;
	int		y;
	int		i;

	i = 0;
	x = 0;
	y = 1;
	if (!(piece_ptr = (t_piece*)malloc(sizeof(t_piece))))
		return (NULL);
	while (i < 20)
	{
		if (buf[i] == '#')
		{
			piece_ptr->tetrimino[x] = (i >= 5) ? (i % 5) : i;
			piece_ptr->tetrimino[y] = i / 5;
			x += 2;
			y += 2;
		}
		i++;
	}
	piece_ptr->x_offset = 0;
	piece_ptr->y_offset = 0;
	piece_ptr->pieceletter = pieceletter;
	return (align(piece_ptr));
}

/*
**		Linked list of piece structs.
*/

t_piece		*makelist(char *buf, int size)
{
	t_piece *current;
	t_piece *beginning;
	int		i;
	char	pieceletter;

	i = 0;
	pieceletter = 'A';
	while (i < size)
	{
		if (pieceletter == 'A')
		{
			beginning = makepiece(buf + i, pieceletter);
			current = beginning;
		}
		else
		{
			current->next = makepiece(buf + i, pieceletter);
			current = current->next;
		}
		pieceletter++;
		i += 21;
	}
	current->next = NULL;
	return (beginning);
}

/*
**		Opens & reads file into a buffer.
*/

t_piece		*parser(char *filename)
{
	char	buf[545];
	int		fd;
	int		bytesread;

	fd = open(filename, O_RDONLY);
	bytesread = read(fd, buf, 545);
	close(fd);
	if (bytesread > 544 || bytesread < 19)
		return (NULL);
	buf[bytesread] = '\0';
	if (!validation(buf, bytesread))
		return (NULL);
	return (makelist(buf, bytesread));
}
