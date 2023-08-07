/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:11:42 by angomes-          #+#    #+#             */
/*   Updated: 2023/05/08 22:26:14 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*chs;
	size_t	i;

	chs = (char *) s;
	i = 0;
	while (i < n)
	{
		*(chs + i) = c;
		i++;
	}
	return (s);
}
