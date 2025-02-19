/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:54:15 by lolq              #+#    #+#             */
/*   Updated: 2025/02/19 12:07:57 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    init_fdf(t_fdf *fdf)
{

}

int main(int argc, char **argv)
{
    t_fdf *fdf;

    fdf = malloc(sizeof(t_fdf));
    if (argc != 2)
        return (free(fdf), print_error("Usage: ./fdf <filename>"), FAIL);
    if (!fdf)
        return(print_error("Error: allocation failed"), FAIL);
    fdf->y = 0;
    fdf->x = 0;
    calc_map(fdf->map, argv[1]);
    parse_map(fdf, argv[1]);
    if (init_components(fdf) != 0)
        return (FAIL);
    return(0);
}

