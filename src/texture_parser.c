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

static int	set_texture_path(char *line, const char *id, char **target)
{
	if (path_valid(line) == -1 || path_exists(line) == -1)
		return (ft_dprintf(2, "Error\nTexture path is not valid\n"), -1);
	if ((ft_strncmp(line, id, 2) == 0) && !*target)
	{
		line += 2;
		if (!ft_is_space(*line))
			return (ft_dprintf(2, "Error\nUnknown texture identifier\n"), -1);
		while (ft_is_space(*line))
			line++;
		if (*line == '\0')
			return (ft_dprintf(2, "Error\nMissing texture path\n"), -1);
		*target = ft_strdup(line);
		return (0);
	}
	return (-1);
}

int	texture_parser(t_game *game, char *line)
{
	if (set_texture_path(line, "NO", &game->textures.no_path) == 0)
		return (0);
	else if (set_texture_path(line, "SO", &game->textures.so_path) == 0)
		return (0);
	else if (set_texture_path(line, "WE", &game->textures.we_path) == 0)
		return (0);
	else if (set_texture_path(line, "EA", &game->textures.ea_path) == 0)
		return (0);
	else
		return (ft_dprintf(2, "Error\nUnknown texture identifier\n"), -1);
}
