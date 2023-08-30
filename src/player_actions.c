//
// Created by Andre on 17/08/23.
//

#include "../inc/so_long.h"

void set_player_iso_x(int32_t x, int32_t y, t_game *game)
{
    x -= game->start_x;
    y -= game->start_y;
    game->player_x = (((((x) / IMAGE_WIDTH_HALF) + (y / IMAGE_HEIGHT_HALF)) / 2));
}

void set_player_iso_y(int32_t x, int32_t y, t_game *game)
{
    x -= game->start_x;
    y -= game->start_y;
    game->player_y = ((((y) / IMAGE_HEIGHT_HALF) - ((x) / IMAGE_WIDTH_HALF)) / 2);
}