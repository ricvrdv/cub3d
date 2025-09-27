/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 13:17:33 by rjesus-d          #+#    #+#             */
/*   Updated: 2025/09/27 13:17:35 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	movement_keys(t_player *player, double	*move_x, double *move_y)
{
	if (player->key_w)
	{
		*move_x += player->dir_x * player->move_speed;
		*move_y += player->dir_y * player->move_speed;
	}
	if (player->key_s)
	{
		*move_x -= player->dir_x * player->move_speed;
		*move_y -= player->dir_y * player->move_speed;
	}
	if (player->key_a)
	{
		*move_x += player->dir_y * player->move_speed;
		*move_y -= player->dir_x * player->move_speed;
	}
	if (player->key_d)
	{
		*move_x -= player->dir_y * player->move_speed;
		*move_y += player->dir_x * player->move_speed;
	}
}

void	handle_movement(t_game *game)
{
	double		move_x;
	double		move_y;
	double		rot_speed;
	t_player	*player;

	player = &game->player;
	move_x = 0;
	move_y = 0;
	rot_speed = 0;
	movement_keys(player, &move_x, &move_y);
	if (player->key_left)
		rot_speed -= player->rot_speed;
	if (player->key_right)
		rot_speed += player->rot_speed;
	if (rot_speed != 0)
		rotate_player(player, rot_speed);
	if (move_x != 0 || move_y != 0)
	{
		if (game->grid[(int)(player->position.y / TILE_SIZE)]
			[(int)(player->position.x / TILE_SIZE + move_x)] != '1')
			player->position.x += move_x * TILE_SIZE;
		if (game->grid[(int)(player->position.y / TILE_SIZE + move_y)]
			[(int)(player->position.x / TILE_SIZE)] != '1')
			player->position.y += move_y * TILE_SIZE;
	}
}

void	rotate_player(t_player *player, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(rot_speed)
		- player->dir_y * sin(rot_speed);
	player->dir_y = old_dir_x * sin(rot_speed)
		+ player->dir_y * cos(rot_speed);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(rot_speed)
		- player->plane_y * sin(rot_speed);
	player->plane_y = old_plane_x * sin(rot_speed)
		+ player->plane_y * cos(rot_speed);
}
