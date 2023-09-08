//
// Created by Andre on 17/08/23.
//

#include "../inc/so_long.h"

void continue_movement(t_game *game)
{
    if (game->press_up > 0 && game->press_up <= MOVE_RANGE)
    {
        player_move_up(game);
        if(game->press_up == MOVE_RANGE)
            game->press_up = 0;
    }
    else if (game->press_down && game->press_down <= MOVE_RANGE)
    {
        player_move_down(game);
        if(game->press_down == MOVE_RANGE)
            game->press_down = 0;
    }
    else if (game->press_left && game->press_left <= MOVE_RANGE)
    {
        player_move_left(game);
        if(game->press_left == MOVE_RANGE)
            game->press_left = 0;
    }
    else if (game->press_right && game->press_right <= MOVE_RANGE)
    {
        player_move_right(game);
        if(game->press_right == MOVE_RANGE)
            game->press_right = 0;
    }
}

void hook_close_window(void *param)
{
    t_game *game;

    game = (t_game*)param;
    if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE)) {
        mlx_close_window(game->mlx);
    }

   if (game->press_up || game->press_down || game->press_left || game->press_right)
       continue_movement(game);

    if ((mlx_is_key_down(game->mlx, MLX_KEY_W) || mlx_is_key_down(game->mlx, MLX_KEY_UP)) &&
    game->map[game->player_y - 1][game->player_x] != '1' && !game->press_up)
        player_move_up(game);

    else if (mlx_is_key_down(game->mlx, MLX_KEY_S) && game->map[game->player_y + 1][game->player_x] != '1' && !game->press_down)
        player_move_down(game);


    else if (mlx_is_key_down(game->mlx, MLX_KEY_A) && game->map[game->player_y][game->player_x - 1] != '1' && !game->press_left)
        player_move_left(game);


    else if (mlx_is_key_down(game->mlx, MLX_KEY_D) && game->map[game->player_y][game->player_x + 1] != '1' && !game->press_right)
        player_move_right(game);

}

//void hook_player_movement(mlx_key_data_t keydata, void *param)
//{
//    t_game *game;
//
//    game = (t_game*)param;
//    set_player_iso_x(game->player_img->instances[0].x, game->player_img->instances[0].y, game);
//    set_player_iso_y(game->player_img->instances[0].x, game->player_img->instances[0].y, game);
//
//    if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS && game->map[game->player_y - 1][game->player_x] != '1')
//    {
//       player_move_up(game);
//    }
//    if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS && game->map[game->player_y + 1][game->player_x] != '1')
//    {
//        player_move_down(game);
//    }
//
//    if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS && game->map[game->player_y][game->player_x - 1] != '1')
//    {
//        player_move_left(game);
//    }
//
//    if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS && game->map[game->player_y][game->player_x + 1] != '1')
//    {
//        player_move_right(game);
//    }
//}