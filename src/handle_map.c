//
// Created by Andre on 16/08/23.
//

#include "../inc/so_long.h"

//void cartesian_to_isometric_map(t_game *game)
//{
//    char    **isometric_map;
//    int32_t y;
//    int32_t x;
//    int32_t iso_x;
//    int32_t iso_y;
//
//    y = 0;
//    iso_x = 0;
//    iso_y = 0;
//    isometric_map = (char **)ft_calloc(game->map_col+ 1, sizeof(char));
//    while(game->map[y])
//    {
//        x = 0;
//        isometric_map[y] = (char*)ft_calloc(game->map_row + 1, sizeof(char));
//       while (game->map[y][x])
//       {
//          iso_x = (x - y);
//          iso_y = ((x + y) / 2);
//           if (iso_x >= 0 && iso_x < game->window_w / IMAGE_WIDTH && iso_y >= 0 && iso_y < game->window_h / IMAGE_HEIGHT)
//           {
//               isometric_map[iso_y][iso_x] = game->map[y][x];
//           }
//           x++;
//           iso_x++;
//       }
//       y++;
//       iso_y++;
//    }
//    game->iso_map = isometric_map;
//}

int32_t map_is_rectangle(t_game *game)
{
    int32_t first_line;
    int32_t y;
    int32_t x;

    y = 0;
    first_line = (int32_t)ft_strlen(*game->map);
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
    if (number_player != 1 || number_exit != 1)
        return (FALSE);
    return(TRUE);
}

void free_map(char **map)
{
    int32_t i;

    i = 0;
    while(map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
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
