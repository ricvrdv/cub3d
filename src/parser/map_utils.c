/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 12:42:08 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/09/27 12:44:28 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	normalize_map(char *dest, const char *src, int width)
{
	int	i;
	int	src_len;

	i = 0;
	src_len = ft_strlen(src);
	while (i < src_len && i < width)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < width)
	{
		dest[i] = 'X';
		i++;
	}
	dest[i] = '\0';
}

void	set_player_direction(t_game *game, int i, int j)
{
	if (game->grid[i][j] == 'N')
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
	}
	else if (game->grid[i][j] == 'S')
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
	}
	else if (game->grid[i][j] == 'W')
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
	}
	else
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
	}
}
