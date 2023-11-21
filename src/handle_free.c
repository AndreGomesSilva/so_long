/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:13:20 by angomes-          #+#    #+#             */
/*   Updated: 2023/09/14 13:04:43 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static void	free_images(t_window *window)
{
	mlx_delete_image(window->mlx, window->background_img);
	mlx_delete_image(window->mlx, window->wall_img);
	mlx_delete_image(window->mlx, window->player_img);
	mlx_delete_image(window->mlx, window->exit_img);
	mlx_delete_image(window->mlx, window->collectable_img);
}

static void	free_textures(t_window *window)
{
	mlx_delete_texture(window->collectable_texture);
	mlx_delete_texture(window->background_texture);
	mlx_delete_texture(window->wall_texture);
	mlx_delete_texture(window->player_texture);
	mlx_delete_texture(window->exit_texture);
}

void	free_game(t_window *window, t_game *game)
{
	free_images(window);
	free_textures(window);
	mlx_close_window(window->mlx);
	free_map(game->map);
	mlx_terminate(window->mlx);
	exit(EXIT_OK);
}
