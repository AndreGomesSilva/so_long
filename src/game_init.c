
#include "../inc/so_long.h"

void hook(void *param)
{
    if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
        mlx_close_window(param);
}

//void move_player(mlx_key_data_t keydata, t_game *game, void *param)
//{
//    if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
//    {
//        game->player_texture = mlx_load_png("./textures/tile002.png");
//        game->player_img = mlx_texture_to_image(game->mlx, game->player_texture);
//    }
//}



int32_t	game_init(char *str)
{
    t_game game;

    game.mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "So_long", true);
    if (!game.mlx)
        ft_error("ERROR = fail to init the window");

    game.map = get_map(str);
    if (map_is_rectangle(&game) && number_player_and_exit(&game))
    {
        map_construct(&game);
        draw_map(&game);
    }
    else
        ft_error("ERROR = map has to be rectangle and have one player and exit only\n");

    mlx_loop_hook(game.mlx, &hook, game.mlx);
    mlx_loop(game.mlx);
    mlx_delete_image(game.mlx, game.background_img);
    mlx_delete_image(game.mlx, game.wall_img);
    mlx_delete_image(game.mlx, game.player_img);
    mlx_delete_image(game.mlx, game.exit_img);
    mlx_delete_image(game.mlx, game.collectable_img);

    mlx_delete_texture(game.collectable_texture);
    mlx_delete_texture(game.background_texture);
    mlx_delete_texture(game.wall_texture);
    mlx_delete_texture(game.player_texture);
    mlx_delete_texture(game.exit_texture);
    mlx_terminate(game.mlx);
    return (EXIT_SUCCESS);
}
