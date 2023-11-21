/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:58:40 by angomes-          #+#    #+#             */
/*   Updated: 2023/10/24 18:43:39 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_flood_fill(t_game *game, char **map, int x, int y)
{
	if (x < 0 || x >= game->map_row || y < 0 || y >= game->map_col
		|| map[y][x] == '1')
		return (FALSE);
	map[y][x] = '1';
	if (ft_flood_fill(game, map, x + 1, y) || ft_flood_fill(game, map, x - 1, y)
		|| ft_flood_fill(game, map, x, y + 1) || ft_flood_fill(game, map, x, y
			- 1))
	{
		return (TRUE);
	}
	return (EXIT_OK);
}

int	valid_route(char **cloned_map)
{
	int	y;
	int	x;

	y = 0;
	while (cloned_map[y])
	{
		x = 0;
		while (cloned_map[y][x])
		{
			if (cloned_map[y][x] != '1' && cloned_map[y][x] != '0')
				return (FALSE);
			x++;
		}
		y++;
	}
	return (TRUE);
}

int	valid_edges(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		if (game->map[y][x] != '1' || game->map[y][game->map_row - 1] != '1')
			return (FALSE);
		while (game->map[y][x])
		{
			if (game->map[0][x] != '1' || game->map[game->map_col
				- 1][x] != '1')
				return (FALSE);
			x++;
		}
		y++;
	}
	return (TRUE);
}

void	validate_map(t_game *game, char *str)
{
	game->cloned_map = get_map(str);
	ft_flood_fill(game, game->cloned_map, game->player_x, game->player_y);
	if (!valid_route(game->cloned_map) || !valid_edges(game))
	{
		free_map(game->cloned_map);
		ft_error("Error\n This map is invalid: it must be enclosed by walls"
					" and the player must be able to collect and exit \n");
	}
	else
		free_map(game->cloned_map);
}
