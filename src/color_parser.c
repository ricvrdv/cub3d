#include "../inc/cub3d.h"

static int rgb_checker(t_game *game, char **line, int index)
{
	int value;

	value = ft_atoi(*line);
	while (ft_isdigit(**line))
		(*line)++;
	if (index < 2)
	{
		if (**line != ',')
			return (handle_error(game, "Invalid color format\n"), -1);
		(**line)++;
	}
	else
	{
		if (*line != NULL && **line != '\0' && !ft_is_space(**line))
			return (handle_error(game, "Extra characters after color\n"), -1);
	}
	if (value < 0 || value > 255)
		return (handle_error(game, "Color value out of range\n"), -1);
	return (value);
}

void color_parser(t_game *game, char *line)
{
	t_colors *target;

	if (*line == 'F')
		target = &game->floor;
	else if (*line == 'C')
		target = &game->ceiling;
	else
		return (handle_error(game, "Unknown color identifier\n"));
	target.id = *line;
	line++;
	while (ft_is_space(*line))
		line++;
	target->r_code = rgb_checker(game, &line, 0);
	target->g_code = rgb_checker(game, &line, 1);
	target->b_code = rgb_checker(game, &line, 2);
}
