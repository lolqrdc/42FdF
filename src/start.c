/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolq <lolq@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:30:00 by loribeir          #+#    #+#             */
/*   Updated: 2025/02/18 20:33:24 by lolq             ###   ########.fr       */
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
    fdf->img->img_addr = mlx_get_data_addr(fdf->img->image, fdf->img->bits_pixel,
                                           fdf->img->line_length, fdf->img->endian);
    return (SUCCESS);
}

/*check_file: check if the file is correct.*/
int check_file(char *file)
{
    char *ext;

    if (!file)
        return (print_error("Error: file is NULL\n"), FAIL);
    ext = ft_strrchr(file, '.');
    if (!ext || ft_strncmp(ext, ".fdf", 4) != 0)
        return (print_error("Error: invalid file\n"), FAIL);
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
        return (print_error("Error: failed to open file\n"), FAIL);
    line = get_next_line(fd);
    if (!line)
        return (print_error("Error: map is empty\n"), FAIL);
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
/*check_map: compare the row and colums to check if the map is consistent.*/
void check_map(t_map *map, char *file)
{
    char *line;
    char **tab;
    int fd;
    int i;

    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (print_error("Error: failed to open file\n"));
    line = get_next_line(fd);
    while (line)
    {
        i = 0;
        tab = ft_split(line, ' ');
        free(line);
        while (tab[i])
            i++;
        free_tab(tab);
        if (i != map->width)
            return (close(fd), print_error("Error: wrong map format\n"));
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
}
/*parse_map: malloc for the matrix and add correct infos into it.*/
void parse_map(t_fdf *fdf, char *file)
{
    int     i;    
    int     fd;
    char    *line;
    char    **tab;

    fdf->map->matrice = malloc(sizeof(int *) * fdf->map->height);
    if (!fdf->map->matrice)
        return (print_error("Error: malloc failed\n"));
    i = 0;
    while (i < fdf->map->height)
    {
        fdf->map->matrice[i] = malloc(sizeof(int) * fdf->map->width);
        if (!fdf->map->matrice[i])
            return(free_matrice(fdf->map), print_error("Error: malloc failed\n"));
    }
    
}
