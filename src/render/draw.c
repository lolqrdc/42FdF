/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolq <lolq@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:32:33 by loribeir          #+#    #+#             */
/*   Updated: 2025/02/24 21:14:53 by lolq             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief setting the color of a specific pixel, it will checks if the pixel
 * coords are in the window boundaries. If valid, will calculate the memory
 * addr of the pixel and set a color.
 */
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

/**
 * @brief init necessary params to do draw the line. It will calc
 * the abs differences in x and y coords, determine the direction of 
 * movement according to a start and end points. 
 */
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

/**
 * @brief implementation of the Bresenham's line algo. Enter in a loop
 * that continues until the end point is reached. To each iteration it
 * will draw the current pixel, update x and y coords. 
 */
void	draw_line(t_fdf *fdf, t_point *first, t_point *end)
{
	t_line	line;
	t_point	tmp;

	tmp = *first;
	init_line(&line, &tmp, end);
	while (1)
	{
		put_pixel(fdf, tmp.screen_x, tmp.screen_y, RED);
		if (tmp.screen_x == end->screen_x
			&& tmp.screen_y == end->screen_y)
			break ;
		if (2 * line.error >= line.dy && tmp.screen_x != end->screen_x)
		{
			line.error += line.dy;
			tmp.screen_x += line.sx;
		}
		if (2 * line.error <= line.dx && tmp.screen_y != end->screen_y)
		{
			line.error += line.dx;
			tmp.screen_y += line.sy;
		}
	}
}

/**
 * @brief draw the entire map by connecting points with lines. 
 * It will iterates through all points in the map. For each point,
 * it draws a horizontal and vertical line to the next point (if it exist).
 */
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
