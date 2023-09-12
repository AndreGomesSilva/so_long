//
// Created by angomes- on 9/9/23.
//

#include "../inc/so_long.h"

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

int ft_flood_fill(t_game *game, char **map, int x, int y) {
    if (x < 0 || x > game->player_x || y < 0 || game->player_y || map[y][x] == '1')
        return 0;

    map[y][x] = '1';

    if (ft_flood_fill(game, map, x + 1, y)
        || ft_flood_fill(game, map, x - 1, y)
        || ft_flood_fill(game, map, x, y + 1)
        || ft_flood_fill(game, map, x, y - 1))
    {
        return (1);
    }

    print_matrix(map);
    return (0);
}

void    check_map(t_game *game, char *str)
{
    char **clone_map;

    clone_map = get_map(str);
    ft_flood_fill(game, clone_map, game->player_x, game->player_y);
}

