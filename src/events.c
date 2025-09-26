#include "cub3d.h"

int handle_keypress(int keysym, t_game *game)
{
    t_player    *player;

    player = &game->player;
    if (keysym == XK_Escape)
        close_window(game);
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

int close_window(t_game *game)
{
    clean_game(game);
    exit(EXIT_SUCCESS);
}

void handle_movement(t_game *game)
{
    double moveX;
    double moveY;
    double rotSpeed;
	t_player	*player;

	player = &game->player;
    moveX = 0;
	moveY = 0;
	rotSpeed = 0;
    if (player->key_w)
	{
		moveX += player->dirX * player->move_speed;
		moveY += player->dirY * player->move_speed;
	}
    if (player->key_s)
	{
		moveX -= player->dirX * player->move_speed;
		moveY -= player->dirY * player->move_speed;
	}
    if (player->key_a)
	{
		moveX += player->dirY * player->move_speed;
		moveY -= player->dirX * player->move_speed;
	}
    if (player->key_d)
	{
		moveX -= player->dirY * player->move_speed;
		moveY += player->dirX * player->move_speed;
	}
    if (player->key_left) 
		rotSpeed -= player->rot_speed;
    if (player->key_right)
		rotSpeed += player->rot_speed;
    if (rotSpeed != 0)
        rotate_player(player, rotSpeed);
    if (moveX != 0 || moveY != 0)
    {
        if (game->grid[(int)(player->position.y / TILE_SIZE)][(int)(player->position.x / TILE_SIZE + moveX)] != '1')
            player->position.x += moveX * TILE_SIZE;
        if (game->grid[(int)(player->position.y / TILE_SIZE + moveY)][(int)(player->position.x / TILE_SIZE)] != '1')
            player->position.y += moveY * TILE_SIZE;
    }
}

void	rotate_player(t_player *player, double rot_speed)
{
	double  oldDirX;
    double  oldPlaneX;

    oldDirX = player->dirX;
	player->dirX = player->dirX * cos(rot_speed) - player->dirY * sin(rot_speed);
	player->dirY = oldDirX * sin(rot_speed) + player->dirY * cos(rot_speed);
	oldPlaneX = player->planeX;
	player->planeX = player->planeX * cos(rot_speed) - player->planeY * sin(rot_speed);
	player->planeY = oldPlaneX * sin(rot_speed) + player->planeY * cos(rot_speed);
}
