/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabah <hakkisabah@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 01:40:52 by hsabah            #+#    #+#             */
/*   Updated: 2023/01/30 23:24:57 by hsabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_program program;

	ft_check_arg(argc, argv);
	ft_init_struct(&program, 0);
	ft_validate_map(argv, &program);
    program.mlx = mlx_init();
    program.window = ft_new_window(&program, "So Long");
	define_frames(&program);

	mlx_hook(program.window.reference, 2, 1L << 0, *ft_input, &program); // 1L << 0 KeyPressMask
	mlx_hook(program.window.reference, 17, 1L << 5, ft_close, &program); // 1L << 5 WindowLeaveMask
	mlx_loop_hook(program.mlx, *ft_update, &program);
	mlx_loop(program.mlx);

	ft_reset_program(program);

	exit(1);
    return (1);
}