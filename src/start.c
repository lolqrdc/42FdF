/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:30:00 by loribeir          #+#    #+#             */
/*   Updated: 2025/02/18 08:12:48 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief initializes mlx components and parsing. 
 */

int    check_file(char *file)
{
    int len;

    len = ft_strlen(file);
    if (!file)
        return (FAIL);
    if (len < 4)
        return (FAIL);
    if (ft_strncmp(file + len - 4, ".fdf", 4) == 0)
        return (SUCCESS);
    return (FAIL);
}

void    check_format(t_fdf *fdf, char *file)
{
    int     i;
    int     fd;
    char    *line;
    char    **tab;
    
    i = 0;
    fd = open(file, O_RDONLY);
    line = get_next_line(fd);
    while (line)
    {
        tab = ft_split(line, ' ');
        free(line);
        while (tab[i])
            free(tab[i++]);
        free(tab);
        if (i < fdf->map.width || i > fdf->map.height)
            ft_putstr_fd("Error: please provide a correct map format.\n", 2);
        line = get_next_line(fd);
    }
    free(line);
    close (fd);
}
