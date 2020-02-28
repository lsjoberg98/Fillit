/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsjoberg <lsjoberg@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 14:21:12 by lsjoberg          #+#    #+#             */
/*   Updated: 2020/02/28 18:00:05 by lsjoberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**		Check if overlaps with previous pieces.
*/

int		overlap(t_map *map, t_piece *piece)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	x = piece->tetrimino[i] + piece->x_offset;
	y = piece->tetrimino[i + 1] + piece->y_offset;
	while (i <= 6 && map->array[y][x] == '.')
	{
		i += 2;
		x = piece->tetrimino[i] + piece->x_offset;
		y = piece->tetrimino[i + 1] + piece->y_offset;
	}
	return (i != 8);
}

/*
**		Can either place the piece or place '.' to clear a piece.
*/

void	place(t_piece *piece, t_map *map, char letter)
{
	int	i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	while (i <= 6)
	{
		x = piece->tetrimino[i] + piece->x_offset;
		y = piece->tetrimino[i + 1] + piece->y_offset;
		map->array[y][x] = letter;
		i += 2;
	}
}

/*
**		Check if coordinates in bounds with map.
*/

int		in_bounds(t_piece *piece, int map_size, char axis)
{
	if (axis == 'y')
		return (piece->tetrimino[1] + piece->y_offset < map_size &&
				piece->tetrimino[3] + piece->y_offset < map_size &&
				piece->tetrimino[5] + piece->y_offset < map_size &&
				piece->tetrimino[7] + piece->y_offset < map_size);
	else
		return (piece->tetrimino[0] + piece->x_offset < map_size &&
				piece->tetrimino[2] + piece->x_offset < map_size &&
				piece->tetrimino[4] + piece->x_offset < map_size &&
				piece->tetrimino[6] + piece->x_offset < map_size);
}

/*
**		Use recursion to check if the pieces fit.
**		If not it backtracks and moves current piece.
*/

int		solve_map(t_map *map, t_piece *piece, int map_size)
{
	if (!piece)
		return (1);
	piece->x_offset = 0;
	piece->y_offset = 0;
	while (in_bounds(piece, map_size, 'y'))
	{
		while (in_bounds(piece, map_size, 'x'))
		{
			if (!overlap(map, piece))
			{
				place(piece, map, piece->pieceletter);
				if (solve_map(map, piece->next, map_size))
					return (1);
				else
				{
					place(piece, map, '.');
				}
			}
			piece->x_offset++;
		}
		piece->x_offset = 0;
		piece->y_offset++;
	}
	return (0);
}

/*
**		Make map and start solving.
*/

void	solve(t_piece *piecelist)
{
	t_map	*map;
	int		map_size;

	map_size = make_map_size(count_pieces(piecelist) * 4);
	map = new_map(map_size);
	while (!solve_map(map, piecelist, map_size))
	{
		free_map(map, map_size);
		map_size++;
		map = new_map(map_size);
	}
	print_map(map, map_size);
	free_map(map, map_size);
}
