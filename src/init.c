#include "../inc/cub3d.h"

void    init_game(t_game *game)
{
    game->mlx_ptr = mlx_init();
    if (!game->mlx_ptr){}
        //handle_error(game, "Failed to initialize MinilibX.\n");
    game->win_ptr = mlx_new_window(game->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "CUB3D");
    if (!game->win_ptr){}
        //handle_error(game, "Failed to open window.\n");
    game->img.img_ptr = mlx_new_image(game->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
    if (!game->img.img_ptr){}
        //handle_error(game, "Failed to create image buffer.\n");
    game->img.addr = mlx_get_data_addr(game->img.img_ptr,
        &game->img.bits_per_pixel, &game->img.line_length,
        &game->img.endian);
    game->img.width = WIN_WIDTH;
    game->img.height = WIN_HEIGHT;
    load_textures(game);
}

//info --> check if a string is numbers, letters or symbols

int	ft_str_isalnum(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (c[i] >= 33 && c[i] <= 126)
			i++;
		else
			return (0);
	}
	return (1);
}

char *input_checker(t_game *game, char *input)
{
	char	**split;

	split = ft_split(input, '.');
	if (!split[1] || !ft_str_isalnum(split[0]))
	{
		handle_error(game, "File must be .cub type\n");
		return (free_arrays((void **)split), NULL);
	}
	if (ft_strncmp(split[1], "cub", 4) == 0)
		return (free_arrays((void **)split), input);
	else
	{
		handle_error(game, "File must be .cub type\n");
		return (free_arrays((void **)split), NULL);
	}
}
