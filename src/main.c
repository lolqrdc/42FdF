/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:54:15 by lolq              #+#    #+#             */
/*   Updated: 2025/02/20 10:00:48 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    init_fdf(t_fdf *fdf)
{
    fdf->map = malloc(sizeof(t_map));
    if (!fdf->map)
        print_error("Error: malloc failed");
    fdf->img = malloc(sizeof(t_img));
    if (!fdf->img)
        print_error("Error: malloc failed");
    fdf->x = 0;
    fdf->y = 0;
    fdf->map->width = 0;
    fdf->map->height = 0;
    fdf->map->matrice = NULL;
}

int main(int argc, char **argv)
{
    t_fdf *fdf;

    fdf = malloc(sizeof(t_fdf));
    if (argc != 2)
        return (free(fdf), print_error("Usage: ./fdf <filename>"), FAIL);
    if (!fdf)
        return(print_error("Error: allocation failed"), FAIL);
    if (get_map(fdf, argv[1]) != SUCCESS)
        return (free(fdf), FAIL);
    if (init_components(fdf) != SUCCESS)
        return (free(fdf), FAIL);
    return(0);
}

