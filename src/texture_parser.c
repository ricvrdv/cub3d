#include "../inc/cub3d.h"

static int	set_texture_path(t_game *game, char *line, const char *id, char **target)
{
	if (ft_strncmp(line, id, 3) == 0)
	{
		line += 2;
		while (ft_is_space(*line))
			line++;
		if (*line == '\0')
			ft_dprintf(2, "Error\nMissing texture path\n");
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
		ft_dprintf(2, "Error\nUnknown texture identifier\n");
}
