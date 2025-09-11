#include "cub3d.h"

int handle_keypress(int keycode, t_game *game)
{
    t_player    *player;

    player = &game->player;
    if (keycode == KEY_ESC)
    {
        // Cleanup and exit
    }
    else if (keycode == KEY_W)
        player->key_w = true;
    else if (keycode == KEY_A)
        player->key_a = true;
    else if (keycode == KEY_S)
        player->key_s = true;
    else if (keycode == KEY_D)
        player->key_d = true;
    else if (keycode == KEY_LEFT)
        player->key_left = true;
    else if (keycode == KEY_RIGHT)
        player->key_right = true;
    return (0);
}

int handle_keyrelease(int keycode, t_game *game)
{
    if (keycode == KEY_W)
        player->key_w = false;
    else if (keycode == KEY_A)
        player->key_a = false;
    else if (keycode == KEY_S)
        player->key_s = false;
    else if (keycode == KEY_D)
        player->key_d = false;
    else if (keycode == KEY_LEFT)
        player->key_left = false;
    else if (keycode == KEY_RIGHT)
        player->key_right = false;
    return (0);
}

int exit_game(t_game *game)
{
    if (game->img_buffer.img_ptr)
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