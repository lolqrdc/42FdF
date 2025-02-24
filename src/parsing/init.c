/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 21:58:15 by lolq              #+#    #+#             */
/*   Updated: 2025/02/24 13:15:01 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_fdf(t_fdf *fdf)
{
	fdf->map = malloc(sizeof(t_map));
	if (!fdf->map)
		print_error("Error: malloc failed");
	fdf->img = malloc(sizeof(t_img));
	if (!fdf->img)
		print_error("Error: malloc failed");
	fdf->mlx = NULL;
	fdf->windows = NULL;
	fdf->x = 0;
	fdf->y = 0;
	fdf->scale = 1.0;
	fdf->points = NULL;
	fdf->map->width = 0;
	fdf->map->height = 0;
	fdf->map->matrice = NULL;
	fdf->img->image = NULL;
	fdf->img->img_addr = NULL;
	fdf->img->bits_pixel = 0;
	fdf->img->line_length = 0;
	fdf->img->endian = 0;
}

int	init_components(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	if (fdf->mlx == NULL)
		return (cleanup_fdf(fdf), print_error("Initialization mlx failed"), 1);
	fdf->windows = mlx_new_window(fdf->mlx, WIN_WIDTH, WIN_HEIGHT, "FdF");
	if (fdf->windows == NULL)
	{
		mlx_destroy_window(fdf->mlx, fdf->windows);
		return (cleanup_fdf(fdf), FAIL);
	}
	fdf->img->image = mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT);
	fdf->img->img_addr = mlx_get_data_addr(fdf->img->image,
			&fdf->img->bits_pixel,
			&fdf->img->line_length, &fdf->img->endian);
	render_map(fdf);
	draw_map(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->windows, fdf->img->image, 0, 0);
	setup_hooks(fdf);
	mlx_loop(fdf->mlx);
	return (SUCCESS);
}
