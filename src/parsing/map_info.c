/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:30:00 by loribeir          #+#    #+#             */
/*   Updated: 2025/02/24 13:32:17 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_map(t_fdf *fdf, char *file)
{
	init_fdf(fdf);
	init_map(fdf->map, file);
	init_matrice(fdf);
	parse_map(fdf, file);
	return (SUCCESS);
}

void calc_map(t_map *map, int fd)
{
    char *line;
    char **tab;

    line = get_next_line(fd);
    if (!line)
        print_error("Error: map is empty");
    tab = ft_split(line, ' ');
    if (!tab)
        print_error("Error: split failed");
    while (tab[map->width])
        map->width++;
    map->height++;
    free_tab(tab);
    free(line);
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break;
        map->height++;
        free(line);
    }
}

void init_map(t_map *map, char *file)
{
    int fd;

    fd = open(file, O_RDONLY);
    if (fd < 0)
        print_error("Error: failed to open file.");
    map->width = 0;
    map->height = 0;
    calc_map(map, fd);
    close(fd);
}

void	parse_map(t_fdf *fdf, char *file)
{
	int		fd;
	char	*line;
	char	**tab;

	fd = open(file, O_RDONLY);
	fdf->y = 0;
	while (fdf->y < fdf->map->height)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		tab = ft_split(line, ' ');
		fdf->x = 0;
		while (tab[fdf->x] && fdf->x < fdf->map->width)
		{
			fdf->map->matrice[fdf->y][fdf->x] = ft_atoi(tab[fdf->x]);
			fdf->x++;
		}
		free_tab(tab);
		free(line);
		fdf->y++;
	}
	close(fd);
}

void	init_matrice(t_fdf *fdf)
{
	int	i;
	int	j;

	fdf->map->matrice = malloc(sizeof(int *) * fdf->map->height);
	if (!fdf->map->matrice)
		print_error("Error: malloc failed");
	i = 0;
	while (i < fdf->map->height)
	{
		fdf->map->matrice[i] = malloc(sizeof(int) * fdf->map->width);
		if (!fdf->map->matrice[i])
			print_error("Error: malloc failed");
		j = 0;
		while (j < fdf->map->width)
		{
			fdf->map->matrice[i][j] = 0;
			j++;
		}
		i++;
	}
}
