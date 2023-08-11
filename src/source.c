//
// Created by angomes- on 8/8/23.
//

#include "../inc/so_long.h"


int	close_win(t_game *vars)
{
    mlx_destroy_window(vars->mlx, vars->window);
    return (0);
}

int construct_map(t_game *game){
    game->img_background = mlx_xpm_file_to_image(game->mlx, "../sprites/Grass.xpm", &game->img_width, &game->img_height);
    game->img_wall = mlx_xpm_file_to_image(game->mlx, "../sprites/Rock.xpm", &game->img_width, &game->img_height);
    return (1);
}

char **get_map(char *str)
{
    char *line;
    int fd;
    char* all_lines;
    char **map;

    fd = open(str, O_RDONLY);
    if (fd < 0)
    {
        printf("erro to open file");
        return (0);
    }
    all_lines = ft_strdup("");
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        all_lines = ft_strjoin(all_lines, line) ;
        free(line);
    }
    map = ft_split(all_lines, '\n');
    free(all_lines);
    close(fd);
    return (map);
}

void draw_map(t_game *game)
{
    int x;
    int y;

    y = 0;
    while (y < WINDOW_HEIGHT)
    {
        x = 0;
        while(x < WINDOW_WIDTH)
        {
            if (game->map[x][y] == 0)
                mlx_put_image_to_window(game->mlx, game->window, game->img_background, x, y);
            if (game->map[x][y] == 1)
                mlx_put_image_to_window(game->mlx, game->window, game->img_wall, x, y);
            x++;
        }
        y++;
    }
}

int game_init(char *str)
{
    t_game game;
    printf("%s", str);

    game.mlx = mlx_init();
    game.window = mlx_new_window(game.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "so_long");
    construct_map(&game);
    game.map = get_map(str);
    draw_map(&game);
    mlx_hook(game.window, 2, 1L<<0, close_win, &game);
    mlx_loop(game.mlx);
//    mlx_destroy_image(game.mlx, game.map);
//    mlx_destroy_window(game.mlx, game.window);
//    mlx_destroy_display(game.mlx);
    free(game.mlx);
    return(1);
}
