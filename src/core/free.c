/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 20:47:02 by gisidro-          #+#    #+#             */
/*   Updated: 2026/05/27 21:12:25 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	error_return(t_data *data, char *msg)
{
	data->error_msg = msg;
	return (true);
}

void	error_exit(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	gc_free_all();
	exit(EXIT_FAILURE);
}

void	free_textures(t_textures *textures)
{
	if (textures->north)
		mlx_delete_texture(textures->north);
	if (textures->south)
		mlx_delete_texture(textures->south);
	if (textures->west)
		mlx_delete_texture(textures->west);
	if (textures->east)
		mlx_delete_texture(textures->east);
}
