/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:16:03 by angomes-          #+#    #+#             */
/*   Updated: 2023/08/04 09:24:35 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600
# define MLX_ERROR 1

typedef struct s_game{
    void *mlx;
    void *window;
    char **map;
    void *img_wall;
    void *img_background;
    void *img_exit;
    void *img_player;
} t_game;

typedef struct s_map{
   char *x;
   char *y;
   int x_len;
   int y_len;
} t_map;

typedef struct s_image{
    int img_width;
    int img_height;
    int pixel_bits;
    int line_bytes;
    int endian;
}t_image;

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libraries/libft/inc/libft.h"
# include <fcntl.h>

int check_param(int argc, char**argv);
int game_init(char *str);

#endif
