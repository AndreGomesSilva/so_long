//
// Created by Andre on 16/08/23.
//

#include "../inc/so_long.h"

int32_t map_is_rectangle(t_game *game)
{
    int32_t first_line;
    int32_t y;
    int32_t x;

    y = 0;
    first_line = ft_strlen(*game->map);
    while (game->map[y])
    {
        x = 0;
        while (game->map[y][x])
            x++;
        if (first_line != x)
            return (FALSE);
        y++;
    }
    return (TRUE);
}

int32_t number_player_and_exit(t_game *game)
{
    int32_t y;
    int32_t x;
    int32_t number_player;
    int32_t number_exit;

    y = 0;
    number_player = 0;
    number_exit = 0;
    while (game->map[y])
    {
        x = 0;
        while (game->map[y][x])
        {
            if (game->map[y][x] == 'P')
                number_player += 1;
            if (game->map[y][x] == 'E')
                number_exit += 1;
            x++;
        }
        y++;
    }
    if (number_player + number_exit != 2)
        return (FALSE);
    return(TRUE);
}

void get_size_map(t_game *game)
{
    int32_t i;

    i = 0;
    game->map_w = ft_strlen(*game->map) * 32;
    while (game->map[i])
        i++;
    game->map_h = i * 32;
}

char **get_map(char *str)
{
    char *line;
    int fd;
    char *all_lines;
    char **map;

    fd = open(str, O_RDONLY);
    if (fd < 0) {
        return (FALSE);
    }
    all_lines = ft_strdup("");
    while (TRUE) {
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
