/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:54:15 by lolq              #+#    #+#             */
/*   Updated: 2025/02/24 12:42:40 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		return (print_error("Error: allocation failed"), FAIL);
	if (argc != 2)
		return (free(fdf), print_error("Usage: ./fdf <filename>"), FAIL);
	check_file(argv[1], fdf);
	if (get_map(fdf, argv[1]) != SUCCESS)
		return (cleanup_fdf(fdf), FAIL);
	if (init_components(fdf) != SUCCESS)
		return (cleanup_fdf(fdf), FAIL);
	return (0);
}
