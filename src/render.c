#include "cub3d.h"

static void draw_floor_ceiling(t_game *game)
{
    int x;
    int y;
    y = 0;
    while (y < WIN_HEIGHT / 2)
    {
        x = 0;
        while (x < WIN_WIDTH)
        {
            put_pixel(&game->img, x, y, game->ceiling_color);
            x++;
        }
        y++; 
    }
    y = WIN_HEIGHT / 2;
    while (y < WIN_HEIGHT)
    {
        x = 0;
        while (x < WIN_WIDTH)
        {
            put_pixel(&game->img, x, y, game->floor_color);
            x++;
        }
        y++;
    }
}

int render_frame(t_game *game)
{
    draw_floor_ceiling(game);
    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.img_ptr, 0, 0);
    return (0);
}
