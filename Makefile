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
SHELL=/bin/bash
UNAME = $(shell uname -s)

ifeq ($(UNAME), Linux)
	#Properties for Linux
	LEAKS =  valgrind --leak-check=full --show-leak-kinds=all -s -q
	CDEBUG = -g3
endif

# Make variables
HEADER = ./inc
CFLAGS = -Wall -Wextra -Werror -I$(HEADER)
RM = rm -f
CC = gcc -MD
AR = ar rcs
SRCS_DIR = src
OBJS_DIR = obj
BIN_DIR = bin
OBJ_GNL_DIR = obj_gnl
BIN = so_long
NAME = $(BIN_DIR)/$(BIN)
LIBFT_PATH = libraries/libft
LIBFT = $(LIBFT_PATH)/libft.a
MLX_PATH = libraries/MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm
MLX_HEADER = libraries/MLX42/include

GNL_DIR = get_next_line

SRCS_MAPS = "./maps/map.ber"

FILES =\
	main \
	check_args \
	game_init \
	player_actions \
	handle_input \
	handle_image \
	handle_error \
	handle_map \
	draw_map \

#SRCS = $(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(FILES)))

OBJS = $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(FILES)))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) $(CDEBUG) $(OBJS) -L$(LIBFT_PATH) -lft $(MLX_PATH) -o $@

$(OBJS_DIR)/%.o:$(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(CDEBUG) -c $< -o $@

$(LIBFT):
	$(MAKE)	-C $(LIBFT_PATH)

play: all
	 valgrind -s --leak-check=full ./bin/so_long "./maps/map.ber"

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
