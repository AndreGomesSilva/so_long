
#include "../inc/so_long.h"



//void move_player(mlx_key_data_t keydata, t_game *game, void *param)
//{
//    if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
//    {
//        game->player_texture = mlx_load_png("./textures/tile002.png");
//        game->player_img = mlx_texture_to_image(game->mlx, game->player_texture);
//
//}
void print_matrix(char **matrix)
{
    int32_t x;
    int32_t y;

    y = 0;
    while(matrix[y])
    {
        x = 0;
        while (matrix[y][x])
        {
            ft_printf("%c", matrix[y][x]);
            x++;
        }
        y++;
    }
}

void get_size_window(t_game *game)
{
    int32_t i;

    i = 0;
    game->map_row = (int32_t)ft_strlen(*game->map);
    game->window_w = game->map_row * IMAGE_WIDTH;
    while (game->map[i])
        i++;
    game->map_col = i;
    game->window_h = game->map_col * IMAGE_HEIGHT;
}

int32_t	game_init(char *str)
{
    t_game game;

    game.map = get_map(str);
    if (map_is_rectangle(&game) && number_player_and_exit(&game))
    {
        get_size_window(&game);
        game.mlx = mlx_init(game.window_w + game.window_w/4, game.window_h * 2, "So_long", true);
        if (!game.mlx)
            ft_error("ERROR = fail to init the window\n");

        if (map_construct(&game))
            draw_map(&game);
        else
            ft_error("ERROR = fail to construct the map\n");
    }
    else
        ft_error("ERROR = map has to be rectangle and have one player and exit only\n");

//    cartesian_to_isometric_map(&game);
    print_matrix(game.map);
    ft_printf(" \n instance %i x = %i \n", game.player_img->instances[0].y, game.player_img->instances[0].x);
    ft_printf("y = %i x = %i \n", game.player_y, game.player_x);
    mlx_loop_hook(game.mlx, &hook_close_window, &game);
//    mlx_key_hook(game.mlx, &hook_player_movement, &game);
    mlx_loop(game.mlx);
    free_images(&game);
    free_textures(&game);
    free_map(game.map);
    mlx_terminate(game.mlx);
    return (EXIT_SUCCESS);
}
