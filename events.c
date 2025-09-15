#include "cub3d.h"

int handle_keypress(int keysym, t_game *game)
{
    t_player    *player;

    player = &game->player;
    if (keysym == XK_Escape)
    {
        exit_game(game);
    }
    else if (keysym == XK_W || keysym == XK_w)
        player->key_w = true;
    else if (keysym == XK_A || keysym == XK_a)
        player->key_a = true;
    else if (keysym == XK_S || keysym == XK_s)
        player->key_s = true;
    else if (keysym == XK_D || keysym == XK_d)
        player->key_d = true;
    else if (keysym == XK_Left)
        player->key_left = true;
    else if (keysym == XK_Right)
        player->key_right = true;
    return (0);
}

int handle_keyrelease(int keysym, t_player *player)
{
    if (keysym == XK_W || keysym == XK_w)
        player->key_w = false;
    else if (keysym == XK_A || keysym == XK_a)
        player->key_a = false;
    else if (keysym == XK_S || keysym == XK_s)
        player->key_s = false;
    else if (keysym == XK_D || keysym == XK_d)
        player->key_d = false;
    else if (keysym == XK_Left)
        player->key_left = false;
    else if (keysym == XK_Right)
        player->key_right = false;
    return (0);
}
