#include "../inc/cub3d.h"

void    init_game(t_game *game)
{
    game->mlx_ptr = mlx_init();
    if (!game->mlx_ptr){}
        //handle_error(game, "Failed to initialize MinilibX.\n");
    game->win_ptr = mlx_new_window(game->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "CUB3D");
    if (!game->win_ptr){}
        //handle_error(game, "Failed to open window.\n");
    game->img.img_ptr = mlx_new_image(game->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
    if (!game->img.img_ptr){}
        //handle_error(game, "Failed to create image buffer.\n");
    game->img.addr = mlx_get_data_addr(game->img.img_ptr,
        &game->img.bits_per_pixel, &game->img.line_length,
        &game->img.endian);
    game->img.width = WIN_WIDTH;
    game->img.height = WIN_HEIGHT;
    load_textures(game);
}
