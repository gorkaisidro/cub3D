/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 21:10:24 by gisidro-          #+#    #+#             */
/*   Updated: 2026/05/27 21:22:58 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	alloc_map_grid(t_data *data, size_t rows)
{
	data->map.height = rows;
	data->map.grid = gc_alloc((rows + 1) * sizeof(char *));
	if (!data->map.grid)
		return (error_return(data, "Map alloc failed"));
	data->map.grid[rows] = NULL;
	return (false);
}

void	fill_grid_and_count(t_data *data, t_vec *map_vec)
{
	size_t	i;
	char	**grid;
	int		len;

	grid = data->map.grid;
	i = 0;
	while (i < map_vec->len)
	{
		grid[i] = *(char **)vec_get(map_vec, i);
		len = ft_strlen(grid[i]);
		if (len > data->map.width)
			data->map.width = len;
		i++;
	}
}

bool	build_map(t_data *data, t_vec *map_vec)
{
	size_t	rows;

	rows = map_vec->len;
	if (alloc_map_grid(data, rows))
		return (true);
	fill_grid_and_count(data, map_vec);
	return (false);
}
