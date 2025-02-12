/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolq <lolq@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:13:48 by lolq              #+#    #+#             */
/*   Updated: 2025/02/11 18:55:22 by lolq             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/* LIBRAIRIES */
# include "./libft/include/libft.h"
# include "./libft/include/ft_printf.h"
# include "./libft/include/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <errno.h>


typedef struct s_fdf
{
    void    *mlx;
    
} t_fdf;

/* FUNCTIONS */
int main(int argc, char **argv);
int handle_errors(char *error_msg);

#endif 