/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 20:48:28 by gisidro-          #+#    #+#             */
/*   Updated: 2026/05/27 21:12:10 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	load_texture(char *path, mlx_texture_t **texture)
{
	*texture = mlx_load_png(path);
	if (!*texture)
		return (false);
	return (true);
}

bool	textures_ready(t_data *data)
{
	t_textures	*t;

	t = data->textures;
	return (t->north && t->south && t->west && t->east);
}

//check int x and int y type
uint32_t	get_texture_color(mlx_texture_t *texture, int x, int y)
{
	if (x < 0 || x >= (int)texture->width || y < 0 || y >= (int)texture->height)
		return (0);
	return (*(uint32_t *)(texture->pixels + y * texture->width * 4 + x * 4));
}

mlx_texture_t	*get_wall_texture(t_data *data)
{
	if (data->ray.side == 0)
	{
		if (data->ray.dir_x > 0)
			return (data->textures->east);
		else
			return (data->textures->west);
	}
	else
	{
		if (data->ray.dir_y > 0)
			return (data->textures->south);
		else
			return (data->textures->north);
	}
}
