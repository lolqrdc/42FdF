/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:13:48 by lolq              #+#    #+#             */
/*   Updated: 2025/02/24 13:31:41 by loribeir         ###   ########.fr       */
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
# define SCROLL_UP 5
# define SCROLL_DOWN 4

/* COLORS */
# define WHITE 0xFFFFFF
# define RED 0xFF0000

/* DEFINE */
# define FAIL 1
# define SUCCESS 0

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	int		screen_x;
	int		screen_y;
}	t_point;

typedef struct t_line
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	error;
}	t_line;
typedef struct s_img
{
	void	*image;
	char	*img_addr;
	int		bits_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_map
{
	int		**matrice;
	int		height;
	int		width;
}	t_map;

typedef struct s_fdf
{
	void	*mlx;
	void	*windows;
	t_img	*img;
	t_map	*map;
	t_point	center;
	t_point	*points;
	int		scale;
	int		x;
	int		y;
}	t_fdf;

/* main.c: */
int		main(int argc, char **argv);

/* parsing.c: init.c */
int		init_components(t_fdf *fdf);
void	init_fdf(t_fdf *fdf);

/*parsing: parsing.c */
void	check_file(char *file, t_fdf *fdf);
int		print_error(char *message);

/*parsing: cleanup.c */
void	free_tab(char **tab);
void	free_matrice(t_fdf *fdf);
void	cleanup_fdf(t_fdf *fdf);

/*parsing: map_info.c */
int		get_map(t_fdf *fdf, char *file);
void calc_map(t_map *map, int fd);
void	parse_map(t_fdf *fdf, char *file);
void	init_matrice(t_fdf *fdf);
void 	init_map(t_map *map, char *file);

/*render: points.c */
t_point	*create_3dpoints(t_fdf *fdf);
void	project_2d(t_point *point, float scale);

/*render: draw.c */
void	put_pixel(t_fdf *fdf, int x, int y, int color);
void	init_line(t_line *line, t_point *first, t_point *end);
void	draw_line(t_fdf *fdf, t_point *first, t_point *end);
void	draw_map(t_fdf *fdf);

/*render: hooks.c */
void	setup_hooks(t_fdf *fdf);
int		close_window(t_fdf *fdf);
int		keyboard_handler(int keycode, t_fdf *fdf);

/*render: render.c */
void	render_map(t_fdf *fdf);
void	calc_scale(t_fdf *fdf);
void	center_map(t_fdf *fdf);

#endif