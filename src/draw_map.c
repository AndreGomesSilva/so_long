//
// Created by Andre on 15/08/23.
//

#include "../inc/so_long.h"

void set_player_iso_x(int32_t x, int32_t y, t_game *game)
{
    game->player_x = ((((x / IMAGE_WIDTH_HALF) + (y / IMAGE_HEIGHT_HALF)) / 2));
}

void set_player_iso_y(int32_t x, int32_t y, t_game *game)
{
    game->player_y = (((y / IMAGE_HEIGHT_HALF) - ( x / IMAGE_WIDTH_HALF)) / 2);
}

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
//            mlx_image_to_window(game->mlx, game->background_img, ((x - y) * IMAGE_WIDTH_HALF), ((x + y) * IMAGE_HEIGHT_HALF));
//            if (game->map[y][x] == '1')
//            {
//                mlx_image_to_window(game->mlx, game->wall_img, ((x - y) * IMAGE_WIDTH_HALF), ((x + y) * IMAGE_HEIGHT_HALF));
//            }
//            else if(game->map[y][x] == 'P')
//            {
//                game->player_x = x;
//                game->player_y = y;
//                mlx_image_to_window(game->mlx, game->player_img, ((x - y) * IMAGE_WIDTH_HALF), ((x + y) * IMAGE_HEIGHT_HALF));
//            }
//            else if(game->map[y][x] == 'C')
//            {
//                mlx_image_to_window(game->mlx, game->collectable_img, ((x - y) * IMAGE_WIDTH_HALF), ((x + y) * IMAGE_HEIGHT_HALF));
//            }
//            else if(game->map[y][x] == 'E')
//            {
//                mlx_image_to_window(game->mlx, game->exit_img, ((x - y) * IMAGE_WIDTH_HALF), ((x + y) * IMAGE_HEIGHT_HALF));
//            }
            if (type == '0')
                mlx_image_to_window(game->mlx, img,  ((x - y) * IMAGE_WIDTH_HALF),  ((x + y) * IMAGE_HEIGHT_HALF));
            else if (game->map[y][x] == type)
            {
                if (type == 'P')
                {
//                    game->player_x = x;
//                    game->player_y = y;
                    mlx_image_to_window(game->mlx, img,  ((x - y) * IMAGE_WIDTH_HALF),  ((x + y) * IMAGE_HEIGHT_HALF));
//                    game->player_x = (((game->player_img->instances[0].x / IMAGE_WIDTH_HALF) + (game->player_img->instances[0].y / IMAGE_HEIGHT_HALF)) / 2);
//                    game->player_y = (((game->player_img->instances[0].y / IMAGE_HEIGHT_HALF) - (game->player_img->instances[0].x / IMAGE_WIDTH_HALF)) / 2);
                    set_player_iso_x(game->player_img->instances[0].x, game->player_img->instances[0].y, game);
                    set_player_iso_y(game->player_img->instances[0].x, game->player_img->instances[0].y, game);
                }
                else
                    mlx_image_to_window(game->mlx, img, ((x - y) * IMAGE_WIDTH_HALF), ((x + y) * IMAGE_HEIGHT_HALF));
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

