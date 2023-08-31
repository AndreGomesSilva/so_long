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

void    update_player_movement(t_game *game, int x, int y, char *path)
{
    set_player_iso_x(x, y, game);
    set_player_iso_y(x, y, game);
    create_new_player_image(game, path);
    mlx_image_to_window(game->mlx, game->player_img, x, y);
}

int get_x_iso_to_cart(int x, int y, t_game *game)
{
    int result;

    x -= game->start_x;
    y -= game->start_y;
    result = (((((x) / IMAGE_WIDTH_HALF) + (y / IMAGE_HEIGHT_HALF)) / 2));
    ft_printf("x -> C = %i ", result);
    return (result);
}

int get_y_iso_to_cart(int x, int y, t_game *game)
{
    int result;

    x -= game->start_x;
    y -= game->start_y;

   result = ((((y) / IMAGE_HEIGHT_HALF) - ((x) / IMAGE_WIDTH_HALF)) / 2);
   ft_printf("y -> C = %i ", result);
   return(result);
}