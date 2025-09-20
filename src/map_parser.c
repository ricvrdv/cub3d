#include "../inc/cub3d.h"

static int  ft_max(int x, int y)
{
    if (x > y)
        return (x);
    return (y);
}

int is_map_line(const char *line)
{
    int i;
    int has_map_content;

    has_map_content = 0;
    if (!line || line[0] == '\0')
        return (0);
    i = 0;
    while (line[i])
    {
        if (!ft_strchr(" 01NSEW", line[i]))
            return (0);
        if (ft_strchr("01NSEW", line[i]))
            has_map_content = 1;
        i++;
    }
    return (has_map_content);
}

static int  validate_map(t_game *game)
{
    int i;
    int j;
    int player_count;

    i = 0;
    player_count = 0;
    while (i < game->map_height)
    {
        j = 0;
        while (j < game->map_width)
        {
            if (!ft_strchr("01NSWEX", game->grid[i][j]))
            {
                ft_dprintf(2, "Error\n");
                ft_dprintf(2, "Invalid char '%c' in map.\n", game->grid[i][j]);
                return (0);
            }
            if (ft_strchr("NSWE", game->grid[i][j]))
            {
                player_count++;
                if (player_count == 1)
                {
                    game->player.pos_x = j + 0.5;
                    game->player.pos_y = i + 0.5;
                    game->player.orientation = game->grid[i][j];
                    //ft_printf("Player\nx: %d y: %d orientation: %c\n", game->player.pos_x, game->player.pos_y, game->player.orientation);
                }
            }
            j++;
        }
        i++;
    }
    if (!player_count)
    {
        ft_dprintf(2, "Error\nNo player starting position found.\n");
        return (0);
    }
    if (player_count > 1)
    {
        ft_dprintf(2, "Error\nMultiple player starting positions found.\n");
        return (0);
    }
    // if (!is_map_closed(game))
    // {
    //     ft_dprintf(2, "Error\nMap is not closed.\n");
    //     return (0);
    // }
    return (1);
}

static void normalize_map(char *dest, const char *src, int width)
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

int map_to_array(t_game *game, t_list *map_lines, int width, int height)
{
    t_list  *current;
    int     y;

    current = map_lines;
    game->grid = malloc(sizeof(char *) * height);
    if (!game->grid)
        return (0);
    y = 0;
    while (current && y < height)
    {
        game->grid[y] = malloc(sizeof(char) * (width + 1));
        if (!game->grid[y])
        {
            while (y > 0)
            {
                free(game->grid[y]);
                y--;
            }
            free(game->grid);
            return (0);
        }
        normalize_map(game->grid[y], current->content, width);
        //ft_printf("%s\n", game->grid[y]);
        y++;
        current = current->next;
    }
    return (1);
}

static char *convert_spaces(const char *line)
{
    int     i;
    int     len;
    char    *converted;

    len = ft_strlen(line);
    converted = malloc(len + 1);
    if (!converted)
        return (NULL);
    i = 0;
    while (i < len)
    {
        if (line[i] == ' ')
            converted[i] = 'X';
        else
            converted[i] = line[i];
        i++;
    }
    converted[i] = '\0';
    return (converted);
}

int map_parser(t_game *game, int fd, char *line)
{
    t_list  *map_lines;
    char    *clean_line;

    map_lines = NULL;
    game->map_width = (int)ft_strlen(line);
    ft_lstadd_back(&map_lines, ft_lstnew(convert_spaces(line)));
    line = get_next_line(fd);
    while (line)
    {
        clean_line = ft_strtrim(line, "\n");
        free(line);
        // if (!is_map_line(clean_line))
        // {
        //     free(clean_line);
        //     ft_lstclear(&map_lines, free);
        //     line = get_next_line(fd);
        //     // When there is the need to abort the reading of a file early
        //     // we need to continue reading until the end to avoid mem leaks
        //     while (line)
        //     {
        //         free(line);
        //         line = get_next_line(fd);
        //     }
        //     return (0);
        // }
        ft_lstadd_back(&map_lines, ft_lstnew(convert_spaces(clean_line)));
        game->map_width = ft_max(game->map_width, (int)ft_strlen(clean_line));
        free(clean_line);
        line = get_next_line(fd);
    }
    game->map_height = ft_lstsize(map_lines);
    if (!map_to_array(game, map_lines, game->map_width, game->map_height))
    {
        ft_lstclear(&map_lines, free);
        return (0);
    }
    ft_lstclear(&map_lines, free);
    if (!validate_map(game))
        return (0);
    return (1);
}