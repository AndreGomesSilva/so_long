//
// Created by angomes- on 9/1/23.
//
#include "../inc/so_long.h"

int collect(t_window *window, t_game *game)
{
    int i;

    i = 0;
    while (i < game->collectable_remain)
    {
        if (window->collectable_img->instances[i].x / IMAGE_WIDTH == game->player_x &&
            window->collectable_img->instances[i].y / IMAGE_HEIGHT == game->player_y)
        {
            window->collectable_img->instances[i].enabled = 0;
            game->map[game->player_y][game->player_x] = '0';
            game->collectable_number -= 1;
        }
        i++;
    }
    if (game->collectable_number <= 0)
        draw_layers(window, game,'E');
  return(TRUE);
}
