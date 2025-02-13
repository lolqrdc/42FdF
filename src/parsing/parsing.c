/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolq <lolq@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:47:00 by lolq              #+#    #+#             */
/*   Updated: 2025/02/13 18:44:19 by lolq             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int    check_file_name(char *file)
{
    int len;

    if (!file)
        return (FAIL);
    len = ft_strlen(file);
    if (len < 4)
        return (FAIL);
    if (ft_strncmp(file + len - 4, ".fdf", 4) == 0)
        return (SUCCESS);
    return (FAIL);
}
