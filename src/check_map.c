//
// Created by angomes- on 9/13/23.
//
#include	"../inc/so_long.h"

int	map_is_rectangle(t_game *game)
{
	int	first_line;
	int	y;
	int	x;

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

static int	count_type(t_game *game, char type)
{
	int	y;
	int	x;
	int	tiles_number;

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

static int	valid_set_of_char(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] != '1' && game->map[y][x] != 'C'
				&& game->map[y][x] != 'P' && game->map[y][x] != 'E')
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

int	right_tile_set(t_game *game)
{
	game->collectable_number = count_type(game, 'C');
	game->collectable_remain = game->collectable_number;
	if (!valid_set_of_char(game))
		return (FALSE);
	if (count_type(game, 'P') != 1 || count_type(game, 'E') != 1
		|| game->collectable_number < 1)
		return (FALSE);
	return (TRUE);
}
