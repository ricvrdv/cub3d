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

static int get_texture_pixel(t_img *texture, int x, int y)
{
    char *pixel;
    
    if (x < 0 || x >= texture->width || y < 0 || y >= texture->height)
        return (0);
    
    pixel = texture->addr + (y * texture->line_length + x * (texture->bits_per_pixel / 8));
    return (*(int *)pixel);
}

void    raycast(t_game *game)
{
    t_player    *player;
    int         x;
    int         y;
    double      camera_x;
    double      ray_dir_x;
    double      ray_dir_y;
    double      pos_x;
    double      pos_y;
    int         map_x;
    int         map_y;
    double      delta_dist_x;
    double      delta_dist_y;
    int         step_x;
    int         step_y;
    double      side_dist_x;
    double      side_dist_y;
    int         hit;
    int         side;
    double      perp_wall_dist;
    int         line_height;
    int         draw_start;
    int         draw_end;
    double      wall_x;
    t_img       *current_tex;
    int         tex_x;
    int         tex_y;
    double      step;
    double      tex_pos;
    int         color;


    player = &game->player;
    player->planeX = 0.66 * -game->player.dirY;
    player->planeY = 0.66 * game->player.dirX;
    pos_x = player->position.x / TILE_SIZE;
    pos_y = player->position.y / TILE_SIZE;
    x = 0;
    while (x < WIN_WIDTH)
    {
        //DDA
        camera_x = 2 * x / (double)WIN_WIDTH - 1;
        ray_dir_x = player->dirX + player->planeX * camera_x;
        ray_dir_y = player->dirY + player->planeY * camera_x;
        map_x = (int)pos_x;
        map_y = (int)pos_y;
        if (ray_dir_x == 0)
            delta_dist_x = 1e30;
        else
            delta_dist_x = fabs(1 / ray_dir_x);
        if (ray_dir_y == 0)
            delta_dist_y = 1e30;
        else
            delta_dist_y = fabs(1 / ray_dir_y);
        if (ray_dir_x < 0)
        {
            step_x = -1;
            side_dist_x = (pos_x - map_x) * delta_dist_x;
        }
        else
        {
            step_x = 1;
            side_dist_x = (map_x + 1.0 - pos_x) * delta_dist_x;
        }
        if (ray_dir_y < 0)
        {
            step_y = -1;
            side_dist_y = (pos_y - map_y) * delta_dist_y;
        }
        else
        {
            step_y = 1;
            side_dist_y = (map_y + 1.0 - pos_y) * delta_dist_y;
        }
        hit = 0;
        while (hit == 0) //decision maker
        {
            if (side_dist_x < side_dist_y)
            {
                side_dist_x += delta_dist_x;
                map_x += step_x;
                side = 0;
            }
            else
            {
                side_dist_y += delta_dist_y;
                map_y += step_y;
                side = 1;
            }
            if (game->grid[map_y][map_x] > 0)
                hit = 1;
        }
        //wall projection
        if (side == 0)
            perp_wall_dist = side_dist_x - delta_dist_x;
        else
            perp_wall_dist = side_dist_y - delta_dist_y;
        line_height = (int)(WIN_HEIGHT / perp_wall_dist);
        draw_start = -line_height / 2 + WIN_HEIGHT / 2;
        if (draw_start < 0)
            draw_start = 0;
        draw_end = line_height / 2 + WIN_HEIGHT / 2;
        if (draw_end >= WIN_HEIGHT)
            draw_end = WIN_HEIGHT - 1;
        //texture drawing
        if (side == 0)
            wall_x = pos_y + perp_wall_dist * ray_dir_y;
        else
            wall_x = pos_x + perp_wall_dist * ray_dir_x;
        wall_x -= floor(wall_x);
        // Choose correct texture
        if (side == 1)
        {
            if (ray_dir_y > 0)
                current_tex = &game->textures.south;
            else
                current_tex = &game->textures.north;
        }
        else
        {
            if (ray_dir_x > 0)
                current_tex = &game->textures.east;
            else
                current_tex = &game->textures.west;
        }
        tex_x = (int)(wall_x * (double)current_tex->width);
        if ((side == 0 && ray_dir_x > 0) || (side == 1 && ray_dir_y < 0))
            tex_x = current_tex->width - tex_x - 1;
        step = 1.0 * current_tex->height / line_height;
        tex_pos = (draw_start - WIN_HEIGHT / 2 + line_height / 2) * step;
        y = draw_start;
        while (y < draw_end)
        {
            tex_y = (int)tex_pos & (current_tex->height - 1);
            tex_pos += step;
            color = get_texture_pixel(current_tex, tex_x, tex_y);
            put_pixel(&game->img, x, y, color);
            y++;
        }
        x++;
    }
}

int render_frame(t_game *game)
{
    draw_floor_ceiling(game);
    raycast(game);
    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.img_ptr, 0, 0);
    return (0);
}
