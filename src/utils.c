/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolq <lolq@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:26:48 by lolq              #+#    #+#             */
/*   Updated: 2025/02/13 18:34:40 by lolq             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    free_tab(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
        free(tab[i++]);
    free(tab);
}
void    free_map(t_map *map)
{
    int i;

    i = 0;
    if (map->z_matrice)
    {
        while (i < map->height)
            free(map->z_matrice[i++]);
        free(map->z_matrice);   
    }
    map->z_matrice = NULL;
    map->height = 0;
    map->width = 0;
}

void handle_error(char *message)
{
    ft_putstr_fd(message, 2);
}
