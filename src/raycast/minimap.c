#include "cub3d.h"

static void	draw_tile(t_game *game, t_point map, int color, int tile)
{
	t_point	pixel;
	t_point	offset;

	pixel.i = map.i * tile;
	pixel.j = map.j * tile;
	offset.i = 0;
	while (offset.i < tile)
	{
		offset.j = 0;
		while (offset.j < tile)
		{
			put_pixel(&game->img,
				pixel.i + offset.i, pixel.j + offset.j, color);
			offset.j++;
		}
		offset.i++;
	}
}

static int	get_tile_color(char cell)
{
	if (cell == '1')
		return (0x555555);
	else if (cell == 'D')
		return (0x964B00);
	else if (cell == 'O')
		return (0xCCCCCC);
	return (0x000000);
}

static void	draw_map_grid(t_game *game, int tile)
{
	t_point	map;
	char		cell;

	map.j = 0;
	while (map.j < game->map_height)
	{
		map.i = 0;
		while (map.i < game->map_width)
		{
			cell = game->grid[map.j][map.i];
			draw_tile(game, map, get_tile_color(cell), tile);
			map.i++;
		}
		map.j++;
	}
}

static void	draw_player_marker(t_game *game, int tile)
{
	t_point	p;
	t_point	offset;

	p.i = (int)(game->player.position.x / TILE_SIZE * tile);
	p.j = (int)(game->player.position.y / TILE_SIZE * tile);
	offset.i = -2;
	while (offset.i <= 2)
	{
		offset.j = -2;
		while (offset.j <= 2)
		{
			put_pixel(&game->img, p.i + offset.i, p.j + offset.j, 0xFF0000);
			offset.j++;
		}
		offset.i++;
	}
}

void	draw_minimap(t_game *game)
{
	int	tile;

	tile = MINIMAP_TILE;
	draw_map_grid(game, tile);
	draw_player_marker(game, tile);
}
