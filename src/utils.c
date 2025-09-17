#include "../inc/cub3d.h"

void    setup_hooks(t_game *game)
{
    mlx_hook(game->win_ptr, KeyPress, KeyPressMask, handle_keypress, game);
    mlx_hook(game->win_ptr, KeyRelease, KeyReleaseMask, handle_keyrelease, &game->player);
    mlx_hook(game->win_ptr, DestroyNotify, NoEventMask, close_window, game);
    mlx_loop_hook(game->mlx_ptr, render_frame, game);
}

static void load_from_path(t_game *game, t_img *texture, char *path)
{
    texture->img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, path,
        &texture->width, &texture->height);
    if (!texture->img_ptr)
    {
        // Cleanup and exit
    }
    texture->addr = mlx_get_data_addr(texture->img_ptr, &texture->bits_per_pixel,
        &texture->line_length, &texture->endian);
}

void    load_textures(t_game *game)
{
    t_textures  *texture;

    texture = &game->textures;
    load_from_path(game, &texture->north, texture->no_path);
    load_from_path(game, &texture->south, texture->so_path);
    load_from_path(game, &texture->west, texture->we_path);
    load_from_path(game, &texture->east, texture->ea_path);
}

void    put_pixel(t_img *img, int x, int y, int color)
{
    char    *dst;

    if (x < 0 || y < 0 || x >= img->width || y >= img->height)
        return ;
    dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

void    handle_error(t_game *game, char *message)
{
    ft_putstr_fd("Error\n", STDERR_FILENO);
    if (message)
        ft_putstr_fd(message, STDERR_FILENO);
    clean_game(game);
    exit(EXIT_FAILURE);
}
