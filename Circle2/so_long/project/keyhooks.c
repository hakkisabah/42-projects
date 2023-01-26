/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabah <hakkisabah@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:34:01 by hsabah            #+#    #+#             */
/*   Updated: 2023/01/26 01:19:27 by hsabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_movements(t_game *game)
{
	ft_putstr_fd("Total moves -> ", 1);
	ft_putnbr_fd(game->moves_total, 1);
	ft_putstr_fd("\n", 1);
}

void	ft_put_display(t_program *program)
{
	mlx_string_put(program->mlx, program->window.reference,
		ANIMATION_FRAMES * program->window.game.map_width * (0.84), 10, 0x80000,
		"Movements: ");
	mlx_string_put(program->mlx, program->window.reference,
		ANIMATION_FRAMES * program->window.game.map_width * (0.84), 10, 0x80000,
		ft_itoa(program->window.game.moves_total));
}

void	ft_is_move(t_program *program, int is_move, int is_bonus)
{
	if (is_move)
	{
		program->window.game.moves_total++;
		if (is_bonus)
			ft_put_display(program);
		else
			ft_put_movements(&program->window.game);
	}
}

int	ft_movements_keyhooks(int key, t_program *program, int is_bonus)
{
	int		y;
	int		x;
	char	**curr_map;
	int		is_move;

	is_move = 0;
	y = program->window.game.player_y;
	x = program->window.game.player_x;

	curr_map = program->window.game.map;
	if (key == 100 && ft_map_availability(curr_map, y, x + 1, program)) /* RIGHT */ 
		is_move = ft_redirect_player(&curr_map[y][x], &curr_map[y][x + 1]);
	else if (key == 97 && ft_map_availability(curr_map, y, x - 1, program)) /* LEFT */
		is_move = ft_redirect_player(&curr_map[y][x], &curr_map[y][x - 1]);
	else if (key == 115 && ft_map_availability(curr_map, y + 1, x, program)) /* DOWN */
		is_move = ft_redirect_player(&curr_map[y][x], &curr_map[y + 1][x]);
	else if (key == 119 && ft_map_availability(curr_map, y - 1, x, program)) /* UP */
		is_move = ft_redirect_player(&curr_map[y][x], &curr_map[y - 1][x]);
	ft_is_move(program, is_move, is_bonus);
	return (0);
}