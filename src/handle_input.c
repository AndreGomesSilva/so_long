//
// Created by Andre on 17/08/23.
//

#include "../inc/so_long.h"

void hook_close_window(void *param)
{
    t_window *window;

    window = (t_window *)param;
    if (mlx_is_key_down(window->mlx, MLX_KEY_ESCAPE)) {
        mlx_close_window(window->mlx);
    }
}

void hook_player_movement(mlx_key_data_t keydata, void *param)
{
    t_window *window;
    t_game  *game;

    window = (t_window *)param;
    game = window->game;

    if (((keydata.key == MLX_KEY_W) ^ (keydata.key == MLX_KEY_UP)) && keydata.action == MLX_PRESS && game->map[game->player_y - 1][game->player_x] != '1')
       player_move_up(window, game);

    if (((keydata.key == MLX_KEY_S) ^ (keydata.key == MLX_KEY_DOWN)) && keydata.action == MLX_PRESS && game->map[game->player_y + 1][game->player_x] != '1')
        player_move_down(window, game);

    if (((keydata.key == MLX_KEY_A) ^ (keydata.key == MLX_KEY_LEFT)) && keydata.action == MLX_PRESS && game->map[game->player_y][game->player_x - 1] != '1')
        player_move_left(window, game);

    if (((keydata.key == MLX_KEY_D) ^ (keydata.key == MLX_KEY_RIGHT)) && keydata.action == MLX_PRESS && game->map[game->player_y][game->player_x + 1] != '1')
        player_move_right(window, game);
}