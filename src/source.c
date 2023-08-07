//
// Created by angomes- on 8/7/23.
//
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

int mouse_event(void *param){
    t_game *click = param;
    mlx_pixel_put(click->mlx, click->window, WINDOW_WIDTH/2, WINDOW_HEIGHT/2, 0xFF0000);
    return (1);
}

double sqrt(double x) {
    if (x < 0) {
        // Handle negative input (NaN)
        return 0.0 / 0.0;
    }

    double guess = x;
    double prevGuess;

    do {
        prevGuess = guess;
        guess = 0.5 * (prevGuess + x / prevGuess);
    } while (prevGuess - guess > 1e-9);

    return guess;
}


int draw_line(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color)
{
    double deltaX = endX - beginX;
    double deltaY = endY - beginY;
    int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));

    deltaX /= pixels;
    deltaY /= pixels;

    double pixelX = beginX;
    double pixelY = beginY;
    while (pixels)
    {
        mlx_pixel_put(mlx, win, pixelX, pixelY, color);
        pixelX += deltaX;
        pixelY += deltaY;
        --pixels;
    }
    return(1);
}

int	main(void)
{
    t_game	game;
    int pixel_bits;
    int line_bytes;
    int endian;

    game.mlx = mlx_init();
    game.window = mlx_new_window(game.mlx,WINDOW_WIDTH, WINDOW_HEIGHT, "so_long");
    game.img_background = mlx_new_image(game.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
    int *buffer = (int *)mlx_get_data_addr(game.img_background, &pixel_bits, &line_bytes, &endian);
    line_bytes /= 4;
    int color = 0xABCDEF;

    for(int y = 0; y < WINDOW_HEIGHT; ++y)
        for(int x = 0; x < WINDOW_WIDTH; ++x)
        {
            buffer[(y * line_bytes) + x] = color;
        }
    mlx_put_image_to_window(game.mlx, game.window, game.img_background, 0 , 0);
    draw_line(game.mlx, game.window, WINDOW_WIDTH, WINDOW_HEIGHT, 0, 0, 0xFFFFFF);
    mlx_hook(game.window, 2, 1L<<0, close, &game);
    mlx_mouse_hook(game.window, &mouse_event, 0);
    mlx_loop(game.mlx);
}
