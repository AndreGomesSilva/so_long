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
# define IMAGE_WIDTH 32
# define IMAGE_HEIGHT 32
# define TRUE 1
# define FALSE 0

# include  "../libraries/MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include "../libraries/libft/inc/libft.h"
# include <fcntl.h>
# include <math.h>

typedef  struct s_game {
    char **map;
    char **cloned_map;
    int map_col;
    int map_row;
    int player_x;
    int player_y;
    int window_w;
    int window_h;
    int collectable_number;
    int collectable_remain;
    int n_player_movement;
} t_game;

typedef struct s_window {
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
    t_game  *game;
}t_window;

void ft_error(char *error);
int check_args(int argc, char**argv);
int	game_init(char *str);
char **get_map(char *str);
void draw_map(t_window *window, t_game *game);
void draw_layers(t_window *window, t_game *game,char type);
int map_construct(t_window *window);
void get_size_window(t_game *game);
int map_is_rectangle(t_game *game);
int right_tile_set(t_game *game);
int create_texture_from_png(t_window *window);
void create_img_from_texture(t_window *window);
void    free_images(t_window *window);
void    free_textures(t_window *window);
void hook_close_window(void *param);
void free_map(char **map);
void hook_player_movement(mlx_key_data_t keydata, void *param);
void free_game(t_window *window, t_game *game);
int create_new_player_image(t_window *window, char *path);
void    update_player_movement(t_window *window, t_game *game, char *path);
void    player_move_up(t_window *window, t_game *game);
void    player_move_down(t_window *window, t_game *game);
void    player_move_left(t_window *window, t_game *game);
void    player_move_right(t_window *window, t_game *game);
int collect(t_window *window, t_game *game);
void    validate_map(t_game *game, char *str);

#endif
