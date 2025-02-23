/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:37:59 by loribeir          #+#    #+#             */
/*   Updated: 2025/02/23 16:36:28 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point *create_3dpoints(t_fdf *fdf)
{
    int     total_pts;
    t_point *pts;

    total_pts = fdf->map->height * fdf->map->width;
    pts = malloc(sizeof(t_point) * total_pts);
    if (!pts)
        print_error("Error: malloc failed\n");
    fdf->x = 0;
    fdf->y = 0;
    while (fdf->y < fdf->map->height)
    {
        pts[fdf->y * fdf->map->width + fdf->x].x = fdf->x;
        pts[fdf->y * fdf->map->width + fdf->x].y = fdf->y;
        pts[fdf->y * fdf->map->width + fdf->x].z = fdf->map->matrice[fdf->y][fdf->x];
        fdf->x++;
        if (fdf->x == fdf->map->width)
        {
            fdf->x = 0;
            fdf->y++;
        }
    }
    return (pts);
}

void    project_2d(t_point *point, float scale)
{
    int sca_x;
    int sca_y;
    int sca_z;

    sca_x = point->x * scale;
    sca_y = point->y * scale;
    sca_z = point->z * scale;
    point->screen_x = (sca_x - sca_y) * cos(ANGLE);
    point->screen_y = (sca_x + sca_y) * sin(ANGLE) - sca_z;
}

void    center_map(t_fdf *fdf)
{
    int i;
    int total_pts;
    float   off_x;
    float   off_y;
    i = 0;
    total_pts = fdf->map->height * fdf->map->width;
    off_x = (WIN_WIDTH / 2) - ((fdf->map->width * fdf->scale) / 2);
    off_y = (WIN_HEIGHT / 2) - ((fdf->map->height * fdf->scale) / 2);
    while (i < total_pts)
    {
        fdf->points[i].screen_x += off_x;
        fdf->points[i].screen_y += off_y;
        i++;
    }
}
