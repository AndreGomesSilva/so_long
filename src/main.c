#include "../inc/so_long.h"

enum game_mode{
    Menu,
    Playing,
    End
};

int	close(t_game *vars)
{
    mlx_destroy_window(vars->mlx, vars->window);
    return (0);
}

int	main(void)
{
    t_game	game;

    game.mlx = mlx_init();
    game.window = mlx_new_window(game.mlx,WINDOW_WIDTH, WINDOW_HEIGHT, "Hello world!");
    mlx_hook(game.window, 2, 1L<<0, close, &game);
    mlx_loop(game.mlx);
}