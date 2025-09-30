/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 12:37:26 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/09/27 15:22:43 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define TILE_SIZE 128

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <stdbool.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "libft/libft.h"
# include "minilibx_linux/mlx.h"

typedef struct s_point
{
	int	i;
	int	j;
}	t_point;

typedef struct s_pos
{
	double	x;
	double	y;
}	t_pos;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_raycast
{
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		side_dist_x;
	double		side_dist_y;
	double		perp_wall_dist;
	int			line_height;
	int			tex_x;
	int			tex_y;
	double		tex_pos;
	int			side;
	int			draw_start;
	int			draw_end;
	double		step;
	t_pos		grid_pos;
	t_img		current_tex;
}	t_raycast;

typedef struct s_player
{
	t_pos	position;
	double	angle;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	move_speed;
	double	rot_speed;
	bool	key_w;
	bool	key_s;
	bool	key_a;
	bool	key_d;
	bool	key_left;
	bool	key_right;
}	t_player;

typedef struct s_textures
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	t_img	north;
	t_img	south;
	t_img	west;
	t_img	east;
	t_img	door_open;
	t_img	door_closed;
}	t_textures;

typedef struct s_colors
{
	char	id;
	int		r_code;
	int		g_code;
	int		b_code;
}	t_colors;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		**grid;
	int			map_width;
	int			map_height;
	int			floor_color;
	int			ceiling_color;
	t_img		img;
	t_player	player;
	t_textures	textures;
	t_colors	floor;
	t_colors	ceiling;
	t_raycast	raycast;
}	t_game;

//	init
void	init_game(t_game *game);
int		input_checker(char *input);

//parser
int		handle_line(t_game *game, int fd, char *line);
void	parser(t_game *game, char *filename);

//parser_utils
void	finish_file_reading(int fd);
int		skip_spaces(char *line);
void	clean_gnl(t_game *game, char *clean_line, int fd);

//color_parser
int		color_parser(t_game *game, char *line);

//texture_parser
int		texture_parser(t_game *game, char *line);

// map_parser
int		map_parser(t_game *game, int fd, char *line);
int		map_to_array(t_game *game, t_list *map_lines, int width, int height);

// validate_map
int		validate_map(t_game *game);

// map_utils
void	normalize_map(char *dest, const char *src, int width);
void	set_player_direction(t_game *game, int i, int j);

// events
int		handle_keypress(int keysym, t_game *game);
int		handle_keyrelease(int keysym, t_player *player);
int		close_window(t_game *game);
void	handle_movement(t_game *game);
void	rotate_player(t_player *player, double rot_speed);
void	toggle_door(t_game *game, t_player *player);

//raycast
void	raycast(t_game *game, int color);

//raycast_utils
void	init_raycast(t_raycast *raycast, t_player *player, t_game *game);
void	init_dda(t_raycast *raycast, t_player *player, int x);

// render
int		render_frame(t_game *game);
int		get_texture_pixel(t_img *texture, int x, int y);

// clean
void	clean_game(t_game *game);

// utils
void	setup_hooks(t_game *game);
void	load_textures(t_game *game);
void	put_pixel(t_img *img, int x, int y, int color);
void	handle_error(t_game *game, char *message, int flag);

#endif
