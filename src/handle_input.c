//
// Created by Andre on 17/08/23.
//

#include "../inc/so_long.h"

void hook_close_window(void *param)
{
    t_game *game;

    game = (t_game *)param;
    set_player_iso_x(game->player_img->instances[0].x,game->player_img->instances[0].y, game);
    set_player_iso_y(game->player_img->instances[0].x, game->player_img->instances[0].y, game);

    if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE)) {
        mlx_close_window(game->mlx);
    }

    /*if (mlx_is_key_down(game->mlx, MLX_KEY_W) && game->map[game->player_y - 1][game->player_x] != '1') {
        int32_t x;
        int32_t y;

        y = game->player_img->instances[0].y -= IMAGE_HEIGHT_HALF;
        x = game->player_img->instances[0].x += IMAGE_WIDTH_HALF;
        set_player_iso_x(x, y, game);
        set_player_iso_y(x, y, game);
        create_new_player_image(game, "./textures/idle_player_W.png");
        mlx_image_to_window(game->mlx, game->player_img, x, y);
        ft_printf("W - instance %i x \n", game->player_img->instances[0].y, game->player_img->instances[0].x);
        ft_printf("W -- y = %i x = %i \n", game->player_y, game->player_x);
    }

    if (mlx_is_key_down(game->mlx, MLX_KEY_S) && game->map[game->player_y + 1][game->player_x] != '1') {
        int32_t x;
        int32_t y;

        y = game->player_img->instances[0].y += IMAGE_HEIGHT_HALF;
        x = game->player_img->instances[0].x -= IMAGE_WIDTH_HALF;
        set_player_iso_x(x, y, game);
        set_player_iso_y(x, y, game);
        create_new_player_image(game, "./textures/idle_player_S.png");
        mlx_image_to_window(game->mlx, game->player_img, x, y);
        ft_printf("S - instance %i x = %i \n", game->player_img->instances[0].y, game->player_img->instances[0].x);
        ft_printf("S -- y = %i x = %i \n", game->player_y, game->player_x);
    }

    if (mlx_is_key_down(game->mlx, MLX_KEY_A) && game->map[game->player_y][game->player_x - 1] != '1') {
        int32_t x;
        int32_t y;

        x = game->player_img->instances[0].x -= IMAGE_WIDTH_HALF;
        y = game->player_img->instances[0].y -= IMAGE_HEIGHT_HALF;
        set_player_iso_x(x, y, game);
        set_player_iso_y(x, y, game);
        create_new_player_image(game, "./textures/idle_player_A.png");
        mlx_image_to_window(game->mlx, game->player_img, x, y);
        ft_printf("A - instance %i x  %i = %i \n", game->player_img->instances[0].y, game->player_img->instances[0].x);
        ft_printf("A -- y = %i x = %i\n", game->player_y, game->player_x);
    }

    if (mlx_is_key_down(game->mlx, MLX_KEY_D) && game->map[game->player_y][game->player_x + 1] != '1') {
        int32_t x;
        int32_t y;

        x = game->player_img->instances[0].x += IMAGE_WIDTH_HALF;
        y = game->player_img->instances[0].y += IMAGE_HEIGHT_HALF;
        set_player_iso_x(x, y, game);
        set_player_iso_y(x, y, game);
        create_new_player_image(game, "./textures/idle_player_D.png");
        mlx_image_to_window(game->mlx, game->player_img, x, y);
        ft_printf("D - instance %i x = %i \n", game->player_img->instances[0].y, game->player_img->instances[0].x);
        ft_printf("D -- y = %i x = %i \n", game->player_y, game->player_x);
    }*/
}

void hook_player_movement(mlx_key_data_t keydata, void *param)
{
    t_game *game;
    int x;
    int y;

    game = (t_game*)param;
    set_player_iso_x(game->player_img->instances[0].x, game->player_img->instances[0].y, game);
    set_player_iso_y(game->player_img->instances[0].x, game->player_img->instances[0].y, game);
    if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS && game->map[game->player_y - 1][game->player_x] != '1')
    {
        y = game->player_img->instances[0].y -= IMAGE_HEIGHT_HALF;
        x = game->player_img->instances[0].x += IMAGE_WIDTH_HALF;
        update_player_movement(game, x, y, "./textures/idle_player_W.png");
        if (game->map[game->player_y][game->player_x] == 'C') {
            int i;

            i = 0;
            while (i < game->n_collectable)
            {
                if (get_x_iso_to_cart(game->collectable_img->instances[i].x, game->collectable_img->instances[i].y, game) == game->player_x &&
                        get_y_iso_to_cart(game->collectable_img->instances[i].x, game->collectable_img->instances[i].y, game) == game->player_y)
                {
                    game->collectable_img->instances[i].enabled = 0;
                    ft_printf("disable coletable");
                }
                i++;
            }
        }
        ft_printf("W - instance %i x \n", game->player_img->instances[0].y, game->player_img->instances[0].x);
        ft_printf("W -- y = %i x = %i \n", game->player_y, game->player_x);
    }

    if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS && game->map[game->player_y + 1][game->player_x] != '1')
    {
        y = game->player_img->instances[0].y += IMAGE_HEIGHT_HALF;
        x = game->player_img->instances[0].x -= IMAGE_WIDTH_HALF;
        update_player_movement(game, x, y, "./textures/idle_player_S.png");
        ft_printf("S - instance %i x = %i \n", game->player_img->instances[0].y, game->player_img->instances[0].x);
        ft_printf("S -- y = %i x = %i \n", game->player_y, game->player_x);
    }

    if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS && game->map[game->player_y][game->player_x - 1] != '1')
    {
        x = game->player_img->instances[0].x -= IMAGE_WIDTH_HALF;
        y = game->player_img->instances[0].y -= IMAGE_HEIGHT_HALF;
        update_player_movement(game, x, y, "./textures/idle_player_A.png");
        ft_printf("A - instance %i x  %i = %i \n", game->player_img->instances[0].y, game->player_img->instances[0].x);
        ft_printf("A -- y = %i x = %i\n", game->player_y, game->player_x);
    }

    if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS && game->map[game->player_y][game->player_x + 1] != '1')
    {
        x = game->player_img->instances[0].x += IMAGE_WIDTH_HALF;
        y = game->player_img->instances[0].y += IMAGE_HEIGHT_HALF;
        update_player_movement(game, x, y, "./textures/idle_player_D.png");
        ft_printf("D - instance %i x = %i \n", game->player_img->instances[0].y, game->player_img->instances[0].x);
        ft_printf("D -- y = %i x = %i \n", game->player_y, game->player_x);
    }
}