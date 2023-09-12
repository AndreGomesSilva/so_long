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
    int map_col;
    int map_row;
    int player_x;
    int player_y;
    int window_w;
    int window_h;
    int n_collectable;
    int r_collectable;
    int image_new_width;
    int image_new_height;
    int n_player_move;
}t_game;

int	game_init(char *str);
int check_args(int argc, char**argv);
char **get_map(char *str);
void draw_map(t_game *game);
int map_construct(t_game *game);
void draw_layers(t_game *game, mlx_image_t *img, char type);
void ft_error(char *error);
void get_size_window(t_game *game);
int map_is_rectangle(t_game *game);
int number_player_and_exit(t_game *game);
int create_texture_from_png(t_game *game);
void create_img_from_texture(t_game *game);
void    free_images(t_game *game);
void    free_textures(t_game *game);
void hook_close_window(void *param);
void free_map(char **map);
void hook_player_movement(mlx_key_data_t keydata, void *param);
void free_game(t_game *game);
int create_new_player_image(t_game *game, char *path);
void    update_player_movement(t_game *game, char *path);
void    player_move_up(t_game *game);
void    player_move_down(t_game *game);
void    player_move_left(t_game *game);
void    player_move_right(t_game *game);
void    check_window_size(t_game *game);
int collect(t_game *game);
void    check_map(t_game *game, char *str);

#endif
