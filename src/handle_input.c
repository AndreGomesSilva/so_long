//
// Created by Andre on 17/08/23.
//

#include "../inc/so_long.h"

void hook_close_window(void *param)
{
    t_game *game;

    game = (t_game *)param;

    if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE)) {
        mlx_close_window(game->mlx);
    }
    if (mlx_is_key_down(game->mlx, MLX_KEY_W)) {
        player_move_up(game);
    }
    if (mlx_is_key_down(game->mlx, MLX_KEY_S)) {
        game->player_img->instances[0].y += 1;
    }
    if (mlx_is_key_down(game->mlx, MLX_KEY_A)) {
        game->player_img->instances[0].x -= 1;
    }
    if (mlx_is_key_down(game->mlx, MLX_KEY_D)) {
        game->player_img->instances[0].x += 1;
    }
}

//void hook_player_movement(mlx_key_data_t keydata, void *param)
//{
//    t_game *game;
//
//    game = (t_game*)param;
//
//    if (keydata.key == MLX_KEY_W && keydata.action == MLX_REPEAT)
//        player_move_up(game);
//    if (keydata.key == MLX_KEY_S && keydata.action == MLX_REPEAT)
//        game->player_img->instances[0].y += 5;
//    if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
//        game->player_img->instances[0].x -= 5;
//    if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
//        game->player_img->instances[0].x += 5;
//
//}