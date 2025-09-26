#include "cub3d.h"

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
            return (free(game->grid), 0);
        }
        normalize_map(game->grid[y], current->content, width);
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

static int  handle_map_line(t_list **map_lines, char *line, int *map_width)
{
    char    *clean_line;

    clean_line = ft_strtrim(line, "\n\r");
    free(line);
    if (!*clean_line)
    {
        free(clean_line);
        ft_lstclear(map_lines, free);
        ft_dprintf(2, "Error\nMap has an empty line\n");
        return (0);
    }
    ft_lstadd_back(map_lines, ft_lstnew(convert_spaces(clean_line)));
    *map_width = ft_max(*map_width, (int)ft_strlen(clean_line));
    free(clean_line);
    return (1);
}

static int  read_map_lines(int fd, t_list **map_lines, int *map_width)
{
    char    *line;

    line = get_next_line(fd);
    while (line)
    {
        if (!handle_map_line(map_lines, line, map_width))
            return (0);
        line = get_next_line(fd);
    }
    return (1);
}

int map_parser(t_game *game, int fd, char *line)
{
    t_list  *map_lines;

    map_lines = NULL;
    game->map_width = (int)ft_strlen(line);
    ft_lstadd_back(&map_lines, ft_lstnew(convert_spaces(line)));
    if (!read_map_lines(fd, &map_lines, &game->map_width))
        return (0);
    game->map_height = ft_lstsize(map_lines);
    if (!map_to_array(game, map_lines, game->map_width, game->map_height))
    {
        ft_lstclear(&map_lines, free);
        return (0);
    }
    ft_lstclear(&map_lines, free);
    return (validate_map(game));
}
