#include "../inc/cub3d.h"

int parser(char *line)
{
	if (line[0] == 'F' || line[0] == 'C')
	{
		color_parser(line);
		return (0);
	}
	else if (line[0] == 'N' || line[0] == 'S' || line[0] == 'W' || line[0] == 'E')
	{
		texture_parser(line);
		return (0);
	}
	else if (line == '1' || line == ' ')
	{
		map_parser();
		return (0);
	}
	return (1);
}
