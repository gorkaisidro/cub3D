/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 20:50:11 by gisidro-          #+#    #+#             */
/*   Updated: 2026/05/27 21:01:37 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	calc_delta(double dir)
{
	if (dir == 0.0)
		return (1e30);
	return (fabs(1.0 / dir));
}

void	init_dda_axis_x(t_data *data, t_dda *dda, double px, int mx)
{
	dda->delta_x = calc_delta(data->ray.dir_x);
	if (data->ray.dir_x < 0)
	{
		dda->step_x = -1;
		dda->side_x = (px - mx) * dda->delta_x;
	}
	else
	{
		dda->step_x = 1;
		dda->side_x = (mx + 1.0 - px) * dda->delta_x;
	}
}

void	init_dda_axis_y(t_data *data, t_dda *dda, double py, int my)
{
	dda->delta_y = calc_delta(data->ray.dir_y);
	if (data->ray.dir_y < 0)
	{
		dda->step_y = -1;
		dda->side_y = (py - my) * dda->delta_y;
	}
	else
	{
		dda->step_y = 1;
		dda->side_y = (my + 1.0 - py) * dda->delta_y;
	}
}

bool	process_dda_cell(t_data *data, t_dda *dda)
{
	char	cell;

	cell = data->map.grid[dda->map_y][dda->map_x];
	if (cell == '1')
		return (true);
	return (false);
}
