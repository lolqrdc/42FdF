/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:30:00 by loribeir          #+#    #+#             */
/*   Updated: 2025/02/19 12:06:38 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*init_components: initialization for graphic variables. */
int init_components(t_fdf *fdf)
{
    fdf->mlx = mlx_init();
    if (fdf->mlx == NULL)
        return (perror("Error: initialization mlx failed\n"), FAIL);
    fdf->windows = mlx_new_window(fdf->mlx, WIN_WIDTH, WIN_HEIGHT, "FdF");
    if (fdf->windows == NULL)
        return (free(fdf->mlx), FAIL);
    fdf->img->image = mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT);
    fdf->img->img_addr = mlx_get_data_addr(fdf->img->image, &fdf->img->bits_pixel,
                                           &fdf->img->line_length, &fdf->img->endian);
    return (SUCCESS);
}


/*calc_map: calculate the nb of rows and colums to have the dimension of the map.*/
void calc_map(t_map *map, char *file)
{
    char *line;
    char **tab;
    int fd;

    fd = open(file, O_RDONLY);
    if (fd < 0)
        print_error("Error: failed to open file\n");
    line = get_next_line(fd);
    if (!line)
        print_error("Error: map is empty\n");
    tab = ft_split(line, ' ');
    while (tab[map->width])
        map->width++;
    while (line)
    {
        free(line);
        map->height++;
        line = get_next_line(fd);
    }
    free(tab);
    close(fd);
}

/*parse_map: malloc for the matrix and add correct infos into it.*/
void parse_map(t_fdf *fdf, char *file)
{
    int     fd;
    char    *line;
    char    **tab;
    
    fd = open(file, O_RDONLY);
    fdf->map->matrice = malloc(sizeof(int) * fdf->map->width);
    if (!fdf->map->matrice)
        print_error("Error: malloc failed");
    while ((line = get_next_line(fd)) && fdf->y < fdf->map->width)
    {
        tab = ft_split(line, ' ');
        fdf->x = 0;
        while (tab[fdf->x] && fdf->x < fdf->map->width)
        {
            fdf->map->matrice[fdf->x][fdf->y] = ft_atoi(tab[fdf->x]);
            fdf->x++;
        }
        free_tab(tab);
        free(line);
        fdf->y++;
    }
    close (fd);
}

/*init_matrice: malloc matrix and set default values.*/
void    init_matrice(t_fdf *fdf)
{
       
}