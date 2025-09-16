#include "../inc/cub3d.h"

int main(int argc, char **argv)
{
    t_game  game;

    if (argc != 2)
    {
        ft_dprintf(2, "Error\nUsage: %s <map_file.cub>", argv[0]);
        return (1);
    }
    if (!input_checker(argv[1]))
    {
        ft_dprintf(2, "Error\nFile extension must be .cub\n");
        return (1);
    }
    ft_memset(&game, 0, sizeof(t_game));
    init_game(&game);
    setup_hooks(&game);
    mlx_loop(game.mlx_ptr);
    printf("Work in progress...");
    return (0);
}
