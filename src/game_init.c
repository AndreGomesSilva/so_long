
#include "../inc/so_long.h"



void	free_game(t_window *window, t_game *game)
{
	free_images(window);
	free_textures(window);
	mlx_terminate(window->mlx);
	free_map(game->map);
}


int32_t	game_init(char *str)
{
	t_game	game;
    t_window   window;

    ft_bzero(&game, sizeof(t_game));
    ft_bzero(&window, sizeof(t_window));
    window.game = &game;
	game.map = get_map(str);
	if (map_is_rectangle(&game) && right_tile_set(&game))
	{
        get_size_window(&game);
        validate_map(&game, str);
		window.mlx = mlx_init(game.window_w, game.window_h, "So_long", true);
		if (!window.mlx)
			ft_error("ERROR = fail to init the window\n");
		if (map_construct(&window))
			draw_map(&window, &game);
		else
			ft_error("ERROR = fail to construct the map\n");
	}
	else
		ft_error("ERROR = map has to be rectangle and have one player, exit and at least one collection\n");
    mlx_loop_hook(window.mlx, &hook_close_window, &window);
    mlx_key_hook(window.mlx, &hook_player_movement, &window);
	mlx_loop(window.mlx);
    free_game(&window, &game);
	return (EXIT_SUCCESS);
}
