# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/31 20:33:19 by angomes-          #+#    #+#              #
#    Updated: 2023/08/04 09:29:47 by angomes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## Properties for MacOS
#CDEBUG = -g3
#GRATE = GAME_RATE=17
##LMLX = -lmlx -framework OpenGL -framework AppKit
#LMLX = -framework Cocoa -framework OpenGL -framework IOKit
#

# Make variables
HEADER = ./inc
CFLAGS = -Wall -Wextra -Werror -I$(HEADER)
LEAKS = valgrind --leak-check=full --show-leak-kinds=all -s -q
RM = rm -f
CC = gcc -g
AR = ar rcs
SRCS_DIR = src
OBJS_DIR = obj
OBJ_GNL_DIR = obj_gnl
BIN = so_long
NAME = $(BIN)
LIBFT_PATH = libraries/libft
LIBFT = $(LIBFT_PATH)/libft.a
MLX_PATH = libraries/MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm
MLX_HEADER = libraries/MLX42/include

SRCS_MAPS = "./maps/map.ber"

FILES =\
	main \
	check_args \
	game_init \
	handle_input \
	handle_image \
	handle_error \
	handle_map \
	check_map \
	handle_window \
	handle_free \
	map_validate \
	handle_collectable \
	player_movement \
	draw_map \

OBJS = $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(FILES)))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_PATH) -lft $(MLX_PATH) -o $@

$(OBJS_DIR)/%.o:$(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE)	-C $(LIBFT_PATH)

play: all
	./so_long "./maps/map.ber"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(RM) -r $(BIN_DIR)

re: fclean all

.PHONY: all clean fclean re
