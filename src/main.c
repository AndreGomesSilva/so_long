/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:34:48 by angomes-          #+#    #+#             */
/*   Updated: 2023/09/14 13:04:36 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	if (check_args(argc, argv))
		game_init(*(argv + 1));
	else
		ft_error("Error\n Fail To init the game\n");
	return (EXIT_OK);
}
