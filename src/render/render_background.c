/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_background.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 20:45:47 by gisidro-          #+#    #+#             */
/*   Updated: 2026/05/20 20:57:13 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	render_floor_ceiling(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (y < data->height / 2)
				mlx_put_pixel(data->image, x, y, data->ceiling);
			else
				mlx_put_pixel(data->image, x, y, data->floor);
			x++;
		}
		y++;
	}
}
