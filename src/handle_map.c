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
        return (FALSE);
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