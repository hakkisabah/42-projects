/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabah <hakkisabah@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 01:40:52 by hsabah            #+#    #+#             */
/*   Updated: 2023/01/26 01:42:52 by hsabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_struct(t_game *game)
{
	game->map_width = 0;
	game->map_height = 0;
	game->collectibles = 0;
	game->exit = 0;
	game->player = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->moves_total = 0;
}

void	define_frames(void *mlx, t_frames *frames)
{
	frames->P = ft_img(mlx, "./textures/player.xpm");
	frames->C = ft_img(mlx, "./textures/collectible.xpm");
	frames->E = ft_img(mlx, "./textures/exit.xpm");
	frames->W = ft_img(mlx, "./textures/wall.xpm");
	frames->F = ft_img(mlx, "./textures/floor.xpm");
	// frames->K = ft_img(mlx, "./textures/enemy.xpm");
}

int	main(int argc, char **argv)
{
	t_program program;

	ft_check_arg(argc, argv);
	ft_init_struct(&program.window.game);
	ft_validate_map(argv, &program.window.game);
    program.mlx = mlx_init();
    program.window = ft_new_window(&program, "So Long");
	define_frames(program.mlx, &program.window.game.frames);

	mlx_hook(program.window.reference, 2, 1L << 0, *ft_input, &program); // 1L << 0 KeyPressMask
	mlx_hook(program.window.reference, 17, 1L << 5, ft_close, &program); // 1L << 5 WindowLeaveMask
	mlx_loop_hook(program.mlx, *ft_update, &program);
	mlx_loop(program.mlx);
	exit(0);
    return (0);
}