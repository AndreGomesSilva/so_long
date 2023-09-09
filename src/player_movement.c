//
//
// Created by angomes- on 9/5/23.

#include "../inc/so_long.h"

void    player_move_up(t_game *game)
{
    game->player_img->instances[0].y -= 1;
    game->player_y -= 1;
    update_player_movement(game,"./textures/player_idle/right/tile000.png");
    if (game->map[game->player_y][game->player_x] == 'C')
        collect(game);
    else if(game->n_collectable <= 0 && game->map[game->player_y][game->player_x] == 'E')
        exit(1);
    ft_printf("W - instance %i x = %i \n", game->player_img->instances[0].y, game->player_img->instances[0].x);
    ft_printf("W -- y = %i x = %i \n", game->player_y, game->player_x);
}

void    player_move_down(t_game *game)
{
    game->player_img->instances[0].y += 1;
    game->player_y += 1;
    update_player_movement(game,"./textures/player_idle/right/tile000.png");
    if (game->map[game->player_y][game->player_x] == 'C')
        collect(game);
    else if(game->n_collectable <= 0 && game->map[game->player_y][game->player_x] == 'E')
        exit(1);
    ft_printf("S - instance %i x = %i \n", game->player_img->instances[0].y, game->player_img->instances[0].x);
    ft_printf("S -- y = %i x = %i \n", game->player_y, game->player_x);
}

void    player_move_right(t_game *game)
{
    game->player_img->instances[0].x += 1;
    game->player_x += 1;
    update_player_movement(game,"./textures/player_idle/right/tile000.png");
    if (game->map[game->player_y][game->player_x] == 'C')
        collect(game);
    else if(game->n_collectable <= 0 && game->map[game->player_y][game->player_x] == 'E')
        exit(1);
    ft_printf("D - instance %i x = %i \n", game->player_img->instances[0].y, game->player_img->instances[0].x);
    ft_printf("D -- y = %i x = %i \n", game->player_y, game->player_x);
}

void    player_move_left(t_game *game)
{
    game->player_img->instances[0].x -= 1;
    game->player_x -= 1;
    update_player_movement(game, "./textures/player_idle/right/tile000.png");
    if (game->map[game->player_y][game->player_x] == 'C')
        collect(game);
    else if(game->n_collectable <= 0 && game->map[game->player_y][game->player_x] == 'E')
        exit(1);
    ft_printf("A - instance %i x = %i \n", game->player_img->instances[0].y, game->player_img->instances[0].x);
    ft_printf("A -- y = %i x = %i\n", game->player_y, game->player_x);
}