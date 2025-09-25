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
	char	*clean_path;
	int		fd;

	path = line;
	while (*path && !ft_is_space(*path))
		path++;
	while (*path && ft_is_space(*path))
		path++;
	clean_path = ft_strtrim(path, " ");
	fd = open(clean_path, O_RDONLY);
	if (fd == -1)
		return (free(clean_path), -1);
	close(fd);
	free(clean_path);
	return (0);
}

static int	set_texture_path(char *line, char **target)
{
	char	*clean_line;

	if (!*target)
	{
		if (path_valid(line) == -1 || path_exists(line) == -1)
			return (ft_dprintf(2, "Error\nTexture path is not valid\n"), -1);
		line += 2;
		if (!ft_is_space(*line))
			return (ft_dprintf(2, "Error\nUnknown texture identifier\n"), -1);
		while (ft_is_space(*line))
			line++;
		if (*line == '\0')
			return (ft_dprintf(2, "Error\nMissing texture path\n"), -1);
		clean_line = ft_strtrim(line, " ");
		*target = ft_strdup(clean_line);
		free(clean_line);
		return (0);
	}
	return (ft_dprintf(2, "Error\nTexture duplicate\n"), -1);
}

int	texture_parser(t_game *game, char *line)
{
	if ((ft_strncmp(line, "NO", 2) == 0))
		return (set_texture_path(line, &game->textures.no_path));
	else if ((ft_strncmp(line, "SO", 2) == 0))
		return (set_texture_path(line, &game->textures.so_path));
	else if ((ft_strncmp(line, "WE", 2) == 0))
		return (set_texture_path(line, &game->textures.we_path));
	else if ((ft_strncmp(line, "EA", 2) == 0))
		return (set_texture_path(line, &game->textures.ea_path));
	else
		return (ft_dprintf(2, "Error\nUnknown texture identifier\n"), -1);
}
