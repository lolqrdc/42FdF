/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 08:19:45 by loribeir          #+#    #+#             */
/*   Updated: 2025/02/24 18:30:05 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_file(char *file, t_fdf *fdf)
{
	char	*ext;

	if (!file)
	{
		if (fdf)
			free(fdf);
		print_error("Error: file is NULL\n");
	}
	ext = ft_strrchr(file, '.');
	if (!ext || ft_strncmp(ext, ".fdf", 4) != 0)
	{
		if (fdf)
			free(fdf);
		print_error("Error: invalid file");
	}
}

int	print_error(char *message)
{
	ft_printf("%s\n", message);
	exit (1);
}
