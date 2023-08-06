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

# Key Codes for MacOS
ESC = KEY_ESC=53
W = KEY_W=13
A = KEY_A=0
S = KEY_S=1
D = KEY_D=2
UP = KEY_UP=126
DOWN = KEY_DOWN=125
LEFT = KEY_LEFT=123
RIGHT = KEY_RIGHT=124
R = KEY_R=15
Q = KEY_Q=12

# Properties for MacOS
CDEBUG = #-g3 -fsanitize=address
GRATE = GAME_RATE=17
GAME = game_mac.c
RENDER = render_mac.c
LMLX = -lmlx -framework OpenGL -framework AppKit

SHELL=/bin/bash
UNAME = $(shell uname -s)

ifeq ($(UNAME), Linux)
	#Properties for Linux
	LEAKS =  valgrind --leak-check=full --show-leak-kinds=all -s -q
	LMLX = -lmlx -lXext -lX11
	GAME = game_linux.c
	RENDER = render_linux.c
	GRATE = GAME_RATE=80
	CDEBUG =

	# Key Codes for Linux
	ESC = KEY_ESC=65307
	W = KEY_W=119
	A = KEY_A=97
	S = KEY_S=115
	D = KEY_D=100
	UP = KEY_UP=65362
	DOWN = KEY_DOWN=65364
	LEFT = KEY_LEFT=65361
	RIGHT = KEY_RIGHT=65363
	R = KEY_R=114
	Q = KEY_Q=113
endif

# Make variables
PRINTF = printf
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
CC = gcc -MD
AR = ar rcs
SRCS_DIR = src
OBJS_DIR = obj
BIN_DIR = bin
OBJ_GNL_DIR = obj_gnl
BIN = so_long
NAME = $(BIN_DIR)/$(BIN)
LIBFT = libft/bin/libft.a
LIBFT_DIR = libft
LIBFT_SRC = $(shell [ -d libft ] && ls libft/src*/*.c)
GNL_DIR = get_next_line

# Keycodes defined during compilation
KEYCODES =  -D $(ESC) -D $(Q) -D $(R) -D $(W) -D $(A) -D $(S) -D $(D) -D $(UP) -D $(DOWN) -D $(LEFT) -D $(RIGHT)

# Game speeds defined during compilation
RATES = -D $(GRATE)

SRCS_MAPS = map01.ber

FILES =\
	main \

SRCS = $(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(FILES)))

OBJS = $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(FILES)))

all: $(NAME)

$(NAME): $(OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) $(CDEBUG) $(OBJS) $(LMLX) -o $@

$(OBJS_DIR)/%.o:$(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(CDEBUG) $(KEYCODES) $(RATES) -c $< -o $@

play:
	./$(NAME)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) -r $(BIN_DIR)

re: fclean all

.PHONY: all clean fclean re
