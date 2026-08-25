/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callbacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 20:46:21 by gisidro-          #+#    #+#             */
/*   Updated: 2026/05/12 20:46:39 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	my_resize_callback(int width, int height, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (width <= MIN_WIDTH || height <= MIN_HEIGHT)
	{
		if (width == MIN_WIDTH && height == MIN_HEIGHT)
		{
			return ;
		}
		if (width <= MIN_WIDTH)
			data->new_width = MIN_WIDTH;
		else
			data->new_width = width;
		if (height <= MIN_HEIGHT)
			data->new_height = MIN_HEIGHT;
		else
			data->new_height = height;
	}
	else
	{
		data->new_width = width;
		data->new_height = height;
	}
	data->resize_pending = true;
}
