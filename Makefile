# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gvarys <gvarys@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 11:18:05 by gvarys            #+#    #+#              #
#    Updated: 2021/12/03 14:33:14 by gvarys           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= so_long

CC					= gcc
CFLAGS				=  -O2 -Wall -Wextra -Werror

RM					= rm -rf

LIBFT_DIR			= libs/Libft/
LIBFT				= $(LIBFT_DIR)/libft.a

MLX_DIR				= libs/minilibx_opengl_20191021/
MLX					= $(MLX_DIR)/libmlx.a

SRC_DIR				= src/
SRC_BONUS_DIR		= src_bonus/

HEADER				= $(SRC_DIR)so_long.h
HEADER_BONUS		= $(SRC_BONUS_DIR)so_long_bonus.h

SRC_FILES			= main.c\
					map_validation.c\
					check_valid.c\
					start_game.c\
					move.c\
					move1.c\
					draw.c\

SRC_BONUS_FILES		= main_bonus.c\
					map_validation_bonus.c\
					check_valid_bonus.c\
					start_game_bonus.c\
					move_bonus.c\
					move1_bonus.c\
					draw_bonus.c\
					animation_bonus.c\

OBJS			= $(patsubst %.c, %.o, $(addprefix $(SRC_DIR), $(SRC_FILES)))
OBJS_BONUS		= $(patsubst %.c, %.o, $(addprefix $(SRC_BONUS_DIR), $(SRC_BONUS_FILES)))

all: $(LIBFT) $(MLX) $(NAME)

bonus: $(LIBFT) $(MLX)
		@make OBJS="$(OBJS_BONUS)" \
		SRC_DIR="$(SRC_BONUS_DIR)" \
		SRC_FILES="$(SRC_BONUS_FILES)" \
		HEADER="$(HEADER_BONUS)" all

$(NAME): $(OBJS) $(HEADER)
		$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -o $@

$(SRC_DIR)%.o:		$(SRC_DIR).c 
			$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	make -C $(MLX_DIR) clean
	make -C $(LIBFT_DIR) fclean

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
