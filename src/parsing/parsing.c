/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:47:00 by lolq              #+#    #+#             */
/*   Updated: 2025/02/13 12:41:46 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/**
 * @brief: Check the name of the file and if the initialization
 * of the map is done correctly.
 */
t_map   parsing_map(t_map map, char *file)
{
    if (!check_file_name(file))
    {
        handle_error("Error: invalid file name", 1);
        return (map);
    }
    if (!init_matrice(file, &map))
    {
        handle_error("Error: failed to initialize the matrix.\n", 2);
        free_map(&map);
        return (map);
    }
    return (map);
}

bool    check_file_name(char *file)
{
    int len;

    len = ft_strlen(file);
    if (!file || len < 4)
        return (false);
    if (ft_strncmp(file + len - 4, ".fdf", 4) == 0)
        return (true);
    return (false);
}
