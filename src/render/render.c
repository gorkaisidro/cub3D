/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 20:44:39 by gisidro-          #+#    #+#             */
/*   Updated: 2026/06/01 18:14:57 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	render(t_data *data)
{
	mlx_resize_hook(data->mlx, &my_resize_callback, (void *)data);
	if (data->resize_pending)
	{
		data->width = data->new_width;
		data->height = data->new_height;
		mlx_delete_image(data->mlx, data->image);
		data->image = mlx_new_image(data->mlx, data->new_width,
				data->new_height);
		mlx_image_to_window(data->mlx, data->image, 0, 0);
		data->player.speed = (double)data->height * PLAYER_SPEED;
		data->resize_pending = false;
	}
	render_floor_ceiling(data);
	render_walls(data);
}
