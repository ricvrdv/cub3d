#include "cub3d.h"

void    setup_hooks(t_game *game)
{
    mlx_hook(game.win_ptr, 2, 1L<<0, handle_keypress, &game);
    mlx_hook(game.win_ptr, 3, 1L<<1, handle_keyrelease, &game.player);
    mlx_hook(game.win_ptr, 17, 0, exit_game, &game);
    mlx_loop_hook(game.mlx_ptr, main_loop, &game);
}