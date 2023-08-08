//
// Created by angomes- on 8/8/23.
//

#include "../inc/so_long.h"


int	close_win(t_game *vars)
{
    mlx_destroy_window(vars->mlx, vars->window);
    return (0);
}

int game_init(char *str)
{
    t_game game;
    printf("%s", str);
    char *relative_path = "../sprites/Idle.xpm";
    int img_width;
    int img_height;
    void *img;

    game.mlx = mlx_init();
    game.window = mlx_new_window(game.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "so_long");
    img =  mlx_xpm_file_to_image(game.mlx, relative_path, &img_width, &img_height);
    mlx_put_image_to_window(game.mlx, game.window,img, 100, 100);
    mlx_hook(game.window, 2, 1L<<0, close_win, &game);
    mlx_loop(game.mlx);
    return(1);
}