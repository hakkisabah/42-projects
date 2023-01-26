/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabah <hakkisabah@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 23:46:09 by hsabah            #+#    #+#             */
/*   Updated: 2023/01/27 00:24:32 by hsabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_validate_map_path(t_game *game)
{
	int	W;
	int	K;
	int	x;
	int	y;

	ft_small_map(game);
	x = 1;
	while (x < game->map_width)
	{
		y = 0;
		W = 0;
		K = 0;
		while (y < game->map_height && x != (game->map_width - 1))
		{
			if (game->map[y][x] == '1')
				W++;
			if (game->map[y][x] == 'K')
				K++;
			y++;
		}
		ft_path_is_ok(W, K, game->map_height);
		x++;
	}
	// find_path(game->map, game->map_height, game->map_width);
}

void	ft_validate_map(char **argv, t_game *game)
{
	int		i;
	int		fd;
	char	*buffer;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	ft_file_is_open(fd);
	buffer = ft_get_map(fd);
	if (buffer[ft_strlen(buffer) - 1] != '\n')  /* prevent possible error for map layout */
		buffer = ft_join(buffer, '\n');
	ft_check_component(buffer, game);
	game->map = ft_split(buffer, '\n');
	while (game->map[0][i] != '\0')
	{
		game->map_width++;
		i++;
	}
	ft_check_map(buffer, game);
	ft_validate_map_path(game);
	free(buffer);
	close(fd);
}