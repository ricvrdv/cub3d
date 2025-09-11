#include "cub3d.h"

int main(int argc, char **argv)
{
    t_game  game;

    if (argc != 2)
    {
        return (1);
    }
    ft_memset(&game, 0, sizeof(t_game));
    init_game(&game);
    mlx_hook(game.win_ptr, 2, 1L<<0, handle_keypress, &game);
    mlx_hook(game.win_ptr, 3, 1L<<1, handle_keyrelease, &game.player);
    mlx_hook(game.win_ptr, 17, 0, exit_game, &game);
    mlx_loop_hook(game.mlx_ptr, main_loop, &game);
    mlx_loop(game.mlx_ptr);
    printf("Work in progress...");
    return (0);
}