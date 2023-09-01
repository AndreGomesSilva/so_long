//
// Created by angomes- on 9/1/23.
//
#include "../inc/so_long.h"

int collect(t_game *game)
{
    int i;

    i = 0;
    while (i < game->r_collectable)
    {
        if (get_x_iso_to_cart(game->collectable_img->instances[i].x, game->collectable_img->instances[i].y, game) == game->player_x &&
            get_y_iso_to_cart(game->collectable_img->instances[i].x, game->collectable_img->instances[i].y, game) == game->player_y)
        {
            game->collectable_img->instances[i].enabled = 0;
            ft_printf("\n ###collect -> remain = %i instance -> %i ###\n", game->n_collectable, i);
            game->map[game->player_y][game->player_x] = '0';
            game->n_collectable -= 1;
        }
        i++;
    }
    if (game->n_collectable <= 0)
        draw_layers(game, game->exit_img, 'E');
  return(1);
}
