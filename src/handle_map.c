/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:57:27 by angomes-          #+#    #+#             */
/*   Updated: 2023/09/13 18:57:37 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	*ft_join(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new_str;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (new_str != NULL)
	{
		ft_strlcpy(new_str, s1, s1_len + 1);
		ft_strlcat(new_str, s2, s1_len + s2_len + 1);
		free(s1);
		free(s2);
		return (new_str);
	}
	free(s1);
	free(s2);
	return (NULL);
}

char	**get_map(char *str)
{
	char	*line;
	int		fd;
	char	*all_lines;
	char	**map;

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		ft_error("Error\n - problem to read the map verify if the path and the name is correct");
		return (NULL);
	}
	all_lines = (char *)ft_calloc(1, sizeof(char));
	while (TRUE)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		all_lines = ft_join(all_lines, line);
	}
	map = ft_split(all_lines, '\n');
	free(all_lines);
	close(fd);
	return (map);
}
