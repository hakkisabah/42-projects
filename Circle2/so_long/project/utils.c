/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabah <hakkisabah@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 01:21:41 by hsabah            #+#    #+#             */
/*   Updated: 2023/01/26 01:43:52 by hsabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_limits_error(void)
{
	ft_putstr_fd("Error!\nNot enough trees in the screen limits.\n",1);
	ft_putstr_fd("Please, plant 1 where they are supposed to be.\n",1);
	exit(1);
}

void	ft_file_is_open(int fd)
{
	if (fd == -1)
	{
		ft_putstr_fd("Error!\nThe map could not be read.\n",1);
		exit (1);
	}
}

void	ft_small_map(t_game *game)
{
	if (game->map_height < 3 || game->map_width < 3)
	{
		ft_putstr_fd("Error!\nThe map is too small.\n",1);
		exit (0);
	}
}

void	ft_path_is_ok(int W, int K, int y)
{
	ft_putnbr_fd(W, 1);
	ft_putnbr_fd(K, 1);
	ft_putnbr_fd(y, 1);
	ft_putnbr_fd(W + K, 1);
	ft_putchar_fd('\n', 1);
	if (((W > 0 || K > 0) && (W == y || K == y)) || (W + K) == y)
	{
		ft_putstr_fd("Error!\nPath sequence is illogical in the map.\n",1);
		exit (0);
	}
}