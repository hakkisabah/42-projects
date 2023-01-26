/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabah <hakkisabah@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:13:30 by hsabah            #+#    #+#             */
/*   Updated: 2023/01/26 00:33:30 by hsabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_map_availability(char **map, int y, int x, t_program *program)
{
	if (program->window.game.collectibles == 0 && map[y][x] == 'E')
	{
		ft_putstr_fd("You won!\n", 1);
		ft_close(program);
	}
	if (map[y][x] == 'C')
		program->window.game.collectibles--;
	return (map[y][x] != '1' && map[y][x] != 'E');
}

int	ft_redirect_player(char *curr, char *redirected)
{
	*curr = '0';
	*redirected = 'P';
	return (1);
}