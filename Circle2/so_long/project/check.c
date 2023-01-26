/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabah <hakkisabah@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:27:53 by hsabah            #+#    #+#             */
/*   Updated: 2023/01/27 00:36:49 by hsabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_arg(int argc, char **argv)
{
	int	argvlen;

	argvlen = ft_strlen(argv[1]);

	if (argc != 2)
	{
		ft_putstr_fd("Error\nInvalid number of arguments. Must be 2.\n",1);
		exit(0);
	}
	if (!ft_strnstr(argv[1], ".ber", argvlen))
	{
		ft_putstr_fd("Error\nInvalid file type. Must be: \"<name>.ber\"\n",1);
		exit (1);
	}
	if (argv[1][argvlen - 4] != '.' || argv[1][argvlen - 3] != 'b' || argv[1][argvlen - 2] != 'e' 
		|| argv[1][argvlen - 1] != 'r' || argv[1][argvlen] != '\0')
	{
		ft_putstr_fd("Error\nInvalid file type. Must be: \"<name>.ber\"\n",1);
		exit (1);
	}
}

void	ft_check_map(char *buffer, t_game *game)
{
	/* we need to check without the newlines('\n') in the buffer */
	if ((int)(ft_strlen(buffer) - game->map_height) != (game->map_height * game->map_width) 
		|| game->map_height == game->map_width)
	{
		ft_putstr_fd("Error!\nThe map has a wrong layout.\n",1);
		exit (1);
	}
	ft_check_x_limits(game);
	ft_check_y_limits(game);
}

void	ft_check_component(char *buffer, t_game *game)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == 'P')
			game->player++;
		if (buffer[i] == 'C')
			game->collectibles++;
		if (buffer[i] == 'E')
			game->exit++;
		if (buffer[i] == '\n')
			game->map_height++;
		i++;
	}
	if (game->player != 1 || game->collectibles < 1 || game->exit != 1)
	{
		ft_putstr_fd("Error\nIncorrect number of Players, Collectibles or Exits.\n",1);
		exit(1);
	}
}

void	ft_check_x_limits(t_game *game)
{
	int x;
	int y;

	x = 0;
	while (x < game->map_width)
	{
		if (game->map[0][x] != '1')
			ft_limits_error();
		x++;
	}
	y = game->map_height - 1;
	x = 0;
	while (x < game->map_width)
	{
		if (game->map[y][x] != '1')
			ft_limits_error();
		x++;
	}
}

void	ft_check_y_limits(t_game *game)
{
	int	x;
	int	y;
	
	y = 0;
	while (y < game->map_height)
	{
		if (game->map[y][0] != '1')
			ft_limits_error();
		y++;
	}
	y = 0;
	x = game->map_width - 1;
	while (y < game->map_height)
	{
		if (game->map[y][x] != '1')
			ft_limits_error();
		y++;
	}
}
