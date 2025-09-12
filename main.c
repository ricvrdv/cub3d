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
    setup_hooks(&game);
    mlx_loop(game.mlx_ptr);
    printf("Work in progress...");
    return (0);
}