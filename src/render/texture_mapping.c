/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_mapping.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 20:47:41 by gisidro-          #+#    #+#             */
/*   Updated: 2026/06/01 21:02:06 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	calculate_tex_x(t_ray *ray)
{
	int	tex_x;

	tex_x = ray->wall_x * ray->texture->width;
	if (tex_x >= (int)ray->texture->width)
		tex_x = ray->texture->width - 1;
	return (tex_x);
}

static int	calculate_tex_y(t_data *data, int y)
{
	int	relative_y;
	int	tex_height;
	int	wall_height;
	int	tex_y;

	relative_y = y - data->column.orig_start_y;
	tex_height = data->ray.texture->height;
	wall_height = data->column.wall_height;
	tex_y = (relative_y * tex_height) / wall_height;
	if (tex_y >= tex_height)
		tex_y = tex_height - 1;
	return (tex_y);
}

void	render_texture_stripe(t_data *data, int screen_x)
{
	int			y;
	int			tex_x;
	int			tex_y;
	uint32_t	color;

	tex_x = calculate_tex_x(&data->ray);
	y = data->column.vis_start_y;
	while (y <= data->column.vis_end_y)
	{
		tex_y = calculate_tex_y(data, y);
		color = get_texture_color(data->ray.texture, tex_x, tex_y);
		mlx_put_pixel(data->image, screen_x, y, color);
		y++;
	}
}
