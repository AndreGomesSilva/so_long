/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_collectable.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:39:03 by angomes-          #+#    #+#             */
/*   Updated: 2023/09/14 13:04:45 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	collect(t_window *window, t_game *game)
{
	int	i;

	i = 0;
	while (i < game->collectable_remain)
	{
		if (window->collectable_img->instances[i].x
			/ IMAGE_WIDTH == game->player_x
			&& window->collectable_img->instances[i].y
			/ IMAGE_HEIGHT == game->player_y)
		{
			window->collectable_img->instances[i].enabled = 0;
			game->map[game->player_y][game->player_x] = '0';
			game->collectable_number -= 1;
		}
		i++;
	}
	return (TRUE);
}
