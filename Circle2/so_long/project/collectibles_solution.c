/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles_solution.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabah <hakkisabah@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:55:10 by hsabah            #+#    #+#             */
/*   Updated: 2023/02/01 00:19:57 by hsabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_solved(t_game *game, int y, int x, char **v_map)
{
	char	**s_map;

	if (v_map[y][x] == 'C')
	{
		s_map = set_solution_map_to_zero(game);
		v_map[y][x] = '0';
		if (!solvemaze(game, y, x, s_map))
		{
			free_map(v_map, game->map_height);
			free_map(s_map, game->map_height);
			return (0);
		}
		else
		{
			free_map(s_map, game->map_height);
		}
	}
	return (1);
}

int	access_to_collectibles(t_game *game, char **v_map)
{
	int	y;
	int	x;
	int	coll;

	coll = game->collectibles;
	y = 1;
	while (y < game->map_height)
	{
		x = 1;
		while (x < game->map_width)
		{
			if (!is_solved(game, y, x, v_map))
				return (0);
			coll--;
			x++;
		}
		if (coll == 0)
		{
			free_map(v_map, game->map_height);
			return (1);
		}
		y++;
	}
	free_map(v_map, game->map_height);
	return (1);
}
