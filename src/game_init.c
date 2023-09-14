/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:34:58 by angomes-          #+#    #+#             */
/*   Updated: 2023/09/13 18:55:20 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static	int	map_to_window(t_window *window, t_game *game, char *str)
{
	if (map_is_rectangle(game) && right_tile_set(game))
	{
		get_size_window(game);
		validate_map(game, str);
		window->mlx = mlx_init(game->window_w, game->window_h, "So_long", true);
		if (!window->mlx)
			ft_error("Error\n - Fail to init the window\n");
		if (map_construct(window))
			draw_map(window, game);
		else
			ft_error("Error\n - Fail to construct the map\n");
		return (TRUE);
	}
	else
		return (FALSE);
}

int	game_init(char *str)
{
	t_game		game;
	t_window	window;

	ft_bzero(&game, sizeof(t_game));
	ft_bzero(&window, sizeof(t_window));
	window.game = &game;
	game.map = get_map(str);
	if (!map_to_window(&window, &game, str))
		ft_error("Error\n - The map must be rectangular have one player(P)" \
		"one exit(E) and at least one collectable(C)\n");
	mlx_loop_hook(window.mlx, &hook_close_window, &window);
	mlx_key_hook(window.mlx, &hook_player_movement, &window);
	mlx_loop(window.mlx);
	free_game(&window, &game);
	return (EXIT_SUCCESS);
}
