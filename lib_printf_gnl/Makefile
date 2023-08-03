# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 19:52:35 by angomes-          #+#    #+#              #
#    Updated: 2023/08/02 18:48:45 by angomes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -f

HRD_DIR = ./includes/
SRCS_DIR = ./srcs/
LIBFT_DIR = ./srcs/libft
GNL_DIR = ./srcs/Get_Next_Line
PRINTF_DIR = ./srcs/ft_printf
OBJS_DIR = ./objs/

SRCS_FILES = \
	$(LIBFT_SRCS)\
	$(GNL_SRCS)\
	$(PRINTF_SRCS)\

LIBFT_FILES =\
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
	ft_strtrim \
	ft_split \

GNL_FILES =\
  get_next_line \
  get_next_line_utils \

PRINTF_FILES =\
  ft_printf \
	ft_printf_utils_number \
	ft_printf_utils_string \

LIBFT_SRCS = $(addprefix $(LIBFT_FILES), $(addsuffix .c, $(LIBFT_FILES)))
GNL_SRCS = $(addprefix $(GNL_DIR), $(addsuffix .c, $(GNL_FILES)))
PRINTF_SRCS = $(addprefix $(PRINTF_DIR), $(addsufix .c, $(PRINTF_FILES)))
SRCS = $(addprefix $(SRC_DIR), $(SRCS_FILES))
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRCS_FILES)))

all: $(NAME)
	
%.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $< -I $(HRD_DIR)

$(NAME): $(OBJS)
	$(AR) $(NAME) $@

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: bonus all clean fclean re
