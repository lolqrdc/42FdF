/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:30:00 by loribeir          #+#    #+#             */
/*   Updated: 2025/02/17 15:32:52 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief initialize the graphic variables and parsing. 
 */

int    check_file(char *file)
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
