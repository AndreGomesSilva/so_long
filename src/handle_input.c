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

    if (mlx_is_key_down(game->mlx, MLX_KEY_W) && game->map[game->player_y - 1][game->player_x] != '1') {
        game->player_img->instances[0].y -= 1;
        if (game->map[game->player_y][game->player_x + 1] != '1' && game->map[game->player_y][game->player_x + 2] != '1')
            game->player_img->instances[0].x += 2;
        set_player_iso_x(game->player_img->instances[0].x - game->window_w/2, game->player_img->instances[0].y - game->window_h/2, game);
        set_player_iso_y(game->player_img->instances[0].x - game->window_w/2, game->player_img->instances[0].y - game->window_h/2, game);
        ft_printf("W - instance %i x \n", game->player_img->instances[0].y, game->player_img->instances[0].x);
        ft_printf("W -- y = %i x = %i \n", game->player_y, game->player_x);
    }

    if (mlx_is_key_down(game->mlx, MLX_KEY_S) && game->map[game->player_y + 1][game->player_x] != '1') {
        game->player_img->instances[0].y += 1;
        if (game->map[game->player_y][game->player_x - 1] != '1' && game->map[game->player_y][game->player_x - 2] != '1')
            game->player_img->instances[0].x -= 2;
        set_player_iso_x(game->player_img->instances[0].x - game->window_w/2, game->player_img->instances[0].y - game->window_h/2, game);
        set_player_iso_y(game->player_img->instances[0].x - game->window_w/2, game->player_img->instances[0].y - game->window_h/2, game);
        ft_printf("S - instance %i x = %i \n", game->player_img->instances[0].y, game->player_img->instances[0].x);
        ft_printf("S -- y = %i x = %i \n", game->player_y, game->player_x);
    }

    if (mlx_is_key_down(game->mlx, MLX_KEY_A) && game->map[game->player_y][game->player_x - 1] != '1') {
        game->player_img->instances[0].x -= 2;
        if (game->map[game->player_y - 1][game->player_x] != '1')
            game->player_img->instances[0].y -= 1;
        set_player_iso_x(game->player_img->instances[0].x - game->window_w/2, game->player_img->instances[0].y - game->window_h/2, game);
        set_player_iso_y(game->player_img->instances[0].x - game->window_w/2, game->player_img->instances[0].y - game->window_h/2, game);
        ft_printf("A - instance %i x  %i = %i \n", game->player_img->instances[0].y, game->player_img->instances[0].x);
        ft_printf("A -- y = %i x = %i\n", game->player_y, game->player_x);
    }

    if (mlx_is_key_down(game->mlx, MLX_KEY_D) && game->map[game->player_y][game->player_x + 1] != '1') {
        game->player_img->instances[0].x += 2;
        if (game->map[game->player_y + 1][game->player_x] != '1')
            game->player_img->instances[0].y += 1;
        set_player_iso_x(game->player_img->instances[0].x - game->window_w/2, game->player_img->instances[0].y - game->window_h/2, game);
        set_player_iso_y(game->player_img->instances[0].x - game->window_w/2, game->player_img->instances[0].y - game->window_h/2, game);
        ft_printf("D - instance %i x = %i \n", game->player_img->instances[0].y, game->player_img->instances[0].x);
        ft_printf("D -- y = %i x = %i \n", game->player_y, game->player_x);
    }
}

//void hook_player_movement(mlx_key_data_t keydata, void *param)
//{
//    t_game *game;
//
//
//    game = (t_game*)param;
//    if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS && game->map[game->player_y - 1][game->player_x] != '1')
//    {
//      game->player_img->instances[0].y -= 2;
//        if (game->map[game->player_y][game->player_x + 1] != '1')
//            game->player_img->instances[0].x += 4;
//        set_player_iso_x(game->player_img->instances[0].x - game->window_w/2, game->player_img->instances[0].y - game->window_h/2, game);
//        set_player_iso_y(game->player_img->instances[0].x - game->window_w/2, game->player_img->instances[0].y - game->window_h/2, game);
//        ft_printf("W - instance %i x = %i \n", game->player_img->instances[0].y, game->player_img->instances[0].x);
//        ft_printf("W -- y = %i x = %i \n", game->player_y, game->player_x);
//    }
//    if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS && game->map[game->player_y + 1][game->player_x] != '1')
//    {
//       game->player_img->instances[0].y += 2;
//        if (game->map[game->player_y][game->player_x - 1] != '1')
//            game->player_img->instances[0].x -= 4;
//        set_player_iso_x(game->player_img->instances[0].x - game->window_w/2, game->player_img->instances[0].y - game->window_h/2, game);
//        set_player_iso_y(game->player_img->instances[0].x - game->window_w/2, game->player_img->instances[0].y - game->window_h/2, game);
//        ft_printf("S - instance %i x = %i \n", game->player_img->instances[0].y, game->player_img->instances[0].x);
//        ft_printf("S -- y = %i x = %i \n", game->player_y, game->player_x);
//    }
//    if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS && game->map[game->player_y][game->player_x - 1] != '1')
//    {
//         game->player_img->instances[0].x -= 2;
//        if (game->map[game->player_y - 1][game->player_x] != '1')
//            game->player_img->instances[0].y -= 4;
//        set_player_iso_x(game->player_img->instances[0].x - game->window_w/2, game->player_img->instances[0].y - game->window_h/2, game);
//        set_player_iso_y(game->player_img->instances[0].x - game->window_w/2, game->player_img->instances[0].y - game->window_h/2, game);
//        ft_printf("A - instance %i x  %i = %i \n", game->player_img->instances[0].y, game->player_img->instances[0].x);
//        ft_printf("A -- y = %i x = %i\n", game->player_y, game->player_x);
//    }
//    if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS && game->map[game->player_y][game->player_x + 1] != '1')
//    {
//         game->player_img->instances[0].x += 2;
//        if (game->map[game->player_y + 1][game->player_x] != '1')
//            game->player_img->instances[0].y += 4;
//        set_player_iso_x(game->player_img->instances[0].x - game->window_w/2, game->player_img->instances[0].y - game->window_h/2, game);
//        set_player_iso_y(game->player_img->instances[0].x - game->window_w/2, game->player_img->instances[0].y - game->window_h/2, game);
//        ft_printf("D - instance %i x = %i \n", game->player_img->instances[0].y, game->player_img->instances[0].x);
//        ft_printf("D -- y = %i x = %i \n", game->player_y, game->player_x);
//    }
//
//}