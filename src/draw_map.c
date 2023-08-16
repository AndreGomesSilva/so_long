//
// Created by Andre on 15/08/23.
//

#include "../inc/so_long.h"

void draw_map(t_game *game)
{
    int x;
    int y;

    y = 0;
    while(game->map[y] != NULL)
    {
        x = 0;
        while (game->map[y][x] != '\0')
        {
            mlx_image_to_window(game->mlx, game->background_img, x * 32, y * 32);
            if(game->map[y][x] == '1')
                mlx_image_to_window(game->mlx, game->wall_img, x * 32, y * 32);
            else if(game->map[y][x] == 'P')
                mlx_image_to_window(game->mlx, game->player_img, x * 32, y * 32);
            else if(game->map[y][x] == 'E')
                mlx_image_to_window(game->mlx, game->exit_img, x * 32, y * 32);
            else if(game->map[y][x] == 'C')
                mlx_image_to_window(game->mlx, game->collectable_img, x * 32, y * 32);
            x++;
        }
        y++;
    }
}

int32_t map_construct(t_game *game)
{
    int x;
    int y;

    x = 32;
    y = 32;
    game->background_texture = mlx_load_png("./textures/Grass.png");
    game->wall_texture = mlx_load_png("./textures/Rock.png");
    game->player_texture = mlx_load_png("./textures/tile000.png");
    game->exit_texture = mlx_load_png("./textures/tile018.png");
    game->collectable_texture = mlx_load_png("./textures/Mushroom_02.png");
    if (!game->background_texture || !game->wall_texture || !game->player_texture || !game->collectable_texture || !game->exit_texture)
        return (FALSE);
    else
    {
        game->player_img = mlx_texture_to_image(game->mlx, game->player_texture);
        game->exit_img = mlx_texture_to_image(game->mlx, game->exit_texture);
        game->background_img = mlx_texture_to_image(game->mlx, game->background_texture);
        game->wall_img = mlx_texture_to_image(game->mlx, game->wall_texture);
        game->collectable_img= mlx_texture_to_image(game->mlx, game->collectable_texture);
        mlx_resize_image(game->collectable_img, x, y);
        mlx_resize_image(game->background_img, x, y);
        mlx_resize_image(game->wall_img, x, y);
        mlx_resize_image(game->player_img, x, y);
        mlx_resize_image(game->exit_img, x, y);
        return(TRUE);
    }
    return(0);
}

