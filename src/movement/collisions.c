/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 20:39:32 by gisidro-          #+#    #+#             */
/*   Updated: 2026/05/27 21:19:36 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	get_map_cell(t_data *data, double x, double y)
{
	int	xi;
	int	yi;

	xi = (int)x;
	yi = (int)y;
	if (yi < 0 || yi >= data->map.height)
		return ('1');
	if (xi < 0 || xi >= (int)ft_strlen(data->map.grid[yi]))
		return ('1');
	return (data->map.grid[yi][xi]);
}

bool	is_wall(t_data *data, double x, double y)
{
	char	cell;

	cell = get_map_cell(data, x, y);
	if (cell == '1')
		return (1);
	return (false);
}

int	can_move_to(t_data *data, double new_x, double new_y)
{
	double	diag_offset;

	diag_offset = COLLISION_LIMIT / sqrt(2);
	if (is_wall(data, new_x + COLLISION_LIMIT, new_y))
		return (0);
	if (is_wall(data, new_x - COLLISION_LIMIT, new_y))
		return (0);
	if (is_wall(data, new_x, new_y + COLLISION_LIMIT))
		return (0);
	if (is_wall(data, new_x, new_y - COLLISION_LIMIT))
		return (0);
	if (is_wall(data, new_x + diag_offset, new_y + diag_offset))
		return (0);
	if (is_wall(data, new_x - diag_offset, new_y + diag_offset))
		return (0);
	if (is_wall(data, new_x + diag_offset, new_y - diag_offset))
		return (0);
	if (is_wall(data, new_x - diag_offset, new_y - diag_offset))
		return (0);
	return (1);
}
