/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:32:33 by loribeir          #+#    #+#             */
/*   Updated: 2025/02/24 11:10:31 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_fdf *fdf, int x, int y, int color)
{
	char	*tmp;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		tmp = fdf->img->img_addr + (y * fdf->img->line_length
				+ x * (fdf->img->bits_pixel / 8));
		*(unsigned int *)tmp = color;
	}
}

void	init_line(t_line *line, t_point *first, t_point *end)
{
	line->dx = abs(end->screen_x - first->screen_x);
	line->dy = -abs(end->screen_y - first->screen_y);
	if (first->screen_x < end->screen_x)
		line->sx = 1;
	else
		line->sx = -1;
	if (first->screen_y < end->screen_y)
		line->sy = 1;
	else
		line->sy = -1;
	line->error = line->dx + line->dy;
}

void	draw_line(t_fdf *fdf, t_point *first, t_point *end)
{
	t_line	line;

	init_line(&line, first, end);
	while (1)
	{
		put_pixel(fdf, first->screen_x, first->screen_y, RED);
		if (first->screen_x == end->screen_x
			&& first->screen_y == end->screen_y)
			break ;
		if (2 * line.error >= line.dy && first->screen_x != end->screen_x)
		{
			line.error += line.dy;
			first->screen_x += line.sx;
		}
		if (2 * line.error <= line.dx && first->screen_y != end->screen_y)
		{
			line.error += line.dx;
			first->screen_y += line.sy;
		}
	}
}

void	draw_map(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->map->height)
	{
		j = 0;
		while (j < fdf->map->width)
		{
			if (j + 1 < fdf->map->width)
				draw_line(fdf, &fdf->points[i * fdf->map->width + j],
					&fdf->points[i * fdf->map->width + j + 1]);
			if (i + 1 < fdf->map->height)
				draw_line(fdf, &fdf->points[i * fdf->map->width + j],
					&fdf->points[(i + 1) * fdf->map->width + j]);
			j++;
		}
		i++;
	}
}
