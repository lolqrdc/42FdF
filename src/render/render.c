/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:50:44 by loribeir          #+#    #+#             */
/*   Updated: 2025/02/23 17:21:26 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    calc_scale(t_fdf *fdf)
{
    int max;

    max = fdf->map->width * fdf->map->height;
    fdf->scale = 40; // base 
    if (max > 50)
        fdf->scale = 20;
    if (max > 100)
        fdf->scale = 10;
    if (max > 200)
        fdf->scale = 5; 
}
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
