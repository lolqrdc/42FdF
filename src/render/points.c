/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:37:59 by loribeir          #+#    #+#             */
/*   Updated: 2025/02/24 11:13:52 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*create_3dpoints(t_fdf *fdf)
{
	t_point	*pts;
	int		total_pts;

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
		pts[fdf->y * fdf->map->width + fdf->x].z
			= fdf->map->matrice[fdf->y][fdf->x];
		fdf->x++;
		if (fdf->x == fdf->map->width)
		{
			fdf->x = 0;
			fdf->y++;
		}
	}
	return (pts);
}

void	project_2d(t_point *point, float scale)
{
	int	sca_x;
	int	sca_y;
	int	sca_z;

	sca_x = point->x * scale;
	sca_y = point->y * scale;
	sca_z = point->z * scale;
	point->screen_x = (sca_x - sca_y) * cos(ANGLE);
	point->screen_y = (sca_x + sca_y) * sin(ANGLE) - sca_z;
}
