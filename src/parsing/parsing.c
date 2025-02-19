/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 08:19:45 by loribeir          #+#    #+#             */
/*   Updated: 2025/02/19 09:58:05 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*check_file: check if the file is correct.*/
void check_file(char *file)
{
    char *ext;

    if (!file)
        print_error("Error: file is NULL\n");
    ext = ft_strrchr(file, '.');
    if (!ext || ft_strncmp(ext, ".fdf", 4) != 0)
        print_error("Error: invalid file\n");
}

/* print_error: write a error message and quit the program.*/
int    print_error(char *message)
{
    ft_printf("%s\n", message);
    exit(1); 
}

