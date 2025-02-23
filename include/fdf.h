/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolq <lolq@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:13:48 by lolq              #+#    #+#             */
/*   Updated: 2025/02/23 22:26:28 by lolq             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/* LIBRAIRIES */
# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"
# include "../libft/include/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <stdbool.h>
# include <errno.h>


/* WINDOW SETTINGS */
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define ANGLE 0.523599
# define ZOOM 30

/* COLORS */
# define WHITE 0xFFFFFF
# define RED 0xFF0000

/* DEFINE */
# define FAIL 1
# define SUCCESS 0

typedef struct s_point
{
    float x; // 3D
    float y; // 3D
    float z;
    int screen_x; // projection 2D.
    int screen_y; // projection 2D.
} t_point;

typedef struct t_line
{
    int dx;
    int dy;
    int sx;
    int sy;
    int error;
} t_line;
typedef struct s_img
{
    void    *image; // ptr to the image created by mlx.
    char    *img_addr; // address of the 1st pixel of the image.
    int     bits_pixel; // bits per pixel.
    int     line_length;
    int     endian;
} t_img;

typedef struct s_map
{
    int     **matrice; // matrice stocking the height values.
    int     height; // nbr of row.
    int     width; // nbr of colummsp.
} t_map;

typedef struct s_fdf
{
    void    *mlx; // mlx instance.
    void    *windows; // window.
    t_img   *img; // image data.
    t_map   *map; // map data.
    t_point center; // centre de l'ecran.
    t_point *points;
    int     scale; // scale.
    int     x;
    int     y;
} t_fdf;

/* main.c: */
int     main(int argc, char **argv);

/* parsing.c: init.c */
int     init_components(t_fdf *fdf);
void    init_fdf(t_fdf *fdf);

/*parsing: parsing.c */
void    check_file(char *file);
int     print_error(char *message);

/*parsing: cleanup.c */
void    free_tab(char **tab);
void    free_matrice(t_fdf *fdf);

/*parsing: map_info.c */
int     get_map(t_fdf *fdf, char *file);
void    calc_map(t_map *map, char *file);
void    parse_map(t_fdf *fdf, char *file);
void    init_matrice(t_fdf *fdf);

/*render: points.c */
t_point *create_3dpoints(t_fdf *fdf);
void    project_2d(t_point *point, float scale);

/*render: draw.c */
void    put_pixel(t_fdf *fdf, int x, int y, int color);
void    init_line(t_line *line, t_point *first, t_point *end);
void    draw_line(t_fdf *fdf, t_point *first, t_point *end);
void    draw_map(t_fdf *fdf);

/*render: hooks.c */
int     close_window(t_fdf *fdf);
int     keyboard_handler(int keycode, t_fdf *fdf);
int     mouse_handler(int mouse, int x, int y, t_fdf *fdf);
void    setup_hooks(t_fdf *fdf);

/*render: render.c */
void    render_map(t_fdf *fdf);
void    calc_scale(t_fdf *fdf);
void    center_map(t_fdf *fdf);


#endif