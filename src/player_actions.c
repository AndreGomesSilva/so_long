//
// Created by Andre on 17/08/23.
//

#include "../inc/so_long.h"


void    update_player_movement(t_game *game, char *path)
{
    create_new_player_image(game, path);
    mlx_image_to_window(game->mlx, game->player_img,game->player_x * IMAGE_WIDTH, game->player_y * IMAGE_HEIGHT);
}