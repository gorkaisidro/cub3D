/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_math.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 20:40:35 by gisidro-          #+#    #+#             */
/*   Updated: 2026/06/03 19:19:50 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	get_movement_delta(t_data *data, double *dx, double *dy)
{
	int		ws;
	int		ad;
	double	cos_a;
	double	sin_a;

	ws = mlx_is_key_down(data->mlx, MLX_KEY_W)
		- mlx_is_key_down(data->mlx, MLX_KEY_S);
	ad = mlx_is_key_down(data->mlx, MLX_KEY_A)
		- mlx_is_key_down(data->mlx, MLX_KEY_D);
	cos_a = cos(data->player.angle) * data->player.speed;
	sin_a = sin(data->player.angle) * data->player.speed;
	*dx = (ws * cos_a) + (ad * sin_a);
	*dy = (ws * sin_a) - (ad * cos_a);
	return (ws != 0 || ad != 0);
}

void	try_move(t_data *data, double dx, double dy)
{
	double	x;
	double	y;

	x = data->player.x;
	y = data->player.y;
	if (can_move_to(data, x + dx, y + dy))
	{
		data->player.x = x + dx;
		data->player.y = y + dy;
	}
	else
	{
		if (can_move_to(data, x + dx, y))
		{
			data->player.x = x + dx;
		}
		if (can_move_to(data, x, y + dy))
		{
			data->player.y = y + dy;
		}
	}
}
