/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolq <lolq@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:47:00 by lolq              #+#    #+#             */
/*   Updated: 2025/02/12 18:14:52 by lolq             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief: 
 */
t_map   parsing_map(char *file)
{
    t_map   map;

    if (!check_file_name(file))
    {
        handle_error("Error: invalid file name", 1);
        return (map);
    }
    init_matrice(file, &map);
    return (map);
}

bool    check_file_name(char *file)
{
    int len;

    len = ft_strlen(file);
    if (len < 4)
        return (false);
    if (ft_strcmp(file + len - 4, ".fdf") == 0)
        return (true);
    return (false);
}

void handle_error(char *msg, int code)
{
    ft_putstr_fd(msg, 2);
    exit(code);
}