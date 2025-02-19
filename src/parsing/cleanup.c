/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:43:16 by loribeir          #+#    #+#             */
/*   Updated: 2025/02/19 11:29:18 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    free_tab(char **tab)
{
    int i;

    i = 0;
    while (tab)
        free(tab[i++]);
    free(tab);
}

void    free_matrice(t_fdf *fdf)
{
    int i;
    
    i = 0;
    while (i < fdf->map->height)
        free(fdf->map->matrice[i++]);
    free(fdf->map->matrice);
}
