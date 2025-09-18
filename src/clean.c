#include "../inc/cub3d.h"

static void destroy_textures(t_game *game)
{
    if (game->textures.no_path)
        free(game->textures.no_path);
    if (game->textures.so_path)
        free(game->textures.so_path);
    if (game->textures.we_path)
        free(game->textures.we_path);
    if (game->textures.ea_path)
        free(game->textures.ea_path);
    if (game->textures.north.img_ptr)
        mlx_destroy_image(game->mlx_ptr, game->textures.north.img_ptr);
    if (game->textures.south.img_ptr)
        mlx_destroy_image(game->mlx_ptr, game->textures.south.img_ptr);
    if (game->textures.west.img_ptr)
        mlx_destroy_image(game->mlx_ptr, game->textures.west.img_ptr);
    if (game->textures.east.img_ptr)
        mlx_destroy_image(game->mlx_ptr, game->textures.east.img_ptr);
}

void clean_game(t_game *game)
{
    if (!game)
        return ;
    if (game->img.img_ptr)
        mlx_destroy_image(game->mlx_ptr, game->img.img_ptr);
    destroy_textures(game);
    if (game->win_ptr)
        mlx_destroy_window(game->mlx_ptr, game->win_ptr);
    if (game->mlx_ptr)
    {
        mlx_destroy_display(game->mlx_ptr);
        free(game->mlx_ptr);
    }
}
