//
//
// Created by angomes- on 9/5/23.

#include "../inc/so_long.h"

void    player_move_up(t_game *game)
{
    game->player_y -= 1;
    update_player_movement(game,"./textures/player_idle/up/tile000.png");
    if (game->map[game->player_y][game->player_x] == 'C')
        collect(game);
    else if(game->n_collectable <= 0 && game->map[game->player_y][game->player_x] == 'E')
    {
        free_game(game);
        exit(1);
    }
    game->n_player_move++;
    ft_printf("\n Number of movement of Player: %i \n", game->n_player_move);
    ft_printf(" W -- y = %i x = %i \n", game->player_y, game->player_x);
}

void    player_move_down(t_game *game)
{
    game->player_y += 1;
    update_player_movement(game,"./textures/player_idle/down/tile000.png");
    if (game->map[game->player_y][game->player_x] == 'C')
        collect(game);
    else if(game->n_collectable <= 0 && game->map[game->player_y][game->player_x] == 'E')
    {
        free_game(game);
        exit(1);
    }
    game->n_player_move++;
    ft_printf("\n Number of movement of Player: %i \n", game->n_player_move);
    ft_printf(" S -- y = %i x = %i \n", game->player_y, game->player_x);
}

void    player_move_right(t_game *game)
{
    game->player_x += 1;
    update_player_movement(game,"./textures/player_idle/right/tile000.png");
    if (game->map[game->player_y][game->player_x] == 'C')
        collect(game);
    else if(game->n_collectable <= 0 && game->map[game->player_y][game->player_x] == 'E')
    {
        free_game(game);
        exit(1);
    }
    game->n_player_move++;
    ft_printf("\n Number of movement of Player: %i \n", game->n_player_move);
    ft_printf(" D -- y = %i x = %i \n", game->player_y, game->player_x);
}

void    player_move_left(t_game *game)
{
    game->player_x -= 1;
    update_player_movement(game, "./textures/player_idle/left/tile000.png");
    if (game->map[game->player_y][game->player_x] == 'C')
        collect(game);
    else if(game->n_collectable <= 0 && game->map[game->player_y][game->player_x] == 'E')
    {
        free_game(game);
        exit(1);
    }
    game->n_player_move++;
    ft_printf("\n Number of movement of Player: %i \n", game->n_player_move);
    ft_printf("A -- y = %i x = %i\n", game->player_y, game->player_x);
}

void    update_player_movement(t_game *game, char *path)
{
    create_new_player_image(game, path);
    mlx_image_to_window(game->mlx, game->player_img,game->player_x * IMAGE_WIDTH, game->player_y * IMAGE_HEIGHT);
}
