# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saray <saray.jafarzade@gmail.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/15 11:05:21 by saray             #+#    #+#              #
#    Updated: 2021/04/23 13:44:48 by saray            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Cub3D

SRC =	./src/parsing.c \
	./src/parsing_color_resolution_texture.c \
	./src/parsing_map.c \
	./src/parsing_utils.c \
	./src/keys_draw.c \
	./src/raycasting_init.c \
	./src/raycasting_utils.c \
	./src/raycasting_move.c \
	./src/raycasting.c \
	./src/sprites.c \
	./src/errors.c \
	./src/save.c \
	./src/get_next_line.c \
	./src/get_next_line_utils.c \
	./src/init.c \
	./src/norm3.c

OBJ	= ${SRC:.c=.o}
INC_DIR	= ./inc/
RM	= rm -f
CC	= clang
CFLAGS	= -Wall -Wextra -Werror

MIX_DIR	= ./mlx_linux/
MLX	= ${MIX_DIR}libmlx.a

$(NAME): ${OBJ}
	make -C ${MIX_DIR}
	${CC} ${CFLAGS} -o3 ${OBJ} -I ${INC_DIR} ${MLX} -lm -lbsd -lX11 -lXext -o $(NAME)


all:
	${NAME}


clean:
	${RM} ${OBJ}
	@make clean -C $(MIX_DIR)


fclean: clean
	${RM} ${NAME}
	@make fclean -C $(MIX_DIR)

re: fclean all

.PHONY: all, clean, fclean, re

