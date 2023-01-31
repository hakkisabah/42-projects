/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabah <hakkisabah@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:00:40 by hsabah            #+#    #+#             */
/*   Updated: 2023/02/01 00:02:33 by hsabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	ft_img(void *mlx, char *path)
{
	t_image img;
	
	img.reference = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.pixels  = mlx_get_data_addr(img.reference, &img.bits_per_pixel, &img.line_size, &img.endian);
	return (img);
}

/*
** ft_put_common function put all images except player
*/

static void	ft_put_common(void *mlx,t_window *window, void *frame)
{
	int position_x;
	int position_y;

	position_x = window->game.frame_position.x * ANIMATION_FRAMES;
	position_y = window->game.frame_position.y * ANIMATION_FRAMES;
	mlx_put_image_to_window (mlx, window->reference,
		frame, position_x, position_y);
}

/*
** ft_put_player function put the player image
** also it saves the player position in the game structure current position
*/

static void	ft_put_player(void *mlx,t_window *window)
{
	int position_x;
	int position_y;

	position_x = window->game.frame_position.x * ANIMATION_FRAMES;
	position_y = window->game.frame_position.y * ANIMATION_FRAMES;
	window->game.player_x = window->game.frame_position.x;
	window->game.player_y = window->game.frame_position.y;
	mlx_put_image_to_window (mlx, window->reference,
		window->game.frames.P.reference, position_x, position_y);
}

void	ft_fill_window(void *mlx, t_window *window, int is_bonus)
{
	char map_pixel;

	window->game.frame_position.y = 0;
	while (window->game.frame_position.y < window->game.map_height)
	{
		window->game.frame_position.x = 0;
		while (window->game.frame_position.x < window->game.map_width)
		{
			map_pixel = window->game.map[window->game.frame_position.y][window->game.frame_position.x];
			if (map_pixel == '1')
				ft_put_common(mlx, window, window->game.frames.W.reference);
			if (map_pixel == 'P')
				ft_put_player(mlx, window);
			if (map_pixel == 'C')
				ft_put_common(mlx, window, window->game.frames.C.reference);
			if (map_pixel == 'E')
				ft_put_common(mlx, window, window->game.frames.E.reference);				
			if (map_pixel == '0')
				ft_put_common(mlx, window, window->game.frames.F.reference);
			if (map_pixel == 'K' && is_bonus)
				ft_put_common(mlx, window, window->game.frames.K.reference);
			else if (map_pixel == 'K' && !is_bonus)
				map_not_equal_to_program();
			window->game.frame_position.x++;
		}
		window->game.frame_position.y++;
	}
}
