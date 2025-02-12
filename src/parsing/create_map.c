/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolq <lolq@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:40:12 by lolq              #+#    #+#             */
/*   Updated: 2025/02/12 18:11:26 by lolq             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief: Count the number of row (height) and columms (width), plus 
 * create the matrice based on the height and width. 
 */

/* read line by line, count the nb of rows and columns. */
void    map_dimension(t_map *map, char *file)
{
    int     fd;
    char    *line;
    char    **split;

    fd = open(file, O_RDONLY);
    if (fd < 0)
        return ;
    map->height = 0;
    map->width = 0;
    while ((line = get_next_line(fd)))
    {
        if (map->height == 0)
        {
            split = ft_split(line, ' ');
            while (split[map->width])
                map->width++;
            free_split(split);
        }
        map->height++;
        free(line);
    }
    close(fd);
}
/* convert each line into int. Ints are stocked inside z_matrice of t_map. */
void    map_matrice(t_map *map, char *file)
{
    int     i;
    int     j;
    int     fd;
    char    *line;
    char    **split;

    fd = open(file, O_RDONLY);
    if (fd < 0)
        return ;
    i = 0;
    while ((line = get_next_line(fd)))
    {
        split = ft_split(line, ' ');
        j = 0;
        while (split[j])
        {
            map->z_matrice[i][j] = ft_atoi(split[j]);
            j++;
        }
        free_split(split);
        free(line);
        i++;
    }
    close(fd);
}
void    init_matrice(char *file, t_map *map)
{
    int i;

    i = 0;
    map->height = 0;
    map->width = 0;
    map->z_matrice = NULL;
    map_dimension(map, file);
    map->z_matrice = malloc(sizeof(int*) * map->height);
    if (map->z_matrice == NULL)
        return ;
    while (i < map->height)
    {
        map->z_matrice[i] = malloc(sizeof(int*) * map->width);
        if (map->z_matrice[i] == NULL)
            return ;
        i++;
    }
    map_matrice(map, file);
}
