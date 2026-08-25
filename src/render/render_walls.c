/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 20:46:32 by gisidro-          #+#    #+#             */
/*   Updated: 2026/05/27 21:16:33 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	render_walls(t_data *data)
{
	double	dist_to_plane;
	double	screen_x;
	double	offset;
	double	angle_offset;
	double	ray_angle;

	dist_to_plane = ((double)data->width / 2.0) / tan(FOV / 2.0);
	screen_x = 0;
	while ((int)screen_x < data->width)
	{
		offset = (screen_x + 0.5) - (double)((double)data->width / 2.0);
		angle_offset = atan(offset / dist_to_plane);
		ray_angle = data->player.angle + angle_offset;
		render_wall_column(data, ray_angle, (int)screen_x);
		screen_x++;
	}
}

void	render_wall_column(t_data *data, double ray_angle, int screen_x)
{
	int		center_y;

	calculate_ray_data(data, ray_angle);
	data->column.wall_height = (int)(data->height / data->ray.distance);
	center_y = data->height / 2;
	data->column.orig_start_y = center_y - (data->column.wall_height / 2);
	data->column.orig_end_y = center_y + (data->column.wall_height / 2);
	data->column.vis_start_y = data->column.orig_start_y;
	data->column.vis_end_y = data->column.orig_end_y;
	if (data->column.vis_start_y < 0)
		data->column.vis_start_y = 0;
	if (data->column.vis_end_y >= data->height)
		data->column.vis_end_y = data->height - 1;
	render_texture_stripe(data, screen_x);
}
