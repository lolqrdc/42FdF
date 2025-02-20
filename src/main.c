/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:54:15 by lolq              #+#    #+#             */
/*   Updated: 2025/02/20 17:37:50 by loribeir         ###   ########.fr       */
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
        return (free(fdf->mlx), FAIL);
    fdf->img->image = mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT);
    fdf->img->img_addr = mlx_get_data_addr(fdf->img->image, &fdf->img->bits_pixel,
                                           &fdf->img->line_length, &fdf->img->endian);
    // transform and render the map
    render_map(fdf);
    mlx_loop(fdf->mlx);
    return (SUCCESS);
}

int main(int argc, char **argv)
{
    t_fdf *fdf;

    fdf = malloc(sizeof(t_fdf));
    if (argc != 2)
        return (free(fdf), print_error("Usage: ./fdf <filename>"), FAIL);
    if (!fdf)
        return(print_error("Error: allocation failed"), FAIL);
    if (get_map(fdf, argv[1]) != SUCCESS)
        return (free(fdf), FAIL);
    if (init_components(fdf) != SUCCESS)
        return (free(fdf), FAIL);
    return(0);
}

