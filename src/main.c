/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:54:15 by lolq              #+#    #+#             */
/*   Updated: 2025/02/13 13:06:28 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
    t_fdf   *fdf;

    fdf = malloc(sizeof(t_fdf));
    if (argc < 2)
        return (ft_putstr_fd("Error: not enough arguments.\n", 2), FAIL);
    if (argc == 2)
        parsing_map(fdf->map, argv[1]);
    free(fdf);
    return (SUCCESS);
}
