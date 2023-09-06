//
// Created by angomes- on 9/5/23.
//

#include "../inc/so_long.h"

void    player_move_up(t_game *game)
{
    int x;
    int y;

    y = game->player_img->instances[0].y -= IMAGE_HEIGHT_HALF /16;
    x = game->player_img->instances[0].x += IMAGE_WIDTH_HALF /16;
    game->press_w++;
    if (game->press_w == 16 && game->map[game->player_y - 1][game->player_x] != '1')
    {
        update_player_movement(game, x, y, "./textures/idle_player_W.png");
        if (game->map[game->player_y][game->player_x] == 'C')
            collect(game);
        else if(game->n_collectable <= 0 && game->map[game->player_y][game->player_x] == 'E')
            exit(1);
        game->press_w = 0;
        ft_printf("W - instance %i x \n", game->player_img->instances[0].y, game->player_img->instances[0].x);
        ft_printf("W -- y = %i x = %i \n", game->player_y, game->player_x);
    }
}

void    player_move_down(t_game *game)
{
    int x;
    int y;

    y = game->player_img->instances[0].y += IMAGE_HEIGHT_HALF;
    x = game->player_img->instances[0].x -= IMAGE_WIDTH_HALF;
    update_player_movement(game, x, y, "./textures/idle_player_S.png");
    if (game->map[game->player_y][game->player_x] == 'C')
        collect(game);
    else if(game->n_collectable <= 0 && game->map[game->player_y][game->player_x] == 'E')
        exit(1);
    ft_printf("S - instance %i x = %i \n", game->player_img->instances[0].y, game->player_img->instances[0].x);
    ft_printf("S -- y = %i x = %i \n", game->player_y, game->player_x);
}

void    player_move_right(t_game *game)
{
    int x;
    int y;

    x = game->player_img->instances[0].x += IMAGE_WIDTH_HALF;
    y = game->player_img->instances[0].y += IMAGE_HEIGHT_HALF;
    update_player_movement(game, x, y, "./textures/idle_player_D.png");
    if (game->map[game->player_y][game->player_x] == 'C')
        collect(game);
    else if(game->n_collectable <= 0 && game->map[game->player_y][game->player_x] == 'E')
        exit(1);
    ft_printf("D - instance %i x = %i \n", game->player_img->instances[0].y, game->player_img->instances[0].x);
    ft_printf("D -- y = %i x = %i \n", game->player_y, game->player_x);
}

void    player_move_left(t_game *game)
{
    int x;
    int y;

    x = game->player_img->instances[0].x -= IMAGE_WIDTH_HALF;
    y = game->player_img->instances[0].y -= IMAGE_HEIGHT_HALF;
    update_player_movement(game, x, y, "./textures/idle_player_A.png");
    if (game->map[game->player_y][game->player_x] == 'C')
        collect(game);
    else if(game->n_collectable <= 0 && game->map[game->player_y][game->player_x] == 'E')
        exit(1);
    ft_printf("A - instance %i x = %i \n", game->player_img->instances[0].y, game->player_img->instances[0].x);
    ft_printf("A -- y = %i x = %i\n", game->player_y, game->player_x);
}