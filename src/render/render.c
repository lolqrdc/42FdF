/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:50:44 by loribeir          #+#    #+#             */
/*   Updated: 2025/02/23 18:17:36 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    render_map(t_fdf *fdf)
{
    int i;
    int total_pts;

    i = 0;
    fdf->points = create_3dpoints(fdf);
    calc_scale(fdf);
    total_pts = fdf->map->height * fdf->map->width;
    while (i < total_pts)
    {
        project_2d(&fdf->points[i], fdf->scale);
        i++;
    }
    center_map(fdf);
    draw_map(fdf);
}

void    center_map(t_fdf *fdf)
{
    int i;
    int total_pts;

    i = 0;
    total_pts = fdf->map->height * fdf->map->width;
    while (i < total_pts)
    {
        fdf->points[i].screen_x += WIN_WIDTH / 2;
        fdf->points[i].screen_y += WIN_HEIGHT / 2;
        i++;
    }
}

void    calc_scale(t_fdf *fdf)
{
    float   w_scale;
    float   h_scale;

    w_scale = (WIN_WIDTH * 0.6) / (fdf->map->width + fdf->map->height);
    h_scale = (WIN_HEIGHT * 0.6) / (fdf->map->height + fdf->map->width);
    fdf->scale = w_scale;
    if (h_scale < w_scale)
        fdf->scale = h_scale;
    if (fdf->scale < 2)
        fdf->scale = 2;
    if (fdf->scale > 30)
        fdf->scale = 30;
}
