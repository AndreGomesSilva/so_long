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
# define WINDOW_WIDTH 1024
# define WINDOW_HEIGHT 800
# define TRUE 1
# define FALSE 0

# include "../libraries/MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include "../libraries/libft/inc/libft.h"
# include <fcntl.h>

typedef struct s_game {
    mlx_t *mlx;
    mlx_image_t *background_img;
    mlx_image_t *wall_img;
    mlx_image_t *player_img;
    mlx_image_t *exit_img;
    mlx_image_t *collectable_img;
    mlx_texture_t *background_texture;
    mlx_texture_t *wall_texture;
    mlx_texture_t *player_texture;
    mlx_texture_t *exit_texture;
    mlx_texture_t *collectable_texture;
    char **map;
    int32_t map_w;
    int32_t map_h;
}t_game;

int32_t	game_init(char *str);
int32_t check_args(int argc, char**argv);
char **get_map(char *str);
void draw_map(t_game *game);
int32_t map_construct(t_game *game);
void ft_error(char *error);
void get_size_map(t_game *game);
int32_t map_is_rectangle(t_game *game);
int32_t number_player_and_exit(t_game *game);

#endif
