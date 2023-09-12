//
// Created by angomes on 9/12/23.
//

#include "../inc/so_long.h"

void	get_size_window(t_game *game)
{
    int	i;

    i = 0;
    game->map_row = (int)ft_strlen(*game->map);
    game->window_w = game->map_row * IMAGE_WIDTH;
    while (game->map[i])
        i++;
    game->map_col = i;
    game->window_h = game->map_col * IMAGE_HEIGHT;
}
