/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 20:30:33 by angomes-          #+#    #+#             */
/*   Updated: 2023/05/21 21:59:25 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*cpysrc;
	char	*cpydest;
	size_t	i;

	if (!dest && !src)
		return (NULL);
	cpysrc = (char *)src;
	cpydest = (char *)dest;
	i = 0;
	if (n == 0)
		return (dest);
	while (i < n)
	{
		*(cpydest + i) = *(cpysrc + i);
		i++;
	}
	return (dest);
}
