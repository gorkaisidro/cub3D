/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 21:16:35 by gisidro-          #+#    #+#             */
/*   Updated: 2026/06/03 18:40:15 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	clean_return(t_data *data, char *msg)
{
	if (data->window_active)
		mlx_terminate(data->mlx);
	if (data->textures)
		free_textures(data->textures);
	if (msg)
		data->error_msg = msg;
	return (EXIT_FAILURE);
}

//TODO
bool	initializer(t_data *data, char *filename, bool strict)
{
	int	status;

	status = 0;
	ft_memset(data, 0, sizeof(t_data));
	data->strict = strict;
	data->player.speed = 0.025;
	if (!init_mlx_data(data))
		return (EXIT_FAILURE);
	data->window_active = 1;
	status = parse_cubfile(filename, data);
	if (status)
		return (clean_return(data, NULL));
	data->image = mlx_new_image(data->mlx, data->width, data->height);
	if (!data->image)
		return (clean_return(data, "Failed to create image"));
	if (is_wall(data, data->player.x, data->player.y))
		return (clean_return(data, "Player starts inside a wall"));
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		error;
	bool	strict;

	strict = false;
	if (argc < 2 || !has_cub_extension(argv[1]) || argc > 3
		|| (argc == 3 && ft_strncmp(argv[2], "--strict", 9) != 0))
	{
		printf("Usage: %s <.cub file>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	if (argc == 3)
		strict = true;
	error = initializer(&data, argv[1], strict);
	if (error)
		error_exit(data.error_msg);
	mlx_image_to_window(data.mlx, data.image, 0, 0);
	mlx_loop_hook(data.mlx, loop_hook, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	if (data.textures)
		free_textures(data.textures);
	gc_free_all();
	return (EXIT_SUCCESS);
}
