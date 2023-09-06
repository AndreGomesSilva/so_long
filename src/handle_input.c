//
// Created by Andre on 17/08/23.
//

#include "../inc/so_long.h"

void hook_close_window(void *param)
{
      t_game *game;

    game = (t_game*)param;
    set_player_iso_x(game->player_img->instances[0].x, game->player_img->instances[0].y, game);
    set_player_iso_y(game->player_img->instances[0].x, game->player_img->instances[0].y, game);

    if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE)) {
        mlx_close_window(game->mlx);
    }

    if (mlx_is_key_down(game->mlx, MLX_KEY_W) && game->map[game->player_y - 1][game->player_x] != '1') {
        player_move_up(game);
    }

    if (mlx_is_key_down(game->mlx, MLX_KEY_S) && game->map[game->player_y + 1][game->player_x] != '1') {
        player_move_down(game);
    }

    if (mlx_is_key_down(game->mlx, MLX_KEY_A) && game->map[game->player_y][game->player_x - 1] != '1') {
        player_move_left(game);
    }

    if (mlx_is_key_down(game->mlx, MLX_KEY_D) && game->map[game->player_y][game->player_x + 1] != '1') {
        player_move_right(game);
    }
}

void hook_player_movement(mlx_key_data_t keydata, void *param)
{
    t_game *game;

    game = (t_game*)param;
    set_player_iso_x(game->player_img->instances[0].x, game->player_img->instances[0].y, game);
    set_player_iso_y(game->player_img->instances[0].x, game->player_img->instances[0].y, game);
    ft_printf("\n ###collect -> remain = %i  ###\n", game->n_collectable);

    if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS && game->map[game->player_y - 1][game->player_x] != '1')
    {
       player_move_up(game);
    }
    if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS && game->map[game->player_y + 1][game->player_x] != '1')
    {
        player_move_down(game);
    }

    if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS && game->map[game->player_y][game->player_x - 1] != '1')
    {
        player_move_left(game);
    }

    if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS && game->map[game->player_y][game->player_x + 1] != '1')
    {
        player_move_right(game);
    }
}