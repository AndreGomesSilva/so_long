/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:57:44 by angomes-          #+#    #+#             */
/*   Updated: 2023/09/13 18:58:17 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
