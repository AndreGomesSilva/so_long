//
// Created by Andre on 17/08/23.
//

#include "../inc/so_long.h"

void set_player_iso_x(int32_t x, int32_t y, t_game *game)
{
    game->player_x = (((((x) / IMAGE_WIDTH_HALF) + (y / IMAGE_HEIGHT_HALF)) / 2));
}

void set_player_iso_y(int32_t x, int32_t y, t_game *game)
{
    game->player_y = ((((y) / IMAGE_HEIGHT_HALF) - ( x / IMAGE_WIDTH_HALF))/ 2);
}

//void    player_move_up(t_game *game)
//{
//    game->player_img->instances[0].y -= 1;
////    ft_printf("\n width: %i  -- height: %i", game->player_img->instances[0].x, game->player_img->instances[0].y);
////    mlx_delete_texture(game->player_texture);
////    game->player_texture = (mlx_load_png("./textures/player_movement/tile016.png"));
////    mlx_delete_image(game->mlx, game->player_img);
////    game->player_img = mlx_texture_to_image(game->mlx, game->player_texture);
//}