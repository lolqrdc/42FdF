/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:37:59 by loribeir          #+#    #+#             */
/*   Updated: 2025/02/20 15:31:50 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief: create 3D point array from map data, implement 3D to 2D conversion
 * function (iso proj), create 2D point array from 3D points.
 */

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

void    project_2d(t_point *point)
{
    float   tmp_x;
    float   tmp_y;
    
    tmp_x = point->x;
    tmp_y = point->y;
    point->screen_x = (tmp_x - tmp_y) * cos(ANGLE);
    point->screen_x = -point->z + (tmp_x + tmp_y) * sin(ANGLE);
}

/*void    apply_zoom(t_point *point, t_fdf *fdf)
{
    point->screen_x *= ZOOM;
    point->screen_y *= ZOOM;
}*/
void    center_map(t_fdf *fdf)
{
    int i;
    int total_pts;

    i = 0;
    total_pts = fdf->map->height * fdf->map->width;
    while (i < total_pts)
    {
        fdf->points[i].screen_x += (WIN_WIDTH / 2);
        fdf->points[i].screen_y += (WIN_HEIGHT / 2);
        i++;
    }
}
