#include "cub3d.h"

int skip_spaces(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (ft_is_space(line[i]))
			i++;
		else
			return (i);
	}
	return (-1);
}

static int	is_map_line(const char *line)
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

static int check_missing_elem(t_game *game)
{
	if (!game->ceiling.id)
		return (1);
	else if (!game->floor.id)
		return (1);
	else if (!game->textures.no_path)
		return (1);
	else if (!game->textures.so_path)
		return (1);
	else if (!game->textures.we_path)
		return (1);
	else if (!game->textures.ea_path)
		return (1);
	else
		return (0);
}

int handle_line(t_game *game, int fd, char *line)
{
	int	i;

	i = skip_spaces(line);
	if (i == -1 || line[i] == '\0')
		return (0);
	if (ft_strchr("FC", line[i]))
		color_parser(game, line + i);
	else if (ft_strchr("NSWE", line[i]))
		texture_parser(game, line + i);
	else if (line[i] == '1')
	{
		if (check_missing_elem(game))
		{
			ft_dprintf(2, "Error\nMap has to be the last element\n");
			return (-1);
		}
		if (!is_map_line(line))
			return(-1);
		if (!map_parser(game, fd, line))
			return (-1);
		return (1);
	}
	return (0);
}

static void	finish_file_reading(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
}

void parser(t_game *game, char *filename)
{
	int 	fd;
	int		ret;
	char 	*line;
	char	*clean_line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (handle_error(game, "Opening file failed\n"));
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		handle_error(game, "Map file is empty.\n");
	}
	while (line)
	{
		clean_line = ft_strtrim(line, "\n\r");
		free(line);
		ret = handle_line(game, fd, clean_line);
		if (ret)
		{
			if (ret == -1)
			{
				free(clean_line);
				finish_file_reading(fd);
				clean_game(game);
				exit(EXIT_FAILURE);
			}
			free(clean_line);
			break ;
		}
		else
		{
			free(clean_line);
			line = get_next_line(fd);
		}
	}
	close(fd);
	if (check_missing_elem(game))
		handle_error(game, "File is missing elements\n");
	return ;
}
