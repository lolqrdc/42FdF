/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:54:15 by lolq              #+#    #+#             */
/*   Updated: 2025/02/18 18:38:37 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{

    if (argc != 2)
        return (ft_putstr_fd("Usage: ./fdf <filename>\n", 2), FAIL);
    if (!check_file)
        return (ft_putstr_fd("Error: invalid map\n", 2), FAIL);
    
}
int    print_error(char *message)
{
    ft_printf("%s\n", message);
    exit(1); 
}
