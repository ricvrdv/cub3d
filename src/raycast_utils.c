/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 15:21:21 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/09/27 15:22:12 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_raycast(t_raycast *raycast, t_player *player, t_game *game)
{
	player->plane_x = 0.66 * -game->player.dir_y;
	player->plane_y = 0.66 * game->player.dir_x;
	raycast->grid_pos.x = player->position.x / TILE_SIZE;
	raycast->grid_pos.y = player->position.y / TILE_SIZE;
}

void	init_dda(t_raycast *raycast, t_player *player, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)WIN_WIDTH - 1;
	raycast->ray_dir_x = player->dir_x + player->plane_x * camera_x;
	raycast->ray_dir_y = player->dir_y + player->plane_y * camera_x;
	raycast->map_x = (int)raycast->grid_pos.x;
	raycast->map_y = (int)raycast->grid_pos.y;
	if (raycast->ray_dir_x == 0)
		raycast->delta_dist_x = 1e30;
	else
		raycast->delta_dist_x = fabs(1 / raycast->ray_dir_x);
	if (raycast->ray_dir_y == 0)
		raycast->delta_dist_y = 1e30;
	else
		raycast->delta_dist_y = fabs(1 / raycast->ray_dir_y);
}
