# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/11 21:08:42 by gisidro-          #+#    #+#              #
#    Updated: 2026/06/01 21:04:14 by gisidro-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc
CFLAGS = -Wall -Werror -Wextra -g -O2
LDFLAGS = -lglfw -pthread -lm -L"/opt/homebrew/lib/" -L"/usr/local/lib/"

LIBMLX = ./MLX42
MLX_42 = $(LIBMLX)/build/libmlx42.a

INCLUDES = -Iincludes -I$(LIBMLX)/include -I./libft/includes

SRC =   src/main.c \
        src/core/window.c \
        src/core/callbacks.c \
		src/core/hooks.c \
        src/core/free.c \
        src/movement/movement.c \
        src/movement/movement_math.c \
        src/movement/collisions.c \
		src/raycasting/ray.c \
		src/raycasting/dda.c \
		src/render/render.c \
        src/render/render_background.c \
        src/render/render_walls.c \
        src/render/texture_mapping.c \
        src/render/texture_manager.c \
        src/render/color_utils.c \
		src/parsing/file.c \
		src/parsing/line.c \
		src/parsing/char.c \
		src/parsing/parsing.c \
		src/parsing/parsing_head.c \
		src/parsing/parsing_map.c \
		src/parsing/parsing_player.c \
		src/parsing/map_algorithms.c 

OBJ = $(SRC:.c=.o)

all: make_libs $(NAME)

make_libs:
	@make -C ./libft

$(LIBMLX):
	@echo "Cloning MLX42..."
	@git clone https://github.com/codam-coding-college/MLX42.git $(LIBMLX)

$(MLX_42): | $(LIBMLX)
	@echo "Building MLX42..."
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c | $(LIBMLX)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(NAME): $(OBJ) libft/libft.a $(MLX_42)
	$(CC) $(CFLAGS) $(OBJ) libft/libft.a $(MLX_42) -o $(NAME) $(LDFLAGS)

clean:
	rm -rf $(OBJ)
	@make -C libft clean
    
fclean: clean
	rm -f $(NAME)
	rm -rf $(LIBMLX)/build
	@make fclean -C libft

re: fclean all

.PHONY: all clean fclean re make_libs