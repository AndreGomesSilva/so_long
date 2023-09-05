//
// Created by Andre on 31/08/23.
//

#include "so_long.h"

void    check_window_size(t_game *game)
{
    if (game->mlx->width <= 800 && game->mlx->height <= 600)
    {
        game->image_new_width = 64;
        game->image_new_height = 64;
    }
    else if (game->mlx->width <= 1920 && game->mlx->height <= 1080)
    {
        game->image_new_width = 80;
        game->image_new_height = 80;
    }
}