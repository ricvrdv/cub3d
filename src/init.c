/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 12:52:55 by rjesus-d          #+#    #+#             */
/*   Updated: 2025/10/09 17:01:02 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	rgb_to_int(t_colors color)
{
	return (color.r_code << 16 | color.g_code << 8 | color.b_code);
}

void	init_game(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		handle_error(game, "Failed to initialize MinilibX\n", 1);
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			WIN_WIDTH, WIN_HEIGHT, "CUB3D");
	if (!game->win_ptr)
		handle_error(game, "Failed to open window\n", 1);
	game->img.img_ptr = mlx_new_image(game->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!game->img.img_ptr)
		handle_error(game, "Failed to create image buffer\n", 1);
	game->img.addr = mlx_get_data_addr(game->img.img_ptr,
			&game->img.bits_per_pixel, &game->img.line_length,
			&game->img.endian);
	game->img.width = WIN_WIDTH;
	game->img.height = WIN_HEIGHT;
	load_textures(game);
	game->floor_color = rgb_to_int(game->floor);
	game->ceiling_color = rgb_to_int(game->ceiling);
	game->player.move_speed = 0.04;
	game->player.rot_speed = 0.04;
}

int	input_checker(char *input)
{
	char	**split;

	split = ft_split(input, '.');
	if (!split[1] || !ft_str_isalnum(split[0]))
	{
		free_arrays((void **)split);
		return (0);
	}
	if (ft_strncmp(split[1], "cub", 4) == 0)
	{
		free_arrays((void **)split);
		return (1);
	}
	else
	{
		free_arrays((void **)split);
		return (0);
	}
}
