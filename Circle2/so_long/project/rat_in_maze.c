/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rat_in_maze.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabah <hakkisabah@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:55:10 by hsabah            #+#    #+#             */
/*   Updated: 2023/02/01 00:19:57 by hsabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
** solution[r][c] = '1' << safe to visit then visit the cell
** and check the cells around it 
** r + 1 going down
** c - 1 going left
** r - 1 going up
** c + 1 going right
** solution[r][c] = '0' backtracking
*/

static int	is_count_limit(t_game *game, int count)
{
	int	calc;

	calc = game->map_height * game->map_width;
	if (count < calc * calc)
		return (1);
	return (0);
}

static int	is_logic_solving(t_game *game, int r, int c, char **solution)
{
	if (r >= 0 && c >= 0 && r < game->map_height && c < game->map_width
		&& solution[r][c] == '0' && game->map[r][c] != 'K'
		&& game->map[r][c] == '0'
		&& is_count_limit(game, count))
		return (1);
	return (0);
}

static int	solvemaze(t_game *game, int r, int c, char **solution)
{
	static int	count;

	count++;
	if (game->map[r][c] == 'E')
	{
		solution[r][c] = '1';
		return (1);
	}
	if (is_logic_solving(game, r, c, solution) && is_count_limit(game, count))
	{
		solution[r][c] = '1';
		if (solvemaze(game, r + 1, c, solution))
			return (1);
		if (solvemaze(game, r, c - 1, solution))
			return (1);
		if (solvemaze(game, r - 1, c, solution))
			return (1);
		if (solvemaze(game, r, c + 1, solution))
			return (1);
		solution[r][c] = '0';
		return (0);
	}
	return (0);
}

/*
** find_path function will find the path from 
** the player position to the exit
** position and will mark the path with '1' in the 
** solution map with solvemaze function when solving 
** starting before set the player position to '0' in the map
** if the path is valid then set the player position to 'P' 
** in the map
*/

void	find_path(t_game *game)
{
	int	player_to_exit;
	int	y;
	int	x;

	y = game->player_y;
	x = game->player_x;
	game->map[game->player_y][game->player_x] = '0';
	player_to_exit = solvemaze(game, y, x, game->solution);
	if (player_to_exit)
	{
		game->map[game->player_y][game->player_x] = 'P';
		free_map(game->solution, game->map_height);
	}
	else
	{
		ft_putstr_fd("Error!\nPath is not valid in the map!\n", 1);
		free_map(game->solution, game->map_height);
		exit(0);
	}
}
