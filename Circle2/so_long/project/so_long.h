/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabah <hakkisabah@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 01:42:17 by hsabah            #+#    #+#             */
/*   Updated: 2023/01/26 13:32:28 by hsabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"

# define ANIMATION_FRAMES 50

typedef struct	s_size
{
	int	x;
	int	y;
}				t_size;

typedef struct s_image
{
	void		*reference;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
	char		*pixels;
	t_size		size;
}				t_image;

typedef struct s_frames
{
	t_image		P;
	t_image		C;
	t_image		E;
	t_image		W;
	t_image		F;
	t_image		K;
}				t_frames;

typedef struct s_game
{
	char		**map;
	int			map_width;
	int			map_height;
	int			collectibles;
	int			exit;
	int			player;
	int			player_x;
	int			player_y;
	int			moves_total;
	t_frames	frames;
	t_size		frame_position;
}				t_game;

typedef struct	s_window 
{
	void		*reference;
	t_size		size;
	t_game		game;
}				t_window;

typedef struct	s_program 
{
	void		*mlx;
	t_window	window;
}				t_program;

void	ft_check_arg(int argc, char **argv);
void	ft_check_map(char *buffer, t_game *game);
void	ft_check_component(char *buffer, t_game *game);
void	ft_check_y_limits(t_game *game);
void	ft_check_x_limits(t_game *game);

int		ft_redirect_player(char *curr, char *redirected);
int		ft_map_availability(char **map, int y, int x, t_program *program);

int		ft_input(int key, void *param);
int		ft_update (void *param);

void	ft_put_movements(t_game *game);
void	ft_put_display(t_program *program);
void	ft_is_move(t_program *program, int is_move, int is_bonus);
int		ft_movements_keyhooks(int key, t_program *program, int is_bonus);

char	*ft_join(char *line, char c);
int		ft_is_line(char *line);
char	*ft_get_map(int fd);

void	find_path(char **map, int y, int x);

void	ft_limits_error(void);
t_image	ft_img(void *mlx, char *path);
void	ft_put_common(void *mlx,t_window *window, void *frame);
void	ft_put_player(void *mlx,t_window *window);
void	ft_fill_window(void *mlx, t_window *window);

void	ft_init_struct(t_game *game);
void	define_frames(void *mlx, t_frames *frames);

void	ft_file_is_open(int fd);
void	ft_small_map(t_game *game);
void	ft_path_is_ok(int W, int K, int y);
void	ft_validate_map_path(t_game *game);
void	ft_validate_map(char **argv, t_game *game);

int			ft_close(t_program *program);
t_window	ft_new_window(t_program *program, char *name);

#endif