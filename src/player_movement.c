#include "../inc/so_long.h"

void    player_move_up(t_window *window, t_game *game)
{
    game->player_y -= 1;
    update_player_movement(window, game,"./textures/player_idle/up/tile000.png");
    if (game->map[game->player_y][game->player_x] == 'C')
        collect(window, game);
    else if(game->collectable_number <= 0 && game->map[game->player_y][game->player_x] == 'E')
    {
        free_game(window, game);
        exit(1);
    }
}

void    player_move_down(t_window *window, t_game *game)
{
    game->player_y += 1;
    update_player_movement(window, game,"./textures/player_idle/down/tile000.png");
    if (game->map[game->player_y][game->player_x] == 'C')
        collect(window, game);
    else if(game->collectable_number <= 0 && game->map[game->player_y][game->player_x] == 'E')
    {
        free_game(window, game);
        exit(1);
    }
}

void    player_move_right(t_window *window, t_game *game)
{
    game->player_x += 1;
    update_player_movement(window, game,"./textures/player_idle/right/tile000.png");
    if (game->map[game->player_y][game->player_x] == 'C')
        collect(window, game);
    else if(game->collectable_number <= 0 && game->map[game->player_y][game->player_x] == 'E')
    {
        free_game(window, game);
        exit(1);
    }
}

void    player_move_left(t_window *window, t_game *game)
{
    game->player_x -= 1;
    update_player_movement(window, game, "./textures/player_idle/left/tile000.png");
    if (game->map[game->player_y][game->player_x] == 'C')
        collect(window, game);
    else if(game->collectable_number <= 0 && game->map[game->player_y][game->player_x] == 'E')
    {
        free_game(window, game);
        exit(1);
    }
}

void    update_player_movement(t_window *window, t_game *game, char *path)
{
    create_new_player_image(window, path);
    mlx_image_to_window(window->mlx, window->player_img,game->player_x * IMAGE_WIDTH, game->player_y * IMAGE_HEIGHT);
    game->n_player_movement++;
    ft_printf("\n Number of player moves: %i \n", game->n_player_movement);
}
