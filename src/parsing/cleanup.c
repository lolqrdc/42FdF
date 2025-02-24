/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:43:16 by loribeir          #+#    #+#             */
/*   Updated: 2025/02/24 13:35:28 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	cleanup_fdf(t_fdf *fdf)
{
	if (fdf->points)
		free(fdf->points);
	if (fdf->map && fdf->map->matrice)
		free_matrice(fdf);
	if (fdf->map)
		free(fdf->map);
	if (fdf->img)
		free(fdf->img);
	free(fdf);
}

void	free_matrice(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (i < fdf->map->height)
	{
		free(fdf->map->matrice[i]);
		i++;
	}
	free(fdf->map->matrice);
}

void	free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
