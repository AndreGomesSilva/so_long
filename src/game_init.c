
#include "../inc/so_long.h"
#include <stdio.h>

//void print_matrix(char **matrix)
//{
//    int32_t x;
//    int32_t y;
//
//    y = 0;
//    while(matrix[y])
//    {
//        x = 0;
//        while (matrix[y][x])
//        {
//            ft_printf("%c", matrix[y][x]);
//            x++;
//        }
//        y++;
//    }
//}

void	free_game(t_game *game)
{
	free_images(game);
	free_textures(game);
	mlx_terminate(game->mlx);
	free_map(game->map);
}

void	get_size_window(t_game *game)
{
	int	i;

	i = 0;
	game->map_row = (int)ft_strlen(*game->map);
	game->window_w = game->map_row * IMAGE_WIDTH;
	while (game->map[i])
		i++;
	game->map_col = i;
	game->window_h = game->map_col * IMAGE_HEIGHT;
}

int32_t	game_init(char *str)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	game.map = get_map(str);
	if (map_is_rectangle(&game) && number_player_and_exit(&game))
	{
		get_size_window(&game);
		game.mlx = mlx_init(game.window_w, game.window_h, "So_long", true);
		check_window_size(&game);
		if (!game.mlx)
			ft_error("ERROR = fail to init the window\n");
		if (map_construct(&game))
			draw_map(&game);
		else
			ft_error("ERROR = fail to construct the map\n");
	}
	else
		ft_error("ERROR = map has to be rectangle and have one player and exit only\n");
	ft_printf(" \n instance -> y=%i - x=%i \n", game.player_img->instances[0].y,
			game.player_img->instances[0].x);
	ft_printf("position on map -> y=%i  - x=%i \n", game.player_y, game.player_x);
	mlx_loop_hook(game.mlx, &hook_close_window, &game);
    mlx_key_hook(game.mlx, &hook_player_movement, &game);
	mlx_loop(game.mlx);
	free_game(&game);
	return (EXIT_SUCCESS);
}
