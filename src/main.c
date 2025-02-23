/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolq <lolq@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:54:15 by lolq              #+#    #+#             */
/*   Updated: 2025/02/23 22:27:16 by lolq             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

