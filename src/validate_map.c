#include "cub3d.h"

static int  check_adjacent(t_game *game, t_point pos)
{
    t_point dir;
    t_point new_pos;

    dir.i = -1;
    while (dir.i <= 1)
    {
        dir.j = -1;
        while (dir.j <= 1)
        {
            if (dir.i != 0 || dir.j != 0)
            {
                new_pos.i = pos.i + dir.i;
                new_pos.j = pos.j + dir.j;
                if (new_pos.i < 0 || new_pos.i >= game->map_height
                    || new_pos.j < 0 || new_pos.j >=game->map_width)
                    return (0);
                if (game->grid[new_pos.i][new_pos.j] == 'X')
                    return (0);
            }
            dir.j++;
        }
        dir.i++;
    }
    return (1);
}

static int  is_map_closed(t_game *game)
{
    t_point pos;

    pos.i = 0;
    while (pos.i < game->map_height)
    {
        pos.j = 0;
        while (pos.j < game->map_width)
        {
            if (game->grid[pos.i][pos.j] == '0'
                || ft_strchr("NSWE", game->grid[pos.i][pos.j]))
            {
                if (!check_adjacent(game, pos))
                    return (0);
            }
            pos.j++;
        }
        pos.i++;
    }
    return (1);
}

static int  check_player_count(int player_count)
{
    if (player_count == 0)
    {
        ft_dprintf(2, "Error\nNo player starting position found.\n");
        return (0);
    }
    if (player_count > 1)
    {
        ft_dprintf(2, "Error\nMultiple player starting positions found.\n");
        return (0);
    }
    return (1);
}

static void set_player_direction(t_game *game, int i, int j)
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

static int  validate_chars(t_game *game, t_point *p, int *player_count)
{
    if (!ft_strchr("01NSWEX", game->grid[p->i][p->j]))
    {
        ft_dprintf(2, "Error\n");
        ft_dprintf(2, "Invalid char '%c' in map.\n", game->grid[p->i][p->j]);
        return (0);
    }
    if (ft_strchr("NSWE", game->grid[p->i][p->j]))
    {
        (*player_count)++;
        if (*player_count == 1)
        {
            game->player.position.x = p->j * TILE_SIZE + TILE_SIZE / 2;
            game->player.position.y = p->i * TILE_SIZE + TILE_SIZE / 2;
            set_player_direction(game, p->i, p->j);
        }
    }
    return (1);
}

int  validate_map(t_game *game)
{
    t_point pos;
    int     player_count;

    pos.i = 0;
    player_count = 0;
    while (pos.i < game->map_height)
    {
        pos.j = 0;
        while (pos.j < game->map_width)
        {
            if (!validate_chars(game, &pos, &player_count))
                return (0);
            pos.j++;
        }
        pos.i++;
    }
    if (!check_player_count(player_count))
        return (0);
    if (!is_map_closed(game))
    {
        ft_dprintf(2, "Error\nMap is not closed.\n");
        return (0);
    }
    return (1);
}
