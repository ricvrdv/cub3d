#include "cub3d.h"

void    init_game(t_game *game)
{
    game->mlx_ptr = mlx_init();
    if (!game->mlx_ptr)
    {
        // Cleanup and exit
    }
    game->win_ptr = mlx_new_window(game->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "CUB3D");
    if (!game->win_ptr)
    {
        // Cleanup and exit
    }
}