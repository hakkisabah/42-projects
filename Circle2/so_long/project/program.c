/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabah <hakkisabah@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:21:06 by hsabah            #+#    #+#             */
/*   Updated: 2023/01/30 22:02:05 by hsabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_struct(t_program *program, int is_bonus)
{
	program->window.game.map_width = 0;
	program->window.game.map_height = 0;
	program->window.game.collectibles = 0;
	program->window.game.exit = 0;
	program->window.game.player = 0;
	program->window.game.player_x = 0;
	program->window.game.player_y = 0;
	program->window.game.moves_total = 0;
	program->is_bonus = is_bonus;
}

void	define_frames(t_program *program)
{
	program->window.game.frames.P = ft_img(program->mlx, "./textures/player.xpm");
	program->window.game.frames.C = ft_img(program->mlx, "./textures/collectible.xpm");
	program->window.game.frames.E = ft_img(program->mlx, "./textures/exit.xpm");
	program->window.game.frames.W = ft_img(program->mlx, "./textures/wall.xpm");
	program->window.game.frames.F = ft_img(program->mlx, "./textures/floor.xpm");
	if (program->is_bonus)
	{
		program->window.game.frames.K = ft_img(program->mlx, "./textures/enemy.xpm");
	}
}

void	ft_reset_program(t_program program)
{
	free(program.mlx);
	free(program.window.reference);
	free(program.window.game.frames.P.pixels);
	free(program.window.game.frames.C.pixels);
	free(program.window.game.frames.E.pixels);
	free(program.window.game.frames.W.pixels);
	free(program.window.game.frames.F.pixels);
	free(program.window.game.frames.K.pixels); 
	free_map(program.window.game.map, program.window.game.map_height);
	ft_close(&program);
}