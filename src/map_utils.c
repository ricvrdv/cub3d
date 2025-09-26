#include "cub3d.h"

void normalize_map(char *dest, const char *src, int width)
{
    int i;
    int src_len;

    i = 0;
    src_len = ft_strlen(src);
    while (i < src_len && i < width)
    {
        dest[i] = src[i];
        i++;
    }
    while (i < width)
    {
        dest[i] = 'X';
        i++;
    }
    dest[i] = '\0';
}

void set_player_direction(t_game *game, int i, int j)
{
    if (game->grid[i][j] == 'N')
    {
        game->player.dirX = 0;
        game->player.dirY = -1;
    }
    else if (game->grid[i][j] == 'S')
    {
        game->player.dirX = 0;
        game->player.dirY = 1;
    }
    else if (game->grid[i][j] == 'W')
    {
        game->player.dirX = -1;
        game->player.dirY = 0;
    }
    else
    {
        game->player.dirX = 1;
        game->player.dirY = 0;
    }
}

