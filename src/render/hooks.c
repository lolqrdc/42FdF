/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:00:00 by loribeir          #+#    #+#             */
/*   Updated: 2025/02/24 11:11:09 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	setup_hooks(t_fdf *fdf)
{
	mlx_key_hook(fdf->windows, keyboard_handler, fdf);
	mlx_hook(fdf->windows, 17, 0, close_window, fdf);
}

int	keyboard_handler(int keycode, t_fdf *fdf)
{
	if (keycode == 65307)
		close_window(fdf);
	return (0);
}

int	close_window(t_fdf *fdf)
{
	if (fdf->img && fdf->img->image)
	{
		mlx_destroy_image(fdf->mlx, fdf->img->image);
		fdf->img->image = NULL;
	}
	if (fdf->windows)
	{
		mlx_destroy_window(fdf->mlx, fdf->windows);
		fdf->windows = NULL;
	}
	if (fdf->mlx)
	{
		mlx_destroy_display(fdf->mlx);
		fdf->mlx = NULL;
	}
	exit(0);
}
