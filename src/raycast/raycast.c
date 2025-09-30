/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 14:08:16 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/09/27 15:23:36 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	decision_maker(t_raycast *raycast, t_game *game,
	int *step_x, int *step_y)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (raycast->side_dist_x < raycast->side_dist_y)
		{
			raycast->side_dist_x += raycast->delta_dist_x;
			raycast->map_x += *step_x;
			raycast->side = 0;
		}
		else
		{
			raycast->side_dist_y += raycast->delta_dist_y;
			raycast->map_y += *step_y;
			raycast->side = 1;
		}
		if (game->grid[raycast->map_y][raycast->map_x] == '1'
				|| game->grid[raycast->map_y][raycast->map_x] == 'D'
				|| game->grid[raycast->map_y][raycast->map_x] == 'O')
			hit = 1;
	}
}

static void	dda_algorithm(t_raycast *rc, t_game *game)
{
	int	step_x;
	int	step_y;

	if (rc->ray_dir_x < 0)
	{
		step_x = -1;
		rc->side_dist_x = (rc->grid_pos.x - rc->map_x) * rc->delta_dist_x;
	}
	else
	{
		step_x = 1;
		rc->side_dist_x = (rc->map_x + 1.0 - rc->grid_pos.x) * rc->delta_dist_x;
	}
	if (rc->ray_dir_y < 0)
	{
		step_y = -1;
		rc->side_dist_y = (rc->grid_pos.y - rc->map_y) * rc->delta_dist_y;
	}
	else
	{
		step_y = 1;
		rc->side_dist_y = (rc->map_y + 1.0 - rc->grid_pos.y) * rc->delta_dist_y;
	}
	decision_maker(rc, game, &step_x, &step_y);
}

static double	draw_wall_line(t_raycast *raycast)
{
	double	wall_x;

	if (raycast->side == 0)
		raycast->perp_wall_dist = raycast->side_dist_x - raycast->delta_dist_x;
	else
		raycast->perp_wall_dist = raycast->side_dist_y - raycast->delta_dist_y;
	if (raycast->perp_wall_dist < 0.0001)
		raycast->perp_wall_dist = 0.0001;
	raycast->line_height = (int)(WIN_HEIGHT / raycast->perp_wall_dist);
	raycast->draw_start = -raycast->line_height / 2 + WIN_HEIGHT / 2;
	if (raycast->draw_start < 0)
		raycast->draw_start = 0;
	raycast->draw_end = raycast->line_height / 2 + WIN_HEIGHT / 2;
	if (raycast->draw_end >= WIN_HEIGHT)
		raycast->draw_end = WIN_HEIGHT;
	if (raycast->side == 0)
		wall_x = raycast->grid_pos.y + raycast->perp_wall_dist
			* raycast->ray_dir_y;
	else
		wall_x = raycast->grid_pos.x + raycast->perp_wall_dist
			* raycast->ray_dir_x;
	wall_x -= floor(wall_x);
	return (wall_x);
}

static void	project_texture(t_raycast *raycast, t_game *game, double wall_x)
{
	if (game->grid[raycast->map_y][raycast->map_x] == 'D')
		raycast->current_tex = game->textures.door_closed;
	else if (game->grid[raycast->map_y][raycast->map_x] == 'O')
    	raycast->current_tex = game->textures.door_open;
	else if (raycast->side == 1)
	{
		if (raycast->ray_dir_y > 0)
			raycast->current_tex = game->textures.south;
		else
			raycast->current_tex = game->textures.north;
	}
	else
	{
		if (raycast->ray_dir_x > 0)
			raycast->current_tex = game->textures.east;
		else
			raycast->current_tex = game->textures.west;
	}
	raycast->tex_x = (int)(wall_x * (double)raycast->current_tex.width);
	if ((raycast->side == 0 && raycast->ray_dir_x < 0)
		|| (raycast->side == 1 && raycast->ray_dir_y > 0))
		raycast->tex_x = raycast->current_tex.width - raycast->tex_x - 1;
	raycast->step = 1.0 * raycast->current_tex.height / raycast->line_height;
	raycast->tex_pos = (raycast->draw_start - WIN_HEIGHT / 2
			+ raycast->line_height / 2) * raycast->step;
}

void	raycast(t_game *game, int color)
{
	t_player	*player;
	t_raycast	*rc;
	int			x;
	int			y;
	double		wall_x;

	player = &game->player;
	rc = &game->raycast;
	init_raycast(rc, player, game);
	x = 0;
	while (x++ < WIN_WIDTH)
	{
		init_dda(rc, player, x);
		dda_algorithm(rc, game);
		wall_x = draw_wall_line(rc);
		project_texture(rc, game, wall_x);
		y = rc->draw_start;
		while (y++ < rc->draw_end)
		{
			rc->tex_y = (int)rc->tex_pos & (rc->current_tex.height - 1);
			rc->tex_pos += rc->step;
			color = get_texture_pixel(&rc->current_tex, rc->tex_x, rc->tex_y);
			put_pixel(&game->img, x, y, color);
		}
	}
}
