/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 19:36:28 by gisidro-          #+#    #+#             */
/*   Updated: 2026/05/12 20:58:30 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	init_mlx_data(t_data *data)
{
	int	mw;
	int	mh;

	data->mlx = mlx_init(MIN_WIDTH, MIN_HEIGHT, "Cub3D Ray-Casting", true);
	if (!data->mlx)
	{
		data->error_msg = "Failed to initialize MLX window";
		return (false);
	}
	data->textures = gc_alloc(sizeof(t_textures));
	if (!data->textures)
	{
		mlx_terminate(data->mlx);
		data->error_msg = "Failed to allocate memory for textures";
		return (false);
	}
	ft_memset(data->textures, 0, sizeof(t_textures));
	mlx_get_monitor_size(0, &mw, &mh);
	data->width = mw / 2;
	data->height = mh / 2;
	mlx_set_window_size(data->mlx, data->width, data->height);
	mlx_set_window_limit(data->mlx, MIN_WIDTH, MIN_HEIGHT, mw, mh);
	mlx_set_window_pos(data->mlx, (mw - data->width) / 2,
		(mh - data->height) / 2);
	return (true);
}
