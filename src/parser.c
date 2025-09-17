#include "../inc/cub3d.h"

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

int handle_line(t_game *game, char *line)
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
		if (!map_parser(game, line))
			return (0);
		return (1);
	}
	return (0);
}

int parser(t_game *game, char *filename)
{
	int fd;
	char *line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (handle_error(game, "Opening file failed\n"), 1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
    		break ;
		if (handle_line(game, line))
		{
			free(line);
			break ;
		}
		free(line);
	}
	close(fd);
	return (0);
}
