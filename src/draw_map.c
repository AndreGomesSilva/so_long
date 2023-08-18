//
// Created by Andre on 15/08/23.
//

#include "../inc/so_long.h"

void draw_layers(t_game *game, mlx_image_t *img, int type)
{
    int32_t x;
    int32_t y;

    y = 0;
    while(game->map[y] != NULL)
    {
        x = 0;
        while (game->map[y][x] != '\0')
        {
            if (type == '0')
                mlx_image_to_window(game->mlx, img, game->window_w/2 + ((x - y) * IMAGE_WIDTH/2), game->window_h/2 + ((x + y) * IMAGE_HEIGHT/2));
            else if (game->map[y][x] == type)
                mlx_image_to_window(game->mlx, img, game->window_w/2 + ((x - y) * IMAGE_WIDTH/2), game->window_h/2 - 8 + ((x + y) * IMAGE_HEIGHT/2));
            x++;
        }
        y++;
    }
}

void draw_map(t_game *game)
{
    draw_layers(game, game->background_img, '0') ;
    draw_layers(game, game->collectable_img, 'C');
    draw_layers(game, game->exit_img, 'E');
    draw_layers(game, game->wall_img, '1');
    draw_layers(game, game->player_img, 'P');
}

int32_t map_construct(t_game *game)
{
    if (create_texture_from_png(game))
    {
        create_img_from_texture(game);
        return (TRUE);
    }
    else
        return (FALSE);
}

