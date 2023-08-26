//
// Created by Andre on 15/08/23.
//

#include "../inc/so_long.h"


//void draw_layers(t_game *game) {
//    int32_t x;
//    int32_t y;
//
//    y = 0;
//    while (game->map[y] != NULL) {
//        x = 0;
//        while (game->map[y][x]) {
//            mlx_image_to_window(game->mlx, game->background_img, game->window_w / 2 + ((x - y) * IMAGE_WIDTH_HALF),
//                                game->window_h / 2 + ((x + y) * IMAGE_HEIGHT_HALF));
//            if (game->map[y][x] == '1')
//            {
//                mlx_image_to_window(game->mlx, game->wall_img, game->window_w / 2 + ((x - y) * IMAGE_WIDTH_HALF),
//                                    game->window_h / 2 + ((x + y) * IMAGE_HEIGHT_HALF));
//            }
//            else if (game->map[y][x] == 'P')
//            {
//                mlx_image_to_window(game->mlx, game->player_img, game->window_w / 2 + ((x - y) * IMAGE_WIDTH_HALF),
//                                    game->window_h / 2 + ((x + y) * IMAGE_HEIGHT_HALF));
//                set_player_iso_x(game->player_img->instances[0].x - game->window_w/2, game->player_img->instances[0].y - game->window_h/2, game);
//                set_player_iso_y(game->player_img->instances[0].x - game->window_w/2, game->player_img->instances[0].y - game->window_h/2, game);
//            }
////            else if (game->map[y][x] == 'C')
////                mlx_image_to_window(game->mlx, game->collectable_img, game->window_w / 2 + ((x - y) * IMAGE_WIDTH_HALF),
////                                    game->window_h / 2 + ((x + y) * IMAGE_HEIGHT_HALF));
////            else if (game->map[y][x] == 'E')
////                mlx_image_to_window(game->mlx, game->exit_img, game->window_w / 2 + ((x - y) * IMAGE_WIDTH_HALF),
////                                    game->window_h / 2 + ((x + y) * IMAGE_HEIGHT_HALF));
//            x++;
//        }
//        y++;
//    }
//}

void draw_layers(t_game *game, mlx_image_t *img, char type)
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
                mlx_image_to_window(game->mlx, img, game->window_w/2 + ((x - y) * IMAGE_WIDTH_HALF),  game->window_h/2 + ((x + y) * IMAGE_HEIGHT_HALF));
            else if (game->map[y][x] == type)
            {
                if (type == 'P')
                {
                    mlx_image_to_window(game->mlx, img, game->window_w/2 + ((x - y) * IMAGE_WIDTH_HALF),  game->window_h/2 + ((x + y) * IMAGE_HEIGHT_HALF));
                    set_player_iso_x(game->player_img->instances[0].x - game->window_w/2, game->player_img->instances[0].y - game->window_h/2, game);
                    set_player_iso_y(game->player_img->instances[0].x - game->window_w/2, game->player_img->instances[0].y - game->window_h/2, game);
                }
                else
                    mlx_image_to_window(game->mlx, img, game->window_w/2 + ((x - y) * IMAGE_WIDTH_HALF), game->window_h/2 +  ((x + y) * IMAGE_HEIGHT_HALF));
            }
            x++;
        }
        y++;
    }
}

void draw_map(t_game *game)
{
//    draw_layers(game);
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

