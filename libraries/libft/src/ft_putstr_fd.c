/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:30:53 by angomes-          #+#    #+#             */
/*   Updated: 2023/05/22 16:52:57 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	s_len;

	if (!s)
		return ;
	s_len = ft_strlen(s);
	write(fd, s, s_len);
}
