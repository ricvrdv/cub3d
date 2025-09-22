#include "cub3d.h"

static int path_valid(char *line)
{
	char	**split;
	char	*last;
	int		i;

	if (ft_strchr(line, '.') == NULL)
		return (-1);
	else
		split = ft_split(line, '.');
	if (!split || !split[0])
		return (-1);
	if (ft_strncmp(split[1], "xpm", 3) != 0)
		return (free_arrays((void **)split), -1);
	i = 3;
	while (split[1][i])
	{
		if (split[1][i] != '\0' && !ft_is_space(split[1][i]))
			return (free_arrays((void **)split), -1);
		i++;
	}
	last = ft_strrchr(split[0], '/');
	i = 0;
	if (!last[i + 1])
		return (free_arrays((void **)split), -1);
	return (free_arrays((void **)split), 0);
}

static int path_exists(char *line)
{
	char	*path;
	int		fd;

	path = line;
	while (*path && !ft_is_space(*path))
		path++;
	while (*path && ft_is_space(*path))
		path++;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	close(fd);
	return (0);
}

static int	set_texture_path(t_game *game, char *line, const char *id, char **target)
{
	if (path_valid(line) == -1 || path_exists(line) == -1)
	{
		handle_error(game, "Texture path is not valid\n");
		return (1);
	}
	if ((ft_strncmp(line, id, 2) == 0) && !*target)
	{
		line += 2;
		if (!ft_is_space(*line))
		{
			handle_error(game, "Unknown texture identifier\n");
			return (1);
		}
		while (ft_is_space(*line))
			line++;
		if (*line == '\0')
			handle_error(game, "Missing texture path\n");
		*target = ft_strdup(line);
		return (0);
	}
	return (1);
}

void	texture_parser(t_game *game, char *line)
{
	if (set_texture_path(game, line, "NO", &game->textures.no_path) == 0)
		return ;
	else if (set_texture_path(game, line, "SO", &game->textures.so_path) == 0)
		return ;
	else if (set_texture_path(game, line, "WE", &game->textures.we_path) == 0)
		return ;
	else if (set_texture_path(game, line, "EA", &game->textures.ea_path) == 0)
		return ;
	else
		handle_error(game, "Unknown texture identifier\n");
}
