/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:30:00 by loribeir          #+#    #+#             */
/*   Updated: 2025/02/20 15:53:14 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief: The goal is to get all necessary info about the map passed as argu-
 * ment, to store the map data. 
 */

/*get_map: call all necessary functions to get a map. */
int get_map(t_fdf *fdf, char *file)
{
    init_fdf(fdf);
    calc_map(fdf->map, file);
    init_matrice(fdf);
    parse_map(fdf, file);
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
    if (!tab)
        print_error("Error: split failed\n");
    while (tab[map->width])
        map->width++;
    map->height++;
    free_tab(tab);
    free(line);
    while ((line = get_next_line(fd)) != NULL)
    {
        map->height++;
        free(line);
    }
    close(fd);
}

/*parse_map: malloc for the matrix and add correct infos into it.*/
void parse_map(t_fdf *fdf, char *file)
{
    int     fd;
    char    *line;
    char    **tab;
    
    fd = open(file, O_RDONLY);
    fdf->y = 0;
    while ((line = get_next_line(fd)) && fdf->y < fdf->map->height)
    {
        tab = ft_split(line, ' ');
        fdf->x = 0;
        while (tab[fdf->x] && fdf->x < fdf->map->width)
        {
            fdf->map->matrice[fdf->y][fdf->x] = ft_atoi(tab[fdf->x]);
            fdf->x++;
        }
        free_tab(tab);
        free(line);
        fdf->y++;
    }
    close(fd);
}

/*init_matrice: malloc matrix and set default values.*/
void    init_matrice(t_fdf *fdf)
{
    int i;
    int j;

    fdf->map->matrice = malloc(sizeof(int *) * fdf->map->height);
    if (!fdf->map->matrice)
        print_error("Error: malloc failed");
    i = 0;
    while (i < fdf->map->height)
    {
        fdf->map->matrice[i] = malloc(sizeof(int) * fdf->map->width);
        if (!fdf->map->matrice[i])
            print_error("Error: malloc failed");
        j = 0;
        while (j < fdf->map->width)
        {
            fdf->map->matrice[i][j] = 0;
            j++;
        }
        i++;
    }
}
