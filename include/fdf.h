/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolq <lolq@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:13:48 by lolq              #+#    #+#             */
/*   Updated: 2025/02/18 20:30:37 by lolq             ###   ########.fr       */
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
    int     zoom; // scale.
    int     x;
    int     y;
} t_fdf;

/* main.c: */
int main(int argc, char **argv);
int print_error(char *message);

/*start.c: */
int     check_file(char *file);
void    calc_map(t_map *map, char *file);
void    check_map(t_map *map, char *file);
void    parse_map(t_fdf *fdf, char *file)

#endif 