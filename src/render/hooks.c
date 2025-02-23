/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolq <lolq@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:00:00 by loribeir          #+#    #+#             */
/*   Updated: 2025/02/23 22:38:31 by lolq             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int keyboard_handler(int keycode, t_fdf *fdf)
{
    if (keycode == 65307)
        close_window(fdf);
    return (0);
}

int close_window(t_fdf *fdf)
{
    mlx_destroy_window(fdf->mlx, fdf->windows);
    exit (0);
}

void    setup_hooks(t_fdf *fdf)
{
    mlx_key_hook(fdf->windows, keyboard_handler, fdf);
    mlx_hook(fdf->windows, 17, 0, close_window, fdf);
}
