#include "../inc/cub3d.h"

static int	set_texture_path(t_game *game, char *line, const char *id, char **target)
{
	if (ft_strncmp(line, id, 3) == 0)
	{
		line += 2;
		while (ft_is_space(*line))
			line++;
		if (*line == '\0')
			handle_error (game, "Missing texture path\n");
		*target = ft_strdup(line);
		return (0);
	}
	return (1);
}

void	texture_parser(t_game *game, char *line)
{
	int match;

	match = 0;
	set_texture_path(game, line, "NO", &game->textures.no_path);
	set_texture_path(game, line, "SO", &game->textures.so_path);
	set_texture_path(game, line, "WE", &game->textures.we_path);
	set_texture_path(game, line, "EA", &game->textures.ea_path);
	if (match == 1)
		handle_error(game, "Unknown texture identifier\n");
}
