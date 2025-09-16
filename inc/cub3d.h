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
# include <X11/X.h>
# include <X11/keysym.h>
# include "libft/libft.h"
# include "minilibx_linux/mlx.h"

typedef struct  s_img
{
    void    *img_ptr;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    int     width;
    int     height;
} t_img;

typedef struct  s_player
{
    bool    key_w;
    bool    key_s;
    bool    key_a;
    bool    key_d;
    bool    key_left;
    bool    key_right;
} t_player;

typedef struct  s_textures
{
    char    *no_path;
    char    *so_path;
    char    *we_path;
    char    *ea_path;
    t_img   north;
    t_img   south;
    t_img   west;
    t_img   east;
} t_textures;

typedef struct s_colors
{
    char    id;
    int     r_code;
    int     g_code;
    int     b_code;
}   t_colors;

typedef struct  s_game
{
    void        *mlx_ptr;
    void        *win_ptr;
    t_img       img;
    t_player    player;
    t_textures  textures;
    t_colors    floor;
    t_colors    ceiling;
} t_game;

// init
void    init_game(t_game *game);
int     input_checker(char *input);

//parser
int     skip_spaces(char *line);
int     handle_line(t_game *game, char *line);
int     parser(t_game *game, char *filename);

//color_parser
void    color_parser(t_game *game, char *line);

//texture_parser
void    texture_parser(t_game *game, char *line);

// events
int     handle_keypress(int keysym, t_game *game);
int     handle_keyrelease(int keysym, t_player *player);
int     close_window(t_game *game);

// render
int     render_frame(t_game *game);

// clean
void    clean_game(t_game *game);

// utils
void    setup_hooks(t_game *game);
void    load_textures(t_game *game);
void    put_pixel(t_img *img, int x, int y, int color);
void    handle_error(t_game *game, char *message);

#endif
