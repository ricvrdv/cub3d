#include "cub3d.h"

void    setup_hooks(t_game *game)
{
    mlx_hook(game->win_ptr, KeyPress, KeyPressMask, handle_keypress, game);
    mlx_hook(game->win_ptr, KeyRelease, KeyReleaseMask, handle_keyrelease, &game->player);
    mlx_hook(game->win_ptr, DestroyNotify, NoEventMask, exit_game, game);
    mlx_loop_hook(game->mlx_ptr, main_loop, game);
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
    //texture->no_path = "textures/north.xpm";
    //texture->so_path = "textures/south.xpm";
    //texture->we_path = "textures/west.xpm";
    //texture->ea_path = "textures/east.xpm";
    load_from_path(game, &texture->north, texture->no_path);
    load_from_path(game, &texture->south, texture->so_path);
    load_from_path(game, &texture->west, texture->we_path);
    load_from_path(game, &texture->east, texture->ea_path);
}

int exit_game(t_game *game)
{
    if (!game)
        return (1);
    if (game->img.img_ptr)
        mlx_destroy_image(game->mlx_ptr, game->img.img_ptr);
    if (game->win_ptr)
        mlx_destroy_window(game->mlx_ptr, game->win_ptr);
    if (game->mlx_ptr)
    {
        mlx_destroy_display(game->mlx_ptr);
        free(game->mlx_ptr);
    }
    exit(0);
}