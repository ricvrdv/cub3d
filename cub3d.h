#ifndef CUB3D_H
# define CUB3D_H

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <stdbool.h>

typedef struct  s_game
{
    void    *mlx_ptr;
    void    *win_ptr;
} t_game;

void    init_game(t_game *game);

int     handle_keypress(int keycode, t_game *game);
int     handle_keyrelease(int keycode, t_game *game);
int     exit_game(t_game *game);

#endif