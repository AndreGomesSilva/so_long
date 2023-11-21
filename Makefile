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

HEADERS = -I ./inc -I ./libraries/MLX42/include
CFLAGS = -Wall -Wextra -Werror -Ofast
LEAKS = valgrind --leak-check=full --show-leak-kinds=all --gen-suppressions=all --suppressions=./libraries/MLX42/suppress.sup
RM = rm -f
CC = cc -g
SRCS_DIR = src
OBJS_DIR = obj
BIN = so_long
NAME = $(BIN)
LIBFT_PATH = libraries/libft
LIBFT = $(LIBFT_PATH)/libft.a
MLX_PATH = libraries/MLX42/build/libmlx42.a -ldl -lglfw
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

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_PATH) -lft $(MLX_PATH) $(HEADERS) -o $@

$(OBJS_DIR)/%.o:$(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< $(HEADERS) -o $@

$(LIBFT):
	$(MAKE)	-C $(LIBFT_PATH)

play: all
	./$(BIN) $(SRCS_MAPS)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(RM) $(BIN)

re: fclean all

.PHONY: all clean fclean re
