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

# include "../libraries/MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <stdio.h>
# include "../libraries/libft/inc/libft.h"
# include <fcntl.h>

typedef struct s_game {
    mlx_t *mlx;
    mlx_image_t *background_img;
    mlx_image_t *wall_img;
    mlx_texture_t *background_texture;
    mlx_texture_t *wall_texture;
    char **map;
}t_game;

int check_param(int argc, char**argv);
int game_init(char *str);

#endif
