#include "cub3d.h"

static int rgb_checker(char **line, int index)
{
	int value;

	value = ft_atoi(*line);
	while (ft_isdigit(**line))
		(*line)++;
	if (index < 2)
	{
		while (ft_is_space(**line))
			(*line)++;
		if (**line != ',')
			return (ft_dprintf(2, "Error\nInvalid color format\n"), -1);
		(*line)++;
		while (ft_is_space(**line))
			(*line)++;
	}
	else
	{
		if (*line != NULL && **line != '\0' && !ft_is_space(**line))
			return (ft_dprintf(2, "Error\nExtra characters after color\n"), -1);
	}
	if (value < 0 || value > 255)
		return (ft_dprintf(2, "Error\nColor value out of range\n"), -1);
	return (value);
}

int color_parser(t_game *game, char *line)
{
	t_colors *target;

	if (*line == 'F' && !game->floor.id)
		target = &game->floor;
	else if (*line == 'C' && !game->ceiling.id)
		target = &game->ceiling;
	else
		return (ft_dprintf(2, "Error\nUnknown color identifier\n"), -1);
	target->id = *line;
	line++;
	while (ft_is_space(*line))
		line++;
	target->r_code = rgb_checker(&line, 0);
	if (target->r_code == -1)
		return (-1);
	target->g_code = rgb_checker(&line, 1);
	if (target->g_code == -1)
		return (-1);
	target->b_code = rgb_checker(&line, 2);
	if (target->b_code == -1)
		return (-1);
	return (0);
}
