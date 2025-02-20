/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:50:44 by loribeir          #+#    #+#             */
/*   Updated: 2025/02/20 17:32:08 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    render_map(t_fdf *fdf)
{
    int i;
    int total_pts;

    i = 0;
    fdf->points = create_3dpoints(fdf);
    total_pts = fdf->map->height * fdf->map->width;
    while (i < total_pts)
    {
        project_2d(&fdf->points[i]);
        i++;
    }
    center_map(fdf);
}
