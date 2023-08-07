# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angomes- <angomes-@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 19:52:35 by angomes-          #+#    #+#              #
#    Updated: 2023/05/24 22:48:40 by angomes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -f
HEADER = inc/libft.h

FILES =\
	ft_strlen \
	ft_memcpy \
	ft_isalpha \
	ft_isdigit \
	ft_isalnum \
	ft_isascii \
	ft_strlcpy \
	ft_strncmp \
	ft_tolower \
	ft_toupper \
	ft_isprint \
	ft_atoi	\
	ft_strlcat \
	ft_memmove \
	ft_memset \
	ft_memcmp \
	ft_memchr \
	ft_strchr \
	ft_strrchr \
	ft_strnstr \
	ft_bzero \
	ft_strdup \
	ft_calloc \
	ft_substr \
	ft_strjoin \
	ft_striteri \
	ft_strmapi \
	ft_itoa \
	ft_putchar_fd \
	ft_putstr_fd \
	ft_putendl_fd \
	ft_putnbr_fd \
	ft_strtrim	\
	ft_split \
	get_next_line \
	get_next_line_utils \

SRCS_DIR = src
SRCS = $(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(FILES)))

OBJS_DIR = objs
OBJS = $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(FILES)))

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(AR) $(NAME) $(OBJS)

$(OBJS_DIR)/%.o:$(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: bonus all clean fclean re
