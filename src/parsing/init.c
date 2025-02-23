/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolq <lolq@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 21:58:15 by lolq              #+#    #+#             */
/*   Updated: 2025/02/23 22:27:20 by lolq             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    init_fdf(t_fdf *fdf)
{
    fdf->map = malloc(sizeof(t_map));
    if (!fdf->map)
        print_error("Error: malloc failed");
    fdf->img = malloc(sizeof(t_img));
    if (!fdf->img)
        print_error("Error: malloc failed");
    fdf->x = 0;
    fdf->y = 0;
    fdf->map->width = 0;
    fdf->map->height = 0;
    fdf->map->matrice = NULL;
}

int init_components(t_fdf *fdf)
{
    fdf->mlx = mlx_init();
    if (fdf->mlx == NULL)
        return (print_error("Error: initialization mlx failed\n"), FAIL);
    fdf->windows = mlx_new_window(fdf->mlx, WIN_WIDTH, WIN_HEIGHT, "FdF");
    if (fdf->windows == NULL)
        return (free(fdf->mlx), free(fdf->mlx), FAIL);
    fdf->img->image = mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT);
    fdf->img->img_addr = mlx_get_data_addr(fdf->img->image, &fdf->img->bits_pixel,
                                           &fdf->img->line_length, &fdf->img->endian);
    render_map(fdf);
    draw_map(fdf);
    mlx_put_image_to_window(fdf->mlx, fdf->windows, fdf->img->image, 0, 0);
    setup_hooks(fdf);
    mlx_loop(fdf->mlx);
    return (SUCCESS);
}
