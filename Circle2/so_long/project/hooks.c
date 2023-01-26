/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabah <hakkisabah@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:19:11 by hsabah            #+#    #+#             */
/*   Updated: 2023/01/26 00:34:42 by hsabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_input(int key, void *param)
{
	t_program	*program = (t_program *)param;
	
	mlx_clear_window(program->mlx, program->window.reference);

	if (key == 65307)
		ft_close(program);
	if (key == 100 || key == 97 || key == 115 || key == 119)
		return (ft_movements_keyhooks(key, program, 0));
	return (0);
}

int	ft_update (void *param)
{
	t_program	*program = (t_program *)param;

	ft_fill_window(program->mlx, &program->window);
	return (0);
}