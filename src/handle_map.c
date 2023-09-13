//
// Created by Andre on 16/08/23.
//

#include "../inc/so_long.h"

int map_is_rectangle(t_game *game)
{
    int first_line;
    int y;
    int x;

    y = 0;
    first_line = (int)ft_strlen(*game->map);
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

int count_type(t_game *game, char type)
{
    int y;
    int x;
    int tiles_number;

    tiles_number = 0;
    y = 0;
    while (game->map[y])
    {
        x = 0;
        while (game->map[y][x])
        {
            if (game->map[y][x] == type)
            {
                tiles_number += 1;
                if (type == 'P')
                {
                    game->player_x = x;
                    game->player_y = y;
                }
            }
            x++;
        }
        y++;
    }
    return (tiles_number);
}

int valid_set_of_char(t_game *game)
{
   int  x;
   int  y;

   y = 0;
   while (game->map[y])
   {
       x = 0;
       while (game->map[y][x])
       {
           if (game->map[y][x] != '1' && game->map[y][x] != 'C' && game->map[y][x] != 'P' && game->map[y][x] != 'E')
           {
               if (game->map[y][x] != '0')
                   return (FALSE);
           }
           x++;
       }
       y++;
   }
    return (TRUE);
}

int right_tile_set(t_game *game)
{
    game->collectable_number = count_type(game, 'C');
    game->collectable_remain = game->collectable_number;
    if (!valid_set_of_char(game))
        return (FALSE);
    if (count_type(game, 'P') != 1 || count_type(game, 'E') != 1 || game->collectable_number < 1)
        return (FALSE);
    return(TRUE);
}

void free_map(char **map)
{
    int i;

    i = 0;
    while(map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}

char	*ft_join(char *s1, char *s2)
{
    size_t	s1_len;
    size_t	s2_len;
    char	*new_str;

    if (!s1 || !s2)
        return (NULL);
    s1_len = ft_strlen(s1);
    s2_len = ft_strlen(s2);
    new_str = (char *) malloc((s1_len + s2_len + 1) * sizeof(char));
    if (new_str != NULL)
    {
        ft_strlcpy(new_str, s1, s1_len + 1);
        ft_strlcat(new_str, s2, s1_len + s2_len + 1);
        free(s1);
        free(s2);
        return (new_str);
    }
    free(s1);
    free(s2);
    return (NULL);
}

char **get_map(char *str)
{
    char *line;
    int fd;
    char *all_lines;
    char **map;

    fd = open(str, O_RDONLY);
    if (fd < 0) {
        ft_error("Error\n - problem to read the map, verify if the path and the name is correct");
        return (NULL);
    }
    all_lines = (char *)ft_calloc(1, sizeof(char));
    while (TRUE) {
        line = get_next_line(fd);
        if (!line)
            break;
        all_lines = ft_join(all_lines, line);
    }
    map = ft_split(all_lines, '\n');
    free(all_lines);
    close(fd);
    return (map);
}