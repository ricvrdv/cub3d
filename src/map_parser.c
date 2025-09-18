#include "../inc/cub3d.h"

static int  ft_max(int x, int y)
{
    if (x > y)
        return (x);
    return (y);
}

static int is_map_line(const char *line)
{
    int i;
    int has_map_content = 0;

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

/*static void process_map_line(t_game *game, int y, char *line, int width)
{
    int x;

    x = 0;
    while (x < width)
    {
        if (x < (int)ft_strlen(line))
        {
            if (line[x] == '1')
                game->map[y][x] = 1;
            else if (line[x] == '0')
                game->map[y][x] = 0;
            else if (ft_strchr("NSEW", line[x]))
            {
                game->map[y][x] = 0;
                set_player_start(game, line[x], x, y);
            }
            else if (line[x] == ' ')
                game->map[y][x] = 1;
            else
                game->map[y][x] = 1;
        }
        else
            game->map[y][x] = 1;
        x++;
    }
}

static int  map_to_array(t_game *game, t_list *map_lines, int width, int height)
{
    int     y;
    char    *line_content;
    t_list  *current;

    game->map = malloc(sizeof(int *) * height);
    if (!game->map)
    {
        // Print "Memory allocation failed"
        return (0);
    }
    y = 0;
    current = map_lines;
    while (current && y < height)
    {
        line_content = (char *)current->content;
        game->map[y] = malloc(sizeof(int) * width);
        if (!game->map[y])
        {
            // Print "Memory allocation failed"
            return (0);

        }
        process_map_line(game, y, line_content, width);
        y++;
        current = current->next;
    }
    game->map_width = width;
    game->map_height = height;
    ft_lstclear(&map_lines, NULL);
    return (1);
}*/

int map_parser(t_game *game, int fd, char *line)
{
    t_list *map_lines;
    int     max_width; // or just use game->map.width; that was init to 0 already

    (void)game;
    map_lines = NULL;
    max_width = (int)ft_strlen(line);
    ft_lstadd_back(&map_lines, ft_lstnew(ft_strdup(line)));
    free(line);
    line = get_next_line(fd);
    while (line)
    {
        if (!is_map_line(line))
        {
            free(line);
            ft_lstclear(&map_lines, free);
            //close(fd);
            return (0);
        }
        ft_lstadd_back(&map_lines, ft_lstnew(ft_strdup(line)));
        max_width = ft_max(max_width, (int)ft_strlen(line));
        line = get_next_line(fd);
    }
    free(line);
    ft_lstclear(&map_lines, free);
    //if (!map_to_array(game, map_lines, max_width, ft_lstsize(map_lines)))
    //    return (0);
    return (1);
}