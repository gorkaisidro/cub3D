/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 20:56:09 by gisidro-          #+#    #+#             */
/*   Updated: 2026/06/03 19:03:52 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>

# include "libft.h"
# include "gc.h"
# include "vec.h"

# include <MLX42/MLX42.h>

# define GRAY_COLOR 0x444444FF
# define LIGHT_GRAY_COLOR 0xBBBBBBFF
# define RED_COLOR 0xFF0000FF
# define GREEN_COLOR 0x00FF00FF
# define BLUE_COLOR 0x0000FFFF
# define BLUE_COLOR_2 0x00AAFFFF
# define YELLOW_COLOR 0xFFFF00FF
# define BLACK_COLOR 0x000000FF
# define WHITE_COLOR 0xFFFFFFFF
# define SKY_COLOR 0x87CEEBFF
# define FLOOR_COLOR 0x8B4513FF

# define MIN_WIDTH 384
# define MIN_HEIGHT 216
# define TILE_SIZE 64
# define STEP_SIZE 0.5
# define FOV 1.0471975511965976

# define COLLISION_LIMIT 0.15
# define PLAYER_SPEED 0.00005
# define VEC_INIT_SIZE 4

typedef struct s_player
{
	double		x;
	double		y;
	double		angle;
	double		speed;
}	t_player;

typedef struct s_textures
{
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*west;
	mlx_texture_t	*east;
}	t_textures;

typedef struct s_column
{
	int		orig_start_y;
	int		orig_end_y;
	int		vis_start_y;
	int		vis_end_y;
	int		wall_height;
}	t_column;

typedef struct s_dda
{
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	delta_x;
	double	delta_y;
	double	side_x;
	double	side_y;
}	t_dda;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
}	t_map;

typedef struct s_ray
{
	double			distance;
	double			hit_x;
	double			hit_y;
	int				side;
	double			wall_x;
	mlx_texture_t	*texture;
	double			dir_x;
	double			dir_y;
}	t_ray;

typedef struct s_data
{
	bool			resize_pending;
	int				new_width;
	int				new_height;
	int				width;
	int				height;
	t_map			map;
	bool			f_color_found;
	bool			c_color_found;
	mlx_t			*mlx;
	mlx_image_t		*image;
	t_ray			ray;
	t_column		column;
	t_player		player;
	t_textures		*textures;
	uint32_t		floor;
	uint32_t		ceiling;
	bool			strict;
	char			*error_msg;
	bool			map_started;
	t_vec			map_vec;
	bool			window_active;
}	t_data;

//window.c
bool			init_mlx_data(t_data *data);

//hooks.c
void			loop_hook(void *param);

//callbacks.c
void			my_resize_callback(int width, int height, void *param);

//free.c
bool			error_return(t_data *data, char *msg);
void			error_exit(char *msg);
void			free_textures(t_textures *textures);

//movement.c
void			handle_movement(t_data *data);
void			handle_rotation(t_data *data);

//movement_utils.c
bool			get_movement_delta(t_data *data, double *dx, double *dy);
void			try_move(t_data *data, double dx, double dy);

//utils.c
bool			is_wall(t_data *data, double x, double y);
int				can_move_to(t_data *data, double new_x, double new_y);

//ray.c
void			calculate_ray_data(t_data *data, double angle);

//dda.c
double			calc_delta(double dir);
void			init_dda_axis_x(t_data *data, t_dda *dda, double px, int mx);
void			init_dda_axis_y(t_data *data, t_dda *dda, double py, int my);
bool			process_dda_cell(t_data *data, t_dda *dda);

//render.c
void			render(t_data *data);

//render_background.c
void			render_floor_ceiling(t_data *data);

//render_walls.c
void			render_walls(t_data *data);
void			render_wall_column(t_data *data,
					double ray_angle, int screen_x);

//texture_mapping.c
void			render_texture_stripe(t_data *data, int screen_x);

//texture_manager.c
bool			load_texture(char *path, mlx_texture_t **texture);
bool			textures_ready(t_data *data);
uint32_t		get_texture_color(mlx_texture_t *texture, int x, int y);
mlx_texture_t	*get_wall_texture(t_data *data);

//color_utils.c
uint8_t			get_r(uint32_t rgba);
uint8_t			get_g(uint32_t rgba);
uint8_t			get_b(uint32_t rgba);
uint8_t			get_a(uint32_t rgba);
uint32_t		get_rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

//line.c
bool			line_is_only_spaces(char *line);
bool			is_map_line(char *line);
bool			split_line(char *line, char **key, char **rest);

//char.c
bool			valid_character(char c);
int				count_char(char *str, char c);
bool			is_number(char *str);

//parsing_head.c
int				process_header_line(char *line, t_data *data);
bool			parse_color_values(char *str, uint32_t *color);
bool			parse_color_line(char *line, t_data *data);
bool			parse_texture_line(char *line, t_data *data);

//parsing_player.c
bool			parse_player_pos(t_data *data);

//parsing_map.c
bool			build_map(t_data *data, t_vec *map_vec);

//map_algorithms.c
bool			is_map_closed_strict(t_data *data);
bool			flood_fill(t_data *data, bool **visited, int i, int j);
bool			is_map_closed(t_data *data);

//parsing.c
int				parse_cubfile(char *filepath, t_data *data);

//file.c
int				open_cub_file(const char *path);
int				close_cub_file(int fd, t_data *data);
bool			has_cub_extension(char *filename);

#endif