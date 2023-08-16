/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:33:42 by angomes-          #+#    #+#             */
/*   Updated: 2023/05/24 23:15:13 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
    char	*ptr;
    size_t	total_size;
    size_t	i;

    i = 0;
    total_size = nmemb * size;
    if (total_size != 0 && total_size / size != nmemb)
        return (NULL);
    ptr = (char *)malloc(total_size);
    if (!ptr)
        return (NULL);
    while (i < total_size)
    {
        ptr[i] = '\0';
        i++;
    }
    return ((void *)ptr);
}
