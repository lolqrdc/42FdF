/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:13:48 by lolq              #+#    #+#             */
/*   Updated: 2025/02/13 11:04:23 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/* LIBRAIRIES */
# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"
# include "../libft/include/get_next_line.h"
# include "./minilibx-linux/mlx.h"
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

/* MES DEFINES */
# define FAIL 1
# define SUCCESS 0

typedef struct s_img
{
    void    *image; // ptr to the image created by mlx.
    char    *addr; // address of the 1st pixel of the image.
    int     bits_pixel; // bits per pixel.
    int     line_length;
    int     endian;
} t_img;

typedef struct s_map
{
    int     **z_matrice; // matrice stocking the height values.
    int     height; // nbr of row in the map.
    int     width; // nbr of columms in the map.
    int     len; // length of the map.
} t_map;

typedef struct s_fdf
{
    void    *mlx; // ptr to the mlx instance.
    void    *windows; // ptr to the created window.
    t_img   img; // struct containing image information.
    t_map   map; // struct containing info of the map(s).
    int     c_x; // control the pos X of the rendered map.
    int     c_y; // control the pos Y of the rendered map.
} t_fdf;

/* FUNCTIONS */
int main(int argc, char **argv);

/* PARSING */
t_map   parsing_map(t_map map, char *file);
bool    check_file_name(char *file);
void    handle_error(char *msg, int code);

/* INITIALIZATION */
void    map_dimension(t_map *map, char *file);
void    map_matrice(t_map *map, char *file);
int    init_matrice(char *file, t_map *map);

/* UTILS */
void    free_tab(char **tab);
void    free_map(t_map *map);

#endif 