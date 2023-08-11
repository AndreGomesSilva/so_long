#include "../inc/so_long.h"

static void ft_error(void)
{
    fprintf(stderr, "%s", mlx_strerror(mlx_errno));
    exit(EXIT_FAILURE);
}

// Print the window width and height.
//static void ft_hook(void* param)
//{
//    const mlx_t* mlx = param;
//
//    printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
//}
//

void draw_background(t_game *game)
{
    int x;
    int y;

    y = 0;
    while(y <= WINDOW_HEIGHT / 16)
    {
        x = 0;
        while (x <= WINDOW_WIDTH / 16)
        {
            mlx_image_to_window(game->mlx, game->background_img, x*16, y*16);
//            if (game->map[y][x] == '1')
//                mlx_image_to_window(game->mlx, game->wall_img, x, y);
            x++;
        }
        y++;
    }
}

//void draw_map(t_game *game)
//{
//    int x;
//    int y;
//
//    y = 0;
//    while(y < 2)
//    {
//        x = 0;
//        while (x < 2)
//        {
//            if (game->map[y][x] == '0')
//                mlx_image_to_window(game->mlx, game->wall_img, 0, 0);
//            if (game->map[y][x] == '1')
//                mlx_image_to_window(game->mlx, game->background_img, 32, 32);
//            x++;
//        }
//        y++;
//    }
//}

char **get_map(char *str)
{
    char *line;
    int fd;
    char* all_lines;
    char **map;

    fd = open(str, O_RDONLY);
    if (fd < 0)
    {
        ft_error();
        return (0);
    }
   all_lines = ft_strdup("");
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        all_lines = ft_strjoin(all_lines, line);
        free(line);
    }
    map = ft_split(all_lines, '\n');
    free(all_lines);
    close(fd);
    return (map);
}

int map_construct(t_game *game)
{
    game->background_texture = mlx_load_png("../sprites/Grass.png");
    game->wall_texture = mlx_load_png("../sprites/Rock.png");
    game->background_img = mlx_texture_to_image(game->mlx, game->background_texture);
    game->wall_img = mlx_texture_to_image(game->mlx, game->wall_texture);
    return(1);
}

int32_t	game_init(char *str)
{
    t_game game;

    // MLX allows you to define its core behaviour before startup.
    game.mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "Teste", true);
    if (!game.mlx)
        ft_error();

    map_construct(&game);
    game.map = get_map(str);
    draw_background(&game);
//    draw_map(&game);
    // Register a hook and pass mlx as an optional param.
    // NOTE: Do this before calling mlx_loop!
    mlx_loop(game.mlx);
    mlx_delete_image(game.mlx, game.background_img);
    mlx_delete_image(game.mlx, game.wall_img);
    mlx_delete_texture(game.background_texture);
    mlx_delete_texture(game.wall_texture);
    mlx_terminate(game.mlx);
    return (EXIT_SUCCESS);
}
int32_t	main(int argc, char** argv)
{
    if (check_param(argc, argv))
    {
        game_init(*(argv + 1));

    }
}
