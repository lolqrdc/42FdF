/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:30:00 by loribeir          #+#    #+#             */
/*   Updated: 2025/02/18 14:07:04 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* initialisation pour ouvrir, afficher la fenetre. */
int init_components(t_fdf *fdf)
{
    fdf->mlx = mlx_init();
    if (fdf->mlx == NULL)
        return (perror("Error: initialization mlx failed\n"), FAIL);
    fdf->windows = mlx_new_window(fdf->mlx, WIN_WIDTH, WIN_HEIGHT, "FdF");
    if (fdf->windows == NULL)
        return (free(fdf->mlx), FAIL);
    fdf->img->image = mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT);
    fdf->img->img_addr = mlx_get_data_addr(fdf->img->image, fdf->img->bits_pixel, \
    fdf->img->line_length, fdf->img->endian);
    return (SUCCESS);
}

/* verifier si le fichier est correct. */
int check_file(char *file)
{
    char    *ext;

    if (!file)
        return (perror("Error: file is NULL\n"), FAIL);
    ext = ft_strrchr(file, '.');
    if (!ext || ft_strncmp(ext, ".fdf", 4) != 0)
        return(perror("Error: invalid file\n"), FAIL);
    return (SUCCESS);
}

/* calc_map: calculate the nb of rows and colums to have the dimension of the map. */
void    calc_map(t_map *map, char *file)
{

}
/* check_map: compare the row and colums to check if the map is consistent. */
void    check_map(t_map *map, char *file)
{
    
}
/* parse_map: malloc for the matrix and add correct infos into it. */
void    parse_map(t_map *map, char *file)
{
    
}
