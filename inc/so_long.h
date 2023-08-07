/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:16:03 by angomes-          #+#    #+#             */
/*   Updated: 2023/08/04 09:24:35 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600
# define MLX_ERROR 1

typedef struct s_game{
    void *mlx;
    void *window;
    char **map;
    void *img_wall;
    void *img_background;
    void *img_exit;
    void *img_player;
} t_game;

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>


#endif
