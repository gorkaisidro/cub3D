/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 20:41:56 by gisidro-          #+#    #+#             */
/*   Updated: 2026/05/27 21:18:41 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	handle_movement(t_data *data)
{
	double	dx;
	double	dy;

	if (!get_movement_delta(data, &dx, &dy))
	{
		return ;
	}
	try_move(data, dx, dy);
}

void	handle_rotation(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		data->player.angle -= data->player.speed;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		data->player.angle += data->player.speed;
}
